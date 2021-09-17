/* 1. Write a short program that asks for your height in integer inches and then converts
your height to feet and inches. Have the program use the underscore character to

indicate where to type the response.Also use a const symbolic constant to repre-
sent the conversion factor. */
#include <iostream>
const int FEET_TO_INCH = 12;

int main() {
    using namespace std;

    unsigned short height;
    cout << "Enter your height in inches(int): ___\b\b\b";
    cin >> height;

    unsigned short feet = height / FEET_TO_INCH;
    unsigned short inches = height % FEET_TO_INCH; 

    cout << "Your height is " << feet << " feet(s)"
         << " and " << inches << " inch(es)" << endl; 

    return 0;
}
