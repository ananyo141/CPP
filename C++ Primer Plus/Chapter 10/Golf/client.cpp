/* 3. Do Programming Exercise 1 from Chapter 9 but replace the code shown there with
an appropriate golf class declaration. Replace setgolf(golf &, const char*, int)
with a constructor with the appropriate argument for providing initial values.
Retain the interactive version of setgolf() but implement it by using the con-
structor. (For example, for the code for setgolf(), obtain the data, pass the data to
the constructor to create a temporary object, and assign the temporary object to the
invoking object, which is *this.) */


#include <iostream>
#include "golf.h"
const int GOLFLIM = 5;

int main() {
    int len = 0;
    glf::Golf golfArr[GOLFLIM];
    while (len < GOLFLIM && golfArr[len].setgolf())
        len++;
    for (int i = 0; i < 15; i++)
        std::cout << "*";
    std::cout << "\n\n";
    while (len--)
        golfArr[len].showgolf();

    return 0;
}

