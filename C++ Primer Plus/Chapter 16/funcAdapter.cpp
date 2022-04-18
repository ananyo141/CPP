// Use function adapter classes and binder functions

#include <iostream>
#include <vector>
#include <algorithm>

#define PVECTOR(v) { \
    std::cout << #v << ":\t "; \
    printVector(v); \
}

template <typename T>
static void printVector (const std::vector<T> &v) {
    // for (const auto &item: v)
    //     std::cout << v << ' ';
    for_each(v.cbegin(), v.cend(), [] (const T &item) {
            std::cout << item << '\t'; 
        });
    std::cout.put('\n');
}

int main() {
    double arr1[] = { 28, 29, 30, 35, 38, 59 };
    double arr2[] = { 63, 65, 69, 75, 80, 99 };

    std::vector<double> v1, v2(arr2, arr2 + (sizeof(arr2) / sizeof(arr2[0])) );
    v1.insert(v1.begin(), arr1, arr1 + (sizeof(arr1) / sizeof(arr1[0]) ));
    std::cout.setf(std::ios_base::fixed);
    std::cout.precision(2);

    PVECTOR(v1);
    PVECTOR(v2);

    std::vector<double> sum;
    transform(v1.cbegin(), v1.cend(), v2.cbegin(), 
            std::back_insert_iterator<std::vector<double>> (sum),
            std::plus<double>() );
    PVECTOR(sum);

    transform(v2.cbegin(), v2.cend(), 
            v2.begin(),
            std::bind1st(std::multiplies<double>(), 2.5) );

    std::cout << "After multiplying with 2.5\n";
    PVECTOR(v2);

    return 0;
}

