/**************************************************************************************
2. Redo Listing 5.4 using a type array object instead of a built-in array and type
long double instead of long long. Find the value of 100!
***************************************************************************************/
#include <iostream>
#include <iomanip>
#include <array>
const int FACTORIAL_UPTO    = 100;
const int FACTORIAL_ARRSIZE = FACTORIAL_UPTO + 1;

int main() {
    std::array<long double, FACTORIAL_ARRSIZE> factArr;
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(1);

    factArr[0] = 1.0;
    for (int i = 1; i < FACTORIAL_ARRSIZE; i++) 
        factArr[i] = i * factArr[i - 1];
    
    for (int i = 0; i < FACTORIAL_ARRSIZE; i++)
        std::cout << i << " ! = " << factArr[i] << std::endl;

    return 0;
}
