/*************************************************************************************
5. The CandyBar structure contains three members.The first member holds the brand
name of a candy bar.The second member holds the weight (which may have a frac-
tional part) of the candy bar, and the third member holds the number of calories
(an integer value) in the candy bar.Write a program that declares such a structure
and creates a CandyBar variable called snack, initializing its members to "Mocha
Munch", 2.3, and 350, respectively.The initialization should be part of the declara-
tion for snack. Finally, the program should display the contents of the snack vari-
able.

6. The CandyBar structure contains three members, as described in Programming
Exercise 5.Write a program that creates an array of three CandyBar structures, ini-
tializes them to values of your choice, and then displays the contents of each struc-
ture.
**************************************************************************************/

#include <iostream>

struct CandyBar {
    std::string brand;
    float weight;
    unsigned cal;
};

int main() {
    using namespace std;

    CandyBar bars[] = {
        {"Mocha Munch",   2.3f, 350},
        {"Cadbury Munch", 1.5f, 440},
        {"Sneakers",      2.5f, 520},
        {"Kit Kat",       2.9f, 480}
    };

    for (int i = 0; i < sizeof (bars) / sizeof (bars[0]); i++) {
        cout << "Snack name: "       << bars[i].brand 
             << "\nSnack Weight: "   << bars[i].weight
             << "\nSnack Calories: " << bars[i].cal    << endl << endl;
    }

    return 0;
}
