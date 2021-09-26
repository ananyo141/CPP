/*************************************************************************************
 * 9. Do Programming Exercise 6, but instead of declaring an array of three CandyBar *  
 * structures, use new to allocate the array dynamically.                             * 
 *                                                                                   * 
 *************************************************************************************/

#include <iostream>
const int ARRSIZE (4);

struct CandyBar {
    std::string brand;
    float weight;
    unsigned cal;
};

int main() {
    using namespace std;

    CandyBar *candies = new CandyBar[ARRSIZE];
    candies[0] = {"Mocha Munch",   2.3f, 350};
    candies[1] = {"Cadbury Munch", 1.5f, 440};
    candies[2] = {"Sneakers",      2.5f, 520};
    candies[3] = {"Kit Kat",       2.9f, 480};
    
    for (int i = 0; i < ARRSIZE; i++) {
        cout << "Snack name: "       << candies[i].brand 
             << "\nSnack Weight: "   << candies[i].weight
             << "\nSnack Calories: " << candies[i].cal    << endl << endl;
    }

    return 0;
}
