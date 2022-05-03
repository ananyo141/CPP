
#include <iostream>

int main() {
    unsigned count = 0;
    char ch;
    std::cout << "Enter message: ";
    while (std::cin.get(ch)) {
        if (ch == '$') {
            std::cin.putback(ch);
            break;
        }
        count++;
    }
    if (!std::cin) {
        if (std::cin.eof())
            std::cerr << "Unexpected EOF";
        else if (std::cin.fail())
            std::cerr << "Read error";
        else        // badbit
            std::cerr << "Unrecognized error";
        std::cerr << '\n';
    }
    std::cout << "Read " << count << " characters.\n";
    std::cout << "Next on input queue: " << (char) std::cin.get() << '\n';

    return 0;
}

