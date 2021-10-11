// Store and print expenses using string arrays
#include <iostream>
#include <array>
const int NUM_SEASONS = 4;
const std::array<std::string, NUM_SEASONS> SEASONS = {"Spring", "Summer", "Fall", "Winter"};

// prototypes //
void showExpenses(const std::array<double, NUM_SEASONS> expensesArr);
void fillExpenses(std::array<double, NUM_SEASONS> *expensesArrPtr);
double totalExpense(const std::array<double, NUM_SEASONS> expensesArr);

int main() {
    std::array<double, NUM_SEASONS> expenses;
    // input expenses
    fillExpenses(&expenses);
    // show expenses
    showExpenses(expenses);
    std::cout << "Total: $" << totalExpense(expenses) << std::endl;

    return 0;
}

void showExpenses(const std::array<double, NUM_SEASONS> expensesArr) {
    std::cout << "\nEXPENSES\n";
    for (int i = 0; i < NUM_SEASONS; i++) 
        std::cout << SEASONS[i] << ": $" << expensesArr[i] << std::endl;
}

void fillExpenses(std::array<double, NUM_SEASONS> *expensesArrPtr) {
    for (int i = 0; i < NUM_SEASONS; i++) {
        std::cout << "Enter " << SEASONS[i] << " expenses: $";
        while(!(std::cin >> (*expensesArrPtr)[i])) {
            std::cin.clear();
            while (std::cin.get() != '\n') ;
            std::cout << "Please enter numerical value: $";
        }       
    }
}

double totalExpense(const std::array<double, NUM_SEASONS> expensesArr) {
    double total = 0;
    for (int i = 0; i < NUM_SEASONS; i++)
        total += expensesArr[i];
    return total;
}
