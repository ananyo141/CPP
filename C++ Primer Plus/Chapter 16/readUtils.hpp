#ifndef READUTILS_HPP_
#define READUTILS_HPP_

#include <iostream>
#define DEBUG(elem) std::cerr << #elem << " = " << elem << std::endl

namespace rd {
    // Read a generic value for which std::ifstream.operator>>() is
    // defined
    template <typename T>
    const T& readvalue(T &hold, const std::string &prompt="") {
        for (;;) {
            std::cout << prompt;
            if (!(std::cin >> hold)) {
                // if reason is end of file, terminate
                if (std::cin.eof()) {
                    std::cerr << "Unexpected EOF\n";
                    std::exit(EXIT_FAILURE);
                }
                std::cin.clear();
                // clear bad input
                while (std::cin.get() != '\n')
                    ;
                std::cerr << "Invalid Input\n";
            }
            else break;
        }
        // clear input buffer
        while (std::cin.get() != '\n')
            ;
        return hold;
    }

    // Specialization for std::string
    template <>
    const std::string& readvalue(std::string &hold, const std::string &prompt);
}

#endif

