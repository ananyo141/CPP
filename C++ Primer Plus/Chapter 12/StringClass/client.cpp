#include <iostream>
#include "stringClass.h"
#define DEBUG(elem) std::cerr << #elem " = " << elem << std::endl
const int ARRSIZE = 10;


int main() {
    // Get user name
    Str::Str name;
    std::cout << "Hi Sir, what's your name?: ";
    std::cin  >> name;
    int total = 0;
    Str::Str sayings[ARRSIZE];
    std::cout << name << ", please enter up to " << ARRSIZE 
              << " sayings <empty line to quit>\n";
    // Get Sayings, empty string to break
    while (total < ARRSIZE) {
        std::cout << "#" << total + 1 << ": ";
        std::cin  >> sayings[total];
        if (!std::cin || !sayings[total]) break;
        ++total;
    }

    Str::Str *shortest, *first;
    shortest = first = sayings; // first element
    // Display the sayings and Set the pointers to the shortest
    // saying and alphabetically first string
    DEBUG(total);
    for (int i = 0; i < total; i++) {
        std::cout << sayings[i][0] << ": " << sayings[i] << '\n';
        if (sayings[i].len() < shortest->len())
            shortest = sayings + i;
        if (sayings[i] < *first)
            first = sayings + i;
    }
    // Display results and how many strings were constructed
    std::cout << "\nShortest:\n" << *shortest
              << "\nAlphabetically first:\t" << *first
              << "\nStrings Constructed:\t"  << Str::Str::totalStr()
              << '\n';
    return 0;
}

