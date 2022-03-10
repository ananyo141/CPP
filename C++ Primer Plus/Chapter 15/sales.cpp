// Implementation file for sales.hpp

#include <string>
#include "sales.hpp"

namespace Sales {
    // Sales Definitions
    Sales::Sales(int year): _year(year) {}

    Sales::Sales(int year, const double *grossArr, int n) : _year(year) {
        for (int i = 0; i < MONTHS; i++)
            _gross[i] = (i < n) ? grossArr[i] : 0;
    }

    Sales::bad_index::bad_index(int ind, const std::string &what_arg)
        : std::logic_error(what_arg), _badInd(ind) { }

    const char* Sales::bad_index::what() noexcept {
        _errmsg = "Error in index evaluation, out of bounds\nBad Index: " 
                  + std::to_string(_badInd) + std::logic_error::what();
        return _errmsg.c_str();
    }

    double & Sales::operator[](int i) {
        if (i < 0 || i >= MONTHS)
            throw bad_index(i);
        return _gross[i];
    }

    double Sales::operator[](int i) const {
        return operator[](i);
    }

    // LabeledSales Definitions
    LabeledSales::LabeledSales(const std::string &label, int y)
        : Sales(y), _label(label) { }

    LabeledSales::LabeledSales(const std::string &label, int y, 
            double *grossArr, int n) : Sales(y, grossArr, n), _label(label) { }

    double & LabeledSales::operator[](int i) {
        if (i < 0 || i >= MONTHS)
            throw lbad_index(get_label(), i);
        return Sales::operator[](i);
    }

    double LabeledSales::operator[](int i) const {
        return operator[](i);
    }
}

