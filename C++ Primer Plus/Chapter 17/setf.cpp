/*
    Today's water temperature: +63
    For our programming friends, that's
    3f
    or
    0X3F
    How 0X1! oops -- How true!
*/

#include <iostream>

int main() {
    int temp = 63;
    std::cout.setf(std::ios_base::showpos);
    std::cout << "Today's water temperature: " << temp << '\n';
    std::cout << "For out programming friends, that's\n";
    std::hex(std::cout);
    std::cout << temp << "\nor\n";
    std::cout.setf(std::ios_base::showbase);
    std::cout.setf(std::ios_base::uppercase);
    std::cout << temp;
    std::cout << "\nHow " << true << "! oops -- How ";
    std::cout.setf(std::ios_base::boolalpha);
    std::cout << true << "!\n";

    return 0;
}

