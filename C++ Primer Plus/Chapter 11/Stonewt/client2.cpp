/* 6. Rewrite the Stonewt class (Listings 11.16 and 11.17) so that it overloads all six
relational operators.The operators should compare the pounds members and return
a type bool value.Write a program that declares an array of six Stonewt objects and
initializes the first three objects in the array declaration.Then it should use a loop
to read in values used to set the remaining three array elements.Then it should
report the smallest element, the largest element, and how many elements are greater
or equal to 11 stone. (The simplest approach is to create a Stonewt object initial-
ized to 11 stone and to compare the other objects with that object.) */

#include <iostream>
#include "stone.h"
const int ARRLEN = 6;
using WEIGHT::Weight;

int main() {
    Weight weightsArr[ARRLEN] = {
        Weight(10),
        Weight(20),
        Weight(30)
    };

    for (int i = 3; i < 6; i++) {
        for (;;) {
            std::cout << "Enter #" << i+1 << " val: ";
            if (std::cin >> weightsArr[i]) break;
            std::cin.clear();
            while (std::cin.get() != '\n') continue;
            std::cerr << "Expected (" << typeid(weightsArr[i]).name() 
                      << ") value\n";
        }
    }

    std::cout << "\nWeights:\n";
    Weight compare(11, Weight::Mode::STONE);
    for (int i = 0; i < ARRLEN; i++) {
        char ch = i < ARRLEN-1 ? ',' : ' ';
        std::cout << weightsArr[i] << ch << " ";
    }
    std::cout << "\n";

    unsigned num_greater = 0;
    Weight largest, smallest;
    largest = smallest = weightsArr[0];
    // Find smallest and largest
    for (Weight &obj: weightsArr) {
        obj.resetMode(Weight::Mode::STONE);
        if (obj > largest)  largest  = obj;
        if (obj < smallest) smallest = obj;
        if (obj >= compare) num_greater++;  // and greater than 11 stones
    }

    std::cout << "\nResults:\n";
    std::cout << "Largest: "    << largest
              << "\nSmallest: " << smallest
              << "\nNum greater than 11 stones: " << num_greater
              << "\n";

    return 0;
}

