/*
1. Write a program that repeatedly asks the user to enter pairs of numbers until at

least one of the pair is 0. For each pair, the program should use a function to calcu-
late the harmonic mean of the numbers.The function should return the answer to

main(), which should report the result.The harmonic mean of the numbers is the
inverse of the average of the inverses and can be calculated as follows:
harmonic mean = 2.0 × x × y / (x + y)
*/

#include <iostream>

double harmonic(int x, int y);

int main() {
    int x, y;
    double result;
    std::cout << "Enter x, y: ";
    std::cout << std::fixed;
    std::cout.precision(2);
    while (std::cin >> x >> y) {
        result = harmonic(x, y);
        std::cout << "The harmonic mean of the number is " << result
                  << "\nNext two numbers (q to quit): ";
    }
    std::cin.clear();
    if (std::cin.get() == 'q') 
        std::cout << "Bye!";
    else std::cout << "Unknown input";
    std::cout << std::endl;

    return 0;
}

double harmonic(int x, int y) {
    return 2.0 * x * y / (x + y);
}
