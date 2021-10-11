/*
10. Design a function calculate() that takes two type double values and a pointer to
a function that takes two double arguments and returns a double.The
calculate() function should also be type double, and it should return the value
that the pointed-to function calculates, using the double arguments to
calculate(). For example, suppose you have this definition for the add()
function:
double add(double x, double y)
{
    return x + y;
}
Then, the function call in the following would cause calculate() to pass the val-
ues 2.5 and 10.4 to the add() function and then return the add() return value
(12.9):
double q = calculate(2.5, 10.4, add);
Use these functions and at least one additional function in the add() mold in a
program.The program should use a loop that allows the user to enter pairs of num-
bers. For each pair, use calculate() to invoke add() and at least one other func-
tion. If you are feeling adventurous, try creating an array of pointers to add()-style
functions and use a loop to successively apply calculate() to a series of functions
by using these pointers. Hint: Here’s how to declare such an array of three pointers:
double (*pf[3])(double, double);
You can initialize such an array by using the usual array initialization syntax and
function names as addresses.
*/
#include <iostream>

// Prototypes //
double calculate(double x, double y, double (*func)(double, double));
double add      (double x, double y);
double subtract (double x, double y);
double multiply (double x, double y);
double divide   (double x, double y);

// array containing function pointers
double (*funcArr[]) (double, double) = {
    add, subtract, multiply, divide
};
const int NUM_FUNC = sizeof(funcArr) / sizeof(funcArr[0]);

int main() {
    double num1, num2;
    std::cout.precision(2);
    std::cout << "Enter x, y: ";
    while (std::cin >> num1 >> num2) {
        for (int i = 0; i < NUM_FUNC; i++)
            std::cout << calculate(num1, num2, funcArr[i]) << '\n';

        std::cout << "\nNext two numbers: ";
    }

    return 0;
}

// function definitions //
double calculate(double x, double y, double (*func)(double, double)) {
    return func(x, y);
}
double add     (double x, double y)    { std::cout << "Addition: ";       return x + y; }
double subtract(double x, double y)    { std::cout << "Subtraction: ";    return x - y; }
double multiply(double x, double y)    { std::cout << "Multiplication: "; return x * y; }
double divide  (double x, double y)    { std::cout << "Division: ";       return x / y; }
