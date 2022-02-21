// Implement unbounded template friend to a template class

#include <iostream>
#define printIt(elem) std::cout << #elem << " = " << elem << '\n'

template <typename T>
class TemplUnboundedFriend {
private:
    T value_ = 9.99;
public:
    template <typename A, typename B>
    void friend unboundedFriend(A &a1, B &b2);
};

int main() {
    TemplUnboundedFriend<int> intSp;
    TemplUnboundedFriend<double> doubleSp;
    unboundedFriend(intSp, doubleSp);

    return 0;
}

template <typename A, typename B>
void unboundedFriend(A &a1, B &a2) {
    /* Friend to all specializations of 
       template class */
    printIt(a1.value_);
    printIt(a2.value_);
}

