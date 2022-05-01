
#include <iostream>

namespace {
    void eofterminate(std::istream &stream) {
        if (stream.eof()) {
            std::cerr << "EOF reached\n";
            std::exit(EXIT_FAILURE);
        }
    }

    void printNextChar(std::istream &stream) {
        std::cout << '\n' << static_cast<char> (std::cin.get()) << " is the next input character\n";
    }
}

int main() {
    char ch, delim = '#';
    while (std::cin.get(ch)) {
        if (ch == delim) {
            std::cin.putback(ch);
            break;
        }
        else std::cout << ch;
    }
    eofterminate(std::cin);
    printNextChar(std::cin);

    while (std::cin.peek() != '#') {
        std::cin.get(ch);
        std::cout << ch;
    }
    eofterminate(std::cin);
    printNextChar(std::cin);

    return 0;
}

