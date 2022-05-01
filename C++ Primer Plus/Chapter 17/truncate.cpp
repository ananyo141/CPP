
#include <iostream>
const int MAXLEN = 10;

static inline void deleteline() { while (std::cin.get() != '\n') ; }

int main() {
    char name[MAXLEN];
    char title[MAXLEN];

    std::cout << "Enter you name: ";
    std::cin.get(name, MAXLEN);

    if (std::cin.peek() != '\n')
        std::cout << "We had to truncate your name\n";
    deleteline();

    std::cout << "Enter your title: ";
    std::cin.get(title, MAXLEN);

    if (std::cin.peek() != '\n')
        std::cout << "We had to truncate your title\n";
    deleteline();

    std::cout << "Name: " << name << "\nTitle: " << title << '\n';
    return 0;
}

