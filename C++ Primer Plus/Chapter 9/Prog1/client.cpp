/* Client file for the functions prototypes in header golf.h
A second file should contain main() and demonstrate all the features of the
prototyped functions. For example, a loop should solicit input for an array of golf
structures and terminate when the array is full or the user enters an empty string
for the golfer’s name.The main() function should use only the prototyped func-
tions to access the golf structures. */

#include <iostream>
#include "golf.h"
const int GOLFLIM = 5;

int main() {
    int len = 0;
    golf::golf golfArr[GOLFLIM];
    // populate golf structure array
    while (len < GOLFLIM && setgolf(golfArr[len])) 
        len++;
    std::cout << "\n";
    for (int i = 0; i < 15; i++) 
        std::cout << "*";
    while (len--) 
        golf::showgolf(golfArr[len]);

    return 0;
}

