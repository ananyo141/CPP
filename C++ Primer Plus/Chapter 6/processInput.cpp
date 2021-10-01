/* 
1. Write a program that reads keyboard input to the @ symbol and that echoes the
input except for digits, converting each uppercase character to lowercase, and vice
versa. (Don’t forget the cctype family.)
*/
#include <iostream>
#include <cctype>

int main() {
    char inCh, outCh;
    std::cout << "Enter your message: ";
    while(std::cin.get(inCh)) {
        if (inCh == '@')        break;
        else if (isdigit(inCh)) continue;
        else if (isupper(inCh)) outCh = tolower(inCh);
        else if (islower(inCh)) outCh = toupper(inCh);
        else outCh = inCh;

        std::cout << outCh;
    }
    std::cout << std::endl;

    return 0;
}
