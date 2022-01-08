#include <iostream>
#include "stringClass.h"
#define DEBUG(elem) std::cerr << __LINE__ << ": " \
                              << #elem " = " << elem << std::endl
#undef  DEBUG
#define DEBUG(elem)

int main() {
    Str::Str s1(" and I am a C++ student.");
    Str::Str s2("Please enter your name: ");
    Str::Str s3;
    std::cout << s2;
    std::cin  >> s3;
    DEBUG(s1);
    DEBUG(s2);
    DEBUG(s3);
    s2 = "My name is " + s3;
    DEBUG(s2);
    std::cout << s2 << ".\n";
    s2 = s2 + s1;
    s2 = s2.upper();
    DEBUG(s2);
    std::cout << "The string:\n" << s2 << "\ncontains " << s2.count('A')
              << " 'A' characters in it.\n";
    s1 = "red";
    Str::Str rgb[3] = { s1, "green", "blue" };
    std::cout << "Enter the name of a primary color for mixing light: ";
    Str::Str ans;
    bool success = false;
    while (std::cin >> ans) {
        ans = ans.lower();
        for (int i = 0; i < 3; i++) {
            if (ans == rgb[i]) {
                std::cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if (success) 
            break;
        else std::cout << "Try again!\n";
    }
    std::cout << "Bye\n";
    return 0;
}

