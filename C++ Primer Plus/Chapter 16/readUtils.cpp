// Files for explicit specialization specifications of
// readvalue template function

#include "readUtils.hpp"

namespace rd {
    template <>
    const std::string&  
    readvalue(std::string &hold, const std::string &prompt, bool exit) {
        std::cout << prompt;
        std::cin  >> std::ws;
        if (!getline(std::cin, hold) && std::cin.eof()) {
            std::cerr << "Unexpected EOF\n";
            if (exit)
                std::exit(EXIT_FAILURE);
        }
        return hold;
    }

    const char* readvalue(char hold[], unsigned lim, const std::string &prompt, bool exit) {
        std::cout << prompt;
        std::cin  >> std::ws;
        if (!std::cin.getline(hold, lim) && std::cin.eof()) {
            std::cerr << "Unexpected EOF\n";
            if (exit)
                std::exit(EXIT_FAILURE);
        }
        return hold;
    }
}

