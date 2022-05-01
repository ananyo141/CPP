// Use showpoint and precision method

#include <iostream>
#include <map>

static void printfriends(std::map<const char *, float> friends) {
    for (const auto &friendPair: friends) {
        std::cout << "\"" << friendPair.first << "\" is $" 
                  << friendPair.second << "!\n";
    }
}

int main() {
    std::cout.setf(std::ios_base::showpoint);
    std::map<const char *, float> friends = {
        {"Furry Friends", 20.40},
        {"Fiery Fiends",  1.9 + 8.0 / 9.0},
    };
    printfriends(friends);
    std::cout.precision(2);
    printfriends(friends);

    return 0;
}
