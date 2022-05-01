
#include <iostream>
#include <sstream>
#include "../Chapter 16/readUtils.hpp"

int main() {
    std::string hdisk;
    std::ostringstream format;
    unsigned capacity;

    rd::readvalue(hdisk, "Enter the name of your hard disk: ");
    rd::readvalue(capacity, "Enter the capacity of harddisk: ");

    format << "The hard disk " << hdisk << " has a capacity of "
           << capacity << " gigabytes.\n";
    std::cout << format.str();

    return 0;
}
