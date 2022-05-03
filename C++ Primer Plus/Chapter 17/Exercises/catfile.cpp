
#include <iostream>
#include <fstream>
#include "../terminate.hpp"

int main(int argc, char *argv[]) {
    char ch;
    if (argc != 2)
        ter::terminate("Usage:", *argv, "FILE");
    std::cout << "Enter message: ";
    std::ofstream outfile(argv[1]);
    if (!outfile.is_open())
        ter::terminate("Unable to open file", argv[1]);
    while (std::cin.get(ch))
        outfile.put(ch);
    outfile.close();

    return 0;
}

