/* 5. Write a template function max5() that takes as its argument an array of five items
of type T and returns the largest item in the array. (Because the size is fixed, it can
be hard-coded into the loop instead of being passed as an argument.) Test it in a
program that uses the function with an array of five int value and an array of five
double values. */

#include <iostream>
const int ARRSIZE = 10;

template<typename T>
T max5(T array[], unsigned limit = 5);

int main() {
    int array1[ARRSIZE] = {5, 8, 66, 4, -9, 5};
    double array2[ARRSIZE] = {5.5, 8.8, 66.66, 4.4, -9.9, 5.5, 99.99};
    int max1 = max5(array1, ARRSIZE);
    double max2 = max5(array2);
    std::cout << "max1 = " << max1
              << "\nmax2 = " << max2 << "\n";

    return 0;
}

template<typename T>
T max5(T array[], unsigned limit) {
    T greatest = array[0];
    for(unsigned i = 0; i < limit; i++)
        if (array[i] > greatest) greatest = array[i];
    return greatest;
}
