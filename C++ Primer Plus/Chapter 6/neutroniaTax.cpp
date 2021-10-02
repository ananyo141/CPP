/*
5. The Kingdom of Neutronia, where the unit of currency is the tvarp, has the fol-
lowing income tax code:
First 5,000 tvarps:  0% tax
Next 10,000 tvarps: 10% tax
Next 20,000 tvarps: 15% tax
Tvarps after 35,000:20% tax
For example, someone earning 38,000 tvarps would owe 5,000 × 0.00 + 10,000 ×
0.10 + 20,000 × 0.15 + 3,000 × 0.20, or 4,600 tvarps.Write a program that uses a
loop to solicit incomes and to report tax owed.The loop should terminate when
the user enters a negative number or non-numeric input.
*/
#include <iostream>
#define DEBUG(x) (std::cout << #x " = " << x << std::endl)

// prototype //
double taxOwed(double tvarps);

int main() {
    double income, tax;
    for (;;) {
        std::cout << "Enter your income in tvarps: ";
        std::cin  >> income;
        if (income < 0) break;
        tax = taxOwed(income);
        std::cout << "Your tax owed: " << tax << std::endl;
    }
    return 0;
}

double taxOwed(double tvarps) {
    bool finalAmount = false;
    double tax = 0;
    unsigned taxableLimit = 5000, increment = 5000, i = 1;
    float taxPercent = 0.0f;
    while (tvarps > 0) {
        if (tvarps > taxableLimit) {
            tax += taxableLimit * taxPercent;
            tvarps -= taxableLimit;
        } else {
            tax += tvarps * taxPercent;
            break;
        }

        /* this portion creates the series that sustain 
        both the taxPercent and taxIncrement logic */
        taxableLimit += increment * i++;
        if (!taxPercent) 
            taxPercent += 0.10f;
        else
            taxPercent += 0.05f;
    }
    return tax;
}
