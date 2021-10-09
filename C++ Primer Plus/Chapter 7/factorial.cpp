/*
5. Define a recursive function that takes an integer argument and returns the factorial
of that argument. Recall that 3 factorial, written 3!, equals 3 × 2!,and so on, with 0!
defined as 1. In general, if n is greater than zero, n! = n * (n - 1)!.Test your function
in a program that uses a loop to allow the user to enter various values for which the
program reports the factorial.
*/

#include <iostream>

double factorial(int num);

int main() {
    int num;
    for(;;) {
        std::cout << "\nFind Factorial of?: ";
        if (!(std::cin >> num)) break;
        std::cout << "The factorial of " << num << " is " << factorial(num) << std::endl;
    }
    return 0;
}

double factorial(int num) {
    // Return the factorial of the given number
    if (num <= 0) return 1;

    return num * factorial(num - 1);
}
