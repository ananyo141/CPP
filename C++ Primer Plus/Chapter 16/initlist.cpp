// Use initializer_list

#include <iostream>
#include <initializer_list>
#include <iomanip>

namespace {
    int totalLists = 0; // global scope

    template <typename T>
    double list_sum(std::initializer_list<T>);
    template <typename T>
    double list_average(std::initializer_list<T>);

    template <typename T>
    void print_list(std::initializer_list<T>);
}

int main() {
    print_list({2, 3, 4});
    std::initializer_list<double> dl = {1.1, 2.2, 3.3, 4.4, 5.5};
    print_list(dl);
    dl = {16.0, 25.0, 36.0, 40.0, 64.0};
    print_list(dl);

    return 0;
}

namespace {
    template <typename T>
    double list_sum(std::initializer_list<T> list) {
        double total = 0;
        for (const auto &x: list)
            total += x;
        return total;
    }

    template <typename T>
    double list_average(std::initializer_list<T> list) {
        typename std::initializer_list<T>::iterator pItr;
        double total = 0;
        for (pItr = list.begin(); pItr != list.end(); ++pItr)
            total += *pItr;
        return total / list.size();
    }

    template <typename T>
    void print_list(std::initializer_list<T> list) {
        // if static variable totalLists created here, a separate
        // variable is created for every specialization of the function
        std::cout << "List " << ++totalLists << ": Sum = " << std::setw(5) << std::left
                  << list_sum(list) << " Average = " << list_average(list) << '\n';
    }
}

