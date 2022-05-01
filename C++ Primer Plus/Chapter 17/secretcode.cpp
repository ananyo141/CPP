
#include <iostream>
#include <fstream>
#include "terminate.hpp"

int main() {
    double secret_num;
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin >> std::ws;
    getline(std::cin, filename);
    if (filename.size() == 0)
        ter::terminate("Invalid filename");

    std::fstream file;
    // open file stream in 'w+' mode
    file.open(filename.c_str(), std::ios_base::in | std::ios_base::out | std::ios_base::trunc);
    if (!file.is_open())
        ter::terminate("Unable to open file `", filename, '`');

    std::cout << "Enter your secret number: ";
    std::cin >> secret_num;

    file << "For your eyes only!\n"
         << "Your secret number is: " << secret_num << '\n';

    file.seekg(0, std::ios_base::beg);
    std::cout << "Here are the contents of file:\n";
    std::string line;
    line.reserve(110);

    while (getline(file, line))
        std::cout << line << '\n';
    file.close();

    return 0;
}
