// Implementation file for studcont.hpp

#include <iostream>
#include "studcont.hpp"

namespace stud {
    void Student::_showScore(std::ostream &os) const {
        int i;
        for (i = 0; i < scores_.size(); i++) {
            os << scores_[i];
            os << ((i % 5 == 4) ? '\n' : ' ');  // for every 5 scores, print newline
        }
        if (i % 5 != 0) // skip final newline if just given 
            os.put('\n');
        if (i == 0)     // never increased
            os << "No Scores Provided\n";
    }

    std::ostream & operator<<(std::ostream &os, const Student &st) {
        os << "Student Name: " << st.name_ << '\n';
        st._showScore(os);
        return os;
    }

    std::istream & operator>>(std::istream &is, Student &st) {
        is >> st.name_;
        return is;
    }

    std::istream & getline(std::istream &is, Student &st) {
        std::getline(is, st.name_);
        return is;
    }
}

namespace util {
    template<>
    void readVal(std::string &val, const std::string &prompt) {
        std::cout << prompt;
        std::cin >> std::ws;
        getline(std::cin, val);
    }
}

