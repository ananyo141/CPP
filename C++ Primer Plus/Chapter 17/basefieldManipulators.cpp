#include <iostream>
#include <iomanip>
#include <map>
const int FIELD_WIDTH = 5;

int main() {
    using manip_t = std::ios_base& (*) (std::ios_base&);

    std::cout << "Enter an integer: ";
    int num;
    std::cin >> num;
    std::map<std::string, manip_t> manips = { 
        {"Hexadecimal", std::hex},
        {"Decimal",     std::dec},
        {"Octal",       std::oct},
    };

    // display decimal, hex, octal and decimal
    std::cout << std::left << std::setw(FIELD_WIDTH) << "n" << " n * n\n";
    for (const auto &item: manips)
        std::cout << std::left << std::setw(FIELD_WIDTH) << item.second
                  << num << ' ' << std::setw(FIELD_WIDTH) 
                  << num * num << '(' << item.first << ")\n";
    std::dec(std::cout);
    std::cout << std::left;
    std::cout.width(FIELD_WIDTH);
    std::cout << num << ' ' << std::setw(FIELD_WIDTH) << num * num << "(Decimal)\n";

    return 0;
}

