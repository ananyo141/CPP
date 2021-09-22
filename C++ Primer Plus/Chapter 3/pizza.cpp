/*************************************************************************************** 
7. William Wingate runs a pizza-analysis service. For each pizza, he needs to record
the following information:
The name of the pizza company, which can consist of more than one word
The diameter of the pizza
The weight of the pizza

Devise a structure that can hold this information and write a program that uses a
structure variable of that type.The program should ask the user to enter each of the
preceding items of information, and then the program should display that informa-
tion. Use cin (or its methods) and cout.

8. Do Programming Exercise 7 but use new to allocate a structure instead of declaring
a structure variable.Also have the program request the pizza diameter before it
requests the pizza company name.
***************************************************************************************/
#include <iostream>

struct Pizza {
    std::string company;
    float diameter;
    float weight;
};

int main() {
    using namespace std;
    
    Pizza chickenFiesta;
    Pizza *pepperoni = new Pizza;

    cout << "Enter pizza diameter: ";
    cin >> chickenFiesta.diameter >> pepperoni->diameter;
    cin.get();
    cout << "Enter pizza  1 company name: ";
    getline(cin, chickenFiesta.company);
    cout << "Enter pizza  2 company name: ";
    getline(cin, pepperoni->company);
    cout << "Enter pizza weight: ";
    cin >> chickenFiesta.weight >> pepperoni->weight;

    cout << "\nPizza Company: "  << chickenFiesta.company  << ", " << pepperoni->company
         << "\nPizza diameter: " << chickenFiesta.diameter << ", " << pepperoni->diameter
         << "\nPizza weight: "   << chickenFiesta.weight   << ", " << pepperoni->weight   << endl;

    return 0;
}
