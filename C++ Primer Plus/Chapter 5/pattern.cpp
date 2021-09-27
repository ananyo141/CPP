/************************************************************************************
10. Write a program using nested loops that asks the user to enter a value for the
number of rows to display. It should then display that many rows of asterisks, with
one asterisk in the first row, two in the second row, and so on. For each row, the
asterisks are preceded by the number of periods needed to make all the rows
display a total number of characters equal to the number of rows.A sample run
would look like this:
Enter number of rows: 5
....*
...**
..***
.****
*****
**************************************************************************************/
#include <iostream>

int main() {
    int numRows;
    std::cout << "How many number of rows you want to see the pattern?: ";
    std::cin >> numRows;

    for (int i = 1; i <= numRows; i++) {
        // print the dots
        for (int j = 0; j < numRows - i; j++)
            std::cout << '.';
        // print the asterisks
        for (int j = 0; j < i; j++)
            std::cout << "*";
        std::cout << std::endl;
    }

    return 0;
}
