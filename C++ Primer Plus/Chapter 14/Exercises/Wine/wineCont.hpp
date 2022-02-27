// ProgEx 1. -- Page 871

#ifndef WINE_CONT_HPP_
#define WINE_CONT_HPP_

#include <iostream>
#include <valarray>
#include "../pairs.hpp"
#include "../StudentClass/studcont.hpp" 

namespace wineCont {
    using util::readVal;

    class Wine {
    protected:
        using ArrInt  = std::valarray<int>;
        using ValPair = pairs::Pairs<ArrInt, ArrInt>;
    private:
        // Defaults
        enum {DEFYEAR = 5};
        std::string name_  = "None";
        int numYears_      = DEFYEAR;
        ValPair yearStats_ = ValPair(ArrInt(numYears_), ArrInt(numYears_));
    public:
        Wine()          { }     // let defaults take over
        virtual ~Wine() { }
        Wine(const std::string &label, int num_years=DEFYEAR);
        Wine(const std::string &label, int num_years,
                const int years[], const int bot[]);
        virtual void show() const;
        virtual void getBottleStats();
        virtual const std::string & getLabel() const { return name_; }
        int totalBottles() const { return yearStats_.second().sum(); }
    };
}

#endif

