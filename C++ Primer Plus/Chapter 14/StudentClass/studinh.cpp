// Implementation file for student inheritance

#include "studinh.hpp"

namespace studinh {
    void Student::_showScore(std::ostream &os) const {
        for (const double &score: (ScoreDB &) *this)
            os << score << ' ';
        os.put('\n');
    }
    std::ostream & operator<<(std::ostream &os, const Student &st) {
        os << "Student Name: " << st.getName();
        st._showScore(os);
        return os;
    }
    std::istream & operator>>(std::istream &is, Student &st) {
        is >> (std::string &) st;
        return is;
    }
    std::istream & getline(std::istream &is, Student &st) {
        getline(is, (std::string &) st);
        return is;
    }
}

