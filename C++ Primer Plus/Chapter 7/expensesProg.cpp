/*
8. Redo Listing 7.15 without using the array class. Do two versions:
a. Use an ordinary array of const char * for the strings representing the sea-
son names, and use an ordinary array of double for the expenses.
b. Use an ordinary array of const char * for the strings representing the sea-
son names, and use a structure whose sole member is an ordinary array of
double for the expenses. (This design is similar to the basic design of the
array class.)
*/
#include <iostream>
const char *seasons[] = {
    "Spring", "Summer", "Fall", "Winter"
};
const int NUM_SEASONS = sizeof(seasons) / sizeof(seasons[0]);

struct Expenses {
    double list[NUM_SEASONS];
};

int main() {
    Expenses userExp;
    double total = 0;
    // input expenses
    for (int i = 0; i < NUM_SEASONS; i++) {
        std::cout << "Enter " << seasons[i] << " expenses: ";
        std::cin  >> userExp.list[i];
        total += userExp.list[i];
    }

    // output expenses
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < NUM_SEASONS; i++) 
        std::cout << seasons[i] << ": $" << userExp.list[i] << '\n';
    std::cout << "Total: $" << total << std::endl;

    return 0;
}
