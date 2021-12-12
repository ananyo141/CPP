/* 5. Rewrite the Stonewt class (Listings 11.16 and 11.17) so that it has a state member
that governs whether the object is interpreted in stone form, integer pounds form,
or floating-point pounds form. Overload the << operator to replace the
show_stn() and show_lbs() methods. Overload the addition, subtraction, and
multiplication operators so that one can add, subtract, and multiply Stonewt values.
Test your class with a short program that uses all the class methods and friends. */

#include <iostream>
#include "stone.h"

int main() {
    using WEIGHT::Weight;
    Weight obj1(30),obj2(40),
           obj3(34), obj4(40);
    std::cout << "Obj1 + Obj2 = " << obj1 + obj2
              << "\nObj3 - Obj4 = " << obj3 - obj4
              << "\nObj3 = " << obj3
              << "\nObj3 * 4 = " << obj3 * 4 << '\n';

    obj3.resetMode(Weight::Mode::STONE);
    std::cout << "Obj3 = " << obj3
              << "\n";

    return 0;
}

