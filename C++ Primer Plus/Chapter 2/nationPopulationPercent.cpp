// Calculate the percent of population of a given nation to world population
#include <iostream>

int main() {
    using namespace std;
    
    long long nationPop, worldPop;
    cout << "Enter the world's population: ";
    cin >> worldPop;
    cout << "Enter the population of your nation: ";
    cin >> nationPop;
    double percentPop = (nationPop / double(worldPop)) * 100;

    cout << "The population of your nation is " << percentPop << "% of the world population.\n";

    return 0;
}
