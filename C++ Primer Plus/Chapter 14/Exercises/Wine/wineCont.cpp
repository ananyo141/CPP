// Implementation file for wineCont.hpp

#include <iomanip>
#include "wineCont.hpp"

namespace wineCont {
    Wine::Wine(const std::string &label, int num_years) 
        : name_(label), numYears_(num_years), yearStats_(
                ValPair(ArrInt(num_years), ArrInt(num_years))
          ) { }

    Wine::Wine(const std::string &label, int num_years,
                const int years[], const int bot[])
        : name_(label), numYears_(num_years), yearStats_(
                ValPair(ArrInt(years, num_years), ArrInt(bot, num_years))
          ) { }

    void Wine::getBottleStats() {
        /* Given a wine object with numyears_ age, prompt the
         * user to get the stats for year and corresponding bottle count */
        int input;
        for (int i = 0; i < numYears_; i++) {
            readVal(yearStats_.first()[i], "Enter Year: ");
            readVal(yearStats_.second()[i], "Enter Bottle Count: ");
        }
    }

    void Wine::show() const {
        std::cout << "Wine (Containment): " << name_ << '\n';
        std::cout << std::right << std::setw(10) << "Year" << "   Bottles\n";
        for (int i = 0; i < numYears_; i++) {
            std::cout << std::right << std::setw(10) << yearStats_.first()[i] << ' '
                      << std::right << std::setw(7) << yearStats_.second()[i] 
                      << '\n';
        }
    }
}

