#include <iostream>
#include <cstring>
#include "golf.h"

namespace glf {
    Golf::Golf() {
        fullname_[0] = '\0';
        handicap_ = -1;
    }
    Golf::Golf(const char *name, int hc) {
        strncpy(fullname_, name, LEN-1);
        fullname_[LEN-1] = '\0';
        handicap_ = hc;
    }
    int Golf::setgolf() {
        enum flags: short {FAILURE = 0, SUCCESS = 1};
       
        std::cout << "Enter name of golfer: ";
        char tempname[LEN];
        std::cin.getline(tempname, LEN);
        if (tempname[0] == '\0')
            return FAILURE;
        int handicap;
        std::cout << "Enter handicap: ";
        while (!(std::cin  >> handicap)) {
            std::cin.clear();
            while (std::cin.get() != '\n') continue;
            std::cout << "Enter integer: ";
        }
        std::cin.get();
        *this = Golf(tempname, handicap);
        return SUCCESS;
    }
    void Golf::handicap(int hc) {
        handicap_ = hc;
    }
    void Golf::showgolf() const {
        std::cout << "Name: " << fullname_
                  << "\nHC: " << handicap_
                  << '\n';
    }
}

