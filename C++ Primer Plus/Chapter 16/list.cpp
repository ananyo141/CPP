// Use list template from STL

#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>

// Use preprocessor to get the raw variable names
#define ListShow(elem) { \
    std::cout << "Showing list: " << #elem << '\n'; \
    showList(elem); \
}

template <typename T>
void showList(const std::list<T> &ls);

int main() {
    int stuff1[] = {1, 2, 4, 8, 6};
    int stuff2[] = {6, 4, 2, 4, 2, 5};
    // deduce sizes
    int len1 = sizeof(stuff1) / sizeof(stuff1[0]);
    int len2 = sizeof(stuff2) / sizeof(stuff2[0]);

    // Create a list of 5 twos
    std::list<int> one(5, 2);
    ListShow(one);

    // create a second list with contents from stuff1
    std::list<int> two(stuff1, stuff1 + len1);
    ListShow(two);

    // create third list with contents from second list and stuff2 added to end
    std::list<int> three(two);
    three.insert(three.end(), stuff2, stuff2 + len2);
    ListShow(three);

    // Remove all instances of 2 from three
    three.remove(2);
    ListShow(three);

    // move one into first of three
    three.splice(three.begin(), one);
    ListShow(one);
    ListShow(three);

    // remove duplicate elements in three
    three.unique();
    ListShow(three);

    // sort and then remove duplicate in three
    three.sort();
    three.unique();
    ListShow(three);

    // sort merge two into three
    two.sort();
    three.merge(two);
    ListShow(two);
    ListShow(three);

    // remove duplicates
    two.swap(three);
    two.unique();
    ListShow(two);
    ListShow(three);

    return 0;
}

template <typename T>
void showList(const std::list<T> &ls) {
    if (ls.size() == 0)
        std::cout << "[EMPTY]";
    for (const auto &item: ls)
        std::cout << item << ' ';
    std::cout << "\n\n";
}

