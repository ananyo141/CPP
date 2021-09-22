/*************************************************************************************
 * 9. Do Programming Exercise 6, but instead of declaring an array of three CandyBar *  
 * structures, use new to allocate the array dynamically.                             * 
 *                                                                                   * 
 *************************************************************************************/

#include <iostream>

struct CandyBar
{
    std::string brand;
    float weight;
    unsigned cal;
};

int main() {
    using namespace std;

    CandyBar *candies = new CandyBar[3];

    return 0;
}
