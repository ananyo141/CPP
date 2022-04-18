// Print the contents of a ':' delimited file (e.g: /etc/passwd)
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <fstream>

static inline void terminate(const std::string &msg) {
    /* A static (implementation) function that 
     * terminates with an error message */
    std::cerr << msg << std::endl;
    std::exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) 
        terminate(std::string("Usage: ") + *argv + " FILENAME");

    std::ifstream infile;
    const char *filename = argv[1];
    infile.open(filename);

    int count = 0;
    std::string readBuf;
    while (infile) {
        getline(infile, readBuf, ':');
        std::replace(readBuf.begin(), readBuf.end(), '\n', ' ');
        if (readBuf == "")
            readBuf = "[EMPTY]";
        std::cout << std::setw(4) << ++count << ": " << readBuf << '\n';
    }
    if (!count)
        std::cerr << "Unable to open file: '" << filename << "'\n";
    return 0;
}

