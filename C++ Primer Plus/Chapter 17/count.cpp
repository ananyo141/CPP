// Counting characters in a list of files

#include <iostream>
#include <fstream>
#include <iomanip>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << *argv << " FILE[S]";
        std::exit(EXIT_FAILURE);
    }

    unsigned long count, total = 0;
    std::ifstream infile;
    for (int i = 1; i < argc; i++) {
        infile.open(argv[i]);
        infile.clear();         // start with an open slate; required in some compilers
        if (!infile.is_open()) {
            std::cerr << "Unable to open file: " << argv[i] << '\n';
            continue;
        }
        count = 0;
        while (infile.get() != EOF)
            count++;
        total += count;
        std::cout << std::left << std::setw(30) << argv[i] << ": " << count << " characters\n";
        infile.close();
    }
    std::cout << "Total Characters: " << total << '\n';
    return 0;
}

