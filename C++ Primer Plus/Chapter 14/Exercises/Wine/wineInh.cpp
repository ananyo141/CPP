// The inheritance version of wine class
#include <iomanip>
#include "../StudentClass/studcont.hpp"
#include "wineInh.hpp"

namespace wineInh {
    using util::readVal;
    Wine::Wine(const std::string &label, int num_years) 
        : std::string(label), numYears_(num_years), 
          ValPair(ArrInt(num_years), ArrInt(num_years)) { }

    Wine::Wine(const std::string &label, int num_years,
                const int years[], const int bot[])
        : std::string(label), numYears_(num_years), 
          ValPair(ArrInt(years, num_years), ArrInt(bot, num_years)) { }

    void Wine::getBottleStats() {
        /* Given a wine object with numyears_ age, prompt the
         * user to get the stats for year and corresponding bottle count */
        int input;
        for (int i = 0; i < numYears_; i++) {
            readVal(Pairs::first()[i], "Enter Year: ");
            readVal(Pairs::second()[i], "Enter Bottle Count: ");
        }
    }

    void Wine::show() const {
        std::cout << "Wine (Inheritance): " << (std::string &) *this << '\n';
        std::cout << std::right << std::setw(10) << "Year" << "   Bottles\n";
        for (int i = 0; i < numYears_; i++) {
            std::cout << std::right << std::setw(10) << Pairs::first()[i] << ' '
                      << std::right << std::setw(7) << Pairs::second()[i] 
                      << '\n';
        }
    }
}

