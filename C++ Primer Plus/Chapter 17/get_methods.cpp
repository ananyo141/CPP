
#include <iostream>
const int MAXREAD = 255;

int main() {
    char buff[MAXREAD];
    // get input
    std::cout << "Enter read for get upto '#':\n";
    std::cin.get(buff, MAXREAD, '#');

    std::cout << "Your input:\n" << buff << '\n';
    if (std::cin.get() != '\n')
        std::cin.ignore(MAXREAD, '\n');

    std::cout << "Enter getline:\n";
    std::cin.getline(buff, MAXREAD, '#');
    std::cout << "Your input:\n" << buff << '\n';
    std::cout << "Next character: " << static_cast<char>(std::cin.get()) << '\n';

    return 0;
}

