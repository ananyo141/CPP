
#include <iostream>
#include <fstream>
#include "../terminate.hpp"

int main(int argc, char *argv[]) {
    if (argc != 3)
        ter::terminate("Usage:", *argv, "SOURCE", "DESTINATION");
    const char *filename1 = argv[1];
    const char *filename2 = argv[2];
    std::ifstream infile(filename1, std::ios_base::in | std::ios_base::binary);
    if (!infile.is_open())
        ter::terminate("Unable to open file:", filename1);
    std::ofstream outfile(filename2, std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
    if (!outfile.is_open())
        ter::terminate("Unable to open file:", filename2);

    char ch;
    while (infile.get(ch))
        outfile.put(ch);

    return 0;
}

