// Test both wine containment and private inheritance
// Dependencies: Additionally compile with ---
// ../pairs.cpp ../StudentClass/studcont.cpp

#include <iostream>
#include "../StudentClass/studcont.hpp" 
#include "wineCont.hpp"
#include "wineInh.hpp"
const int LABSIZ = 50;
using util::readVal;
// typedef between wineCont and wineInh
//using WineClass = wineInh::Wine;
using WineClass = wineCont::Wine;


int main() {
    int years;
    std::string label;
    readVal(label, "Enter name of wine: ");
    readVal(years, "Enter number of years: ");
    WineClass firstHolding(label, years);
    firstHolding.getBottleStats();
    firstHolding.show();
    const int YRS = 3;
    int years_db[YRS] = {1993, 1995, 1998};
    int bottles[YRS] = {48, 60, 72};
    WineClass more("Gushing Grape Red", YRS, years_db, bottles);
    more.show();
    std::cout << "Total bottles for " << more.getLabel()
              << ": " << more.totalBottles() << '\n';
    std::cout << "Bye!\n";

    return 0;
}

