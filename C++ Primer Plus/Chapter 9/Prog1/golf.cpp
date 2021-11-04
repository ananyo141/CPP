// Contains the definitions of functions prototyped in
// golf.h header file

#include <iostream>
#include <cstring>
#include "golf.h"

namespace golf {
    void setgolf(golf & g, const char * name, int hc) {
        strncpy(g.fullname, name, LEN-2);
        g.fullname[LEN-1] = '\0';
        g.handicap = hc;
    }

    int setgolf(golf & g) {
        std::cout << "Enter FullName: ";
        std::cin.getline(g.fullname, LEN);
        if (g.fullname[0] == '\0') return 0;
        std::cout << "Enter Handicap: ";
        while (!(std::cin >> g.handicap)) {
            std::cin.clear();
            while (std::cin.get() != '\n')
                ;
            std::cout << "Integer required: ";
        }
        std::cin.get();     // discard the newline in buffer
        return 1;
    }

    void handicap(golf & g, int hc) {
        g.handicap = hc;
    }

    void showgolf(const golf & g) {
        std::cout << "\nName: "     << g.fullname
                  << "\nHandicap: " << g.handicap
                  << "\n";
    }
}

