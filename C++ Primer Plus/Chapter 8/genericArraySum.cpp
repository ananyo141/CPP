/* 7. Modify Listing 8.14 so that it uses two template functions called SumArray() to
return the sum of the array contents instead of displaying the contents.The pro-
gram now should report the total number of things and the sum of all the debts. */

#include <iostream>
#define ArrLen(array) (sizeof(array)/sizeof(array[0]))
const int ARRSIZE = 50;

struct Debts {
    char name[ARRSIZE];
    double amount;
};

// template prototypes //
template<typename T>
T SumArr(T array[], unsigned limit);
template<typename T>   // overloaded template
T SumArr(T *array[], unsigned limit);

int main() {
    int things[] = {13, 31, 103, 301, 310, 130};
    Debts mr_E[] = {
        {"Ima Wolfe", 2400.0},
        {"Ura Foxe",  1300.0},
        {"Iby Stout", 1800.0}
    };
    double *debtAmts[ArrLen(mr_E)];
    // create the array of double* containing addresses of amount members
    for (int i = 0; i < ArrLen(mr_E); i++)
        debtAmts[i] = &mr_E[i].amount;

    std::cout << "Total number of Mr.E's things: " << SumArr(things, ArrLen(things))
              << "\nTotal debt of Mr.E: " << SumArr(debtAmts, ArrLen(debtAmts)) << "\n";

    return 0;
}

// definitions //
template<typename T>
T SumArr(T array[], unsigned limit) {
    T sum = 0;
    while (limit--)
        sum += array[limit];
    return sum;
}

template<typename T>    // overloaded version of the template
T SumArr(T *array[], unsigned limit) {
    T sum = 0;
    while (limit--)
        sum += *array[limit];
    return sum;
}
