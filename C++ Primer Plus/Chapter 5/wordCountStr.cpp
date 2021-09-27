/**************************************************************************************
9. Write a program that matches the description of the program in Programming
Exercise 8, but use a string class object instead of an array. Include the string
header file and use a relational operator to make the comparison test.
**************************************************************************************/
#include <iostream>

int main() {
    int wordCount = 0;
    std::string word;
    std::cout << "Enter words (to stop, type the word done):\n";
    while(std::cin >> word) {
        if (word == "done") break;
        else wordCount++;
    }
    std::cout << "You entered a total of " << wordCount << " word(s) (excluding 'done')\n";

    return 0;
}
