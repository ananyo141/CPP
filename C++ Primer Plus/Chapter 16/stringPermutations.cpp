// Find out all the permutations of the given string

#include <iostream>
#include <algorithm>
#include <string>

int main() {
    std::string input;
    for (;;) {
        std::cout << "Enter word to find permutations: ";
        if (!(std::cin >> input && input != "quit"))
            break;
        std::sort(input.begin(), input.end());
        do std::cout << input << '\n';
        while (std::next_permutation(input.begin(), input.end() ));
    }
    std::cout << "Done\n";

    return 0;
}

