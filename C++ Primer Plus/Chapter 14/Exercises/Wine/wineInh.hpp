#ifndef WINE_INH_HPP_
#define WINE_INH_HPP_
#include <iostream>
#include <valarray>
#include "../pairs.hpp"

namespace wineInh {
    using ArrInt = std::valarray<int>;
    using ValPair = pairs::Pairs<ArrInt, ArrInt>;

    class Wine : private std::string, private ValPair {
        enum {DEFYEAR=5};
        int numYears_ = DEFYEAR;

    public:
        Wine() : std::string("None"), 
            ValPair(ArrInt(DEFYEAR), ArrInt(DEFYEAR)) { }
        virtual ~Wine() { }
        Wine(const std::string &label, int num_years=DEFYEAR);
        Wine(const std::string &label, int num_years,
                const int years[], const int bot[]);
        virtual void show() const;
        virtual void getBottleStats();
        virtual const std::string & getLabel() const { return (std::string &) *this; }
        int totalBottles() const { return ValPair::second().sum(); }
    };
}

#endif

