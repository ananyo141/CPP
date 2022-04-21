// Use list remove method and general algorithm

#include <iostream>
#include <algorithm>
#include <list>

static inline void show(int x) { std::cout << x << ' '; }

int main() {
    std::initializer_list<int> init = {4, 5, 4, 2, 2, 3, 4, 8, 1, 4};
    std::list<int> list1(init);
    std::list<int> list2(init);

    std::cout << "Original list contents:\n";
    for_each(list1.cbegin(), list1.cend(), show);
    std::cout.put('\n');

    std::cout << "Using remove method:\n";
    list1.remove(4);
    for_each(list1.cbegin(), list1.cend(), show);
    std::cout.put('\n');

    std::cout << "Using remove function\n";
    std::list<int>::iterator newEnd = std::remove(list2.begin(), list2.end(), 4);

    std::cout << "After removing\n";
    for_each(list2.cbegin(), list2.cend(), show);
    std::cout.put('\n');

    list2.erase(newEnd, list2.end());
    std::cout << "After using erase\n";
    for_each(list1.cbegin(), list1.cend(), show);
    std::cout.put('\n');

    return 0;
}

