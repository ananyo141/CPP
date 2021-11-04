// Count the characters in a given line and keep track of the total characters
// entered in the session

#include <iostream>
#include <cctype>

void strcount(const std::string &line);

int main() {
    std::string line;
    for (;;) {
        std::cout << "Enter line(empty to quit): ";
        getline(std::cin, line);
        if (line == "") break;
        strcount(line);
    }
    std::cout << "Bye!\n";

    return 0;
}

void strcount(const std::string &line) {
    static unsigned total = 0;
    unsigned count = 0, i = 0;
    while (i < line.length())
        if (!isspace(line[i++])) count++;
    total += count;
    std::cout << "\"" << line << "\" contains "
              << count << " characters\n"
              << total << " characters total\n";
}

