// Implement bound non-template and template friends to a class template

#include <iostream>
#define printIt(elem) std::cout << #elem << " = " << elem << '\n'

// non-bound friend
void allcounts();
// bound template friends
template <typename T> void onecount();
template <typename T> void report(T &);

template <typename TT>
class TemplWithBoundFriends {
private:
    int privateMem_ = 5;
    static int staticMem_;
public:
    TemplWithBoundFriends()  { staticMem_++; }
    ~TemplWithBoundFriends() { staticMem_--; }
    // non-bound non-template friend
    friend void allcounts();
    // bound template friends
    friend void onecount<TT>();             // specializations of the base function templates
    friend void report<> (TemplWithBoundFriends<TT> &); // to make specialized friends
};

// Definitions
template <typename TT>
int TemplWithBoundFriends<TT>::staticMem_ = 0;

void allcounts() {
    /* While unbound friend is a friend to all specializations
     * of a class template, we have to explicitly define the type
     * of specialization */
    printIt(TemplWithBoundFriends<int>::staticMem_);
    printIt(TemplWithBoundFriends<double>::staticMem_);
}

template <typename T>
void onecount() {
    /* Template friend does away with knowing the exact class specialization
     * type; but becomes bound to that specialization only */
    printIt(TemplWithBoundFriends<T>::staticMem_);
}

template <typename T>
void report (T &templObj) {
    printIt(templObj.privateMem_);
}

// Explicit instantiations
template class TemplWithBoundFriends<int>;
template class TemplWithBoundFriends<double>;

int main() {
    TemplWithBoundFriends<int> IntTempl;
    allcounts();
    onecount<int>();
    report(IntTempl);
    return 0;
}

