#include <iostream>
#include <fstream>
#include <filesystem>
#include "terminate.hpp"

int main() {
    char ch, filename[FILENAME_MAX];
    std::cout << "Enter filename: ";
    std::cin.getline(filename, FILENAME_MAX);
    if (filename[0] == '\0')
        ter::terminate("No filename provided");

    bool file_exists = std::filesystem::exists(filename);
    std::fstream file;
    file.open(filename, std::ios_base::in | std::ios_base::out | std::ios_base::app);

    // show file contents if exists
    if (file_exists) {
        std::cout << "Reading previous contents of file:\n";
        while (file.get(ch))
            std::cout << ch;
    }
    file.clear();
    file.seekp(0, std::ios_base::end);  // write pointer points to the end

    // append to file
    std::cout << "Enter contents to append:\n";
    while (std::cin.get(ch))            // reads until simulated eof
        file.put(ch);
    std::cin.clear();

    // show revised file contents
    file.seekg(0);
    while (file.get(ch))
        std::cout.put(ch);

    std::cout << "\nDone\n";
    return 0;
}

