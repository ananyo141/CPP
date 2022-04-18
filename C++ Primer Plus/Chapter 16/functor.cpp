// Using functors

#include <iostream>
#include <algorithm>
#include <list>
#include <cmath>
#include <iterator>

// Predicate functor used to compare with a value given at
// construction time
template <typename T>
class Compare {
private:
    T compareWith_;
protected:
    const T &getComparisionVal() const { return compareWith_; }
public:
    Compare(const T &val): compareWith_(val) {}
    virtual ~Compare() {}
    virtual bool operator() (const T &val) = 0;
};

template <typename T>
class LessThan : public Compare<T> {
public:
    LessThan(const T &val) : Compare<T>(val) {}
    virtual bool operator() (const T &val) {
        return val < Compare<T>::getComparisionVal();
    }
};

template <typename T>
class GreaterThan: public Compare<T> {
public:
    GreaterThan(const T &val) : Compare<T>(val) {}
    virtual bool operator() (const T &val) {
        return val > Compare<T>::getComparisionVal();
    }
};

template <typename T>
static void showList (const std::list<T> &list) {
    for (const auto &item: list)
        std::cout << item << ' ';
    std::cout.put('\n');
}

int main() {
    std::initializer_list<int> init = {
        50, 100, 90, 180, 60, 210, 415, 88, 188, 201
    };

    std::list<int> l1(init);
    std::list<int> l2(init);

    LessThan<int> predicateL(200);

    showList(l1);
    showList(l2);

    l1.remove_if(predicateL);
    std::cout << "\nL1 after predicate:";
    showList(l1);

    l2.remove_if(GreaterThan<int> (100));
    std::cout << "L2 after predicate:";
    showList(l2);

    l2.remove_if([] (int v) { return v > 50; });
    std::cout << "L2 after lambda:";
    showList(l2);

    l1.erase(l1.begin(), l1.end());
    l1.insert(l1.begin(), init.begin(), init.end());

    std::cout << "Reset l1\n";
    std::cout << "SquareRoot list (Rounded Approx):\n";
    transform(l1.cbegin(), l1.cend(), std::ostream_iterator<int, char>
            (std::cout, " "), sqrt);

    transform(l1.cbegin(), l1.cend(), l2.cbegin(), l1.begin(), std::plus<int>() );
    std::cout << "\nL1 after summation with L2\n";
    showList(l1);

    return 0;
}

