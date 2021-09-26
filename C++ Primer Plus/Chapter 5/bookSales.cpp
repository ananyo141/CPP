/*************************************************************************************
5. You sell the book C++ for Fools.Write a program that has you enter a year’s worth
of monthly sales (in terms of number of books, not of money).The program should
use a loop to prompt you by month, using an array of char * (or an array of
string objects, if you prefer) initialized to the month strings and storing the input
data in an array of int.Then, the program should find the sum of the array con-
tents and report the total sales for the year.
***************************************************************************************/
#include <iostream>
#include <array>
#define ArrLen(arrname) sizeof(arrname) / sizeof(arrname[0])

const char *MONTHS[] = {
    "January", "February", "March", "April", "May", "June", "July",
    "August", "September", "October", "November", "December"
};

int main() {
    const int arrSize = ArrLen(MONTHS);
    std::array<int, arrSize> monthlySales;
    for (int i = 0; i < arrSize; i++) {
        std::cout << "Enter " << MONTHS[i] << " Sales: ";
        std::cin >> monthlySales[i];
    }
    int yearlySales = 0;
    for (int month : monthlySales) yearlySales += month;

    std::cout << "Yearly sale accounted to: " << yearlySales << std::endl;

    return 0;
}
