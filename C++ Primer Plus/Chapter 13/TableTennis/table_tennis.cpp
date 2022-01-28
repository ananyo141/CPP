#include <iostream>
#include "table_tennis.hpp"

namespace tt {
    TableTennisPlayer::TableTennisPlayer(const std::string &fname, 
        const std::string &lname, bool htab)            // initialize strings 
            : firstname_(fname), lastname_(lname)   {   // in member init lists
        hasTable_  = htab;                              // for efficiency
    }

    RatedTTPlayer::RatedTTPlayer(const std::string &fname,
        const std::string &lname, bool htab, int rating)
            : TableTennisPlayer(fname, lname, htab) {   // parent init
        rating_ = rating;
    }

    RatedTTPlayer::RatedTTPlayer(int rating, const TableTennisPlayer &ttp)
            : TableTennisPlayer(ttp)                {   // invoke copy constructor
        rating_ = rating;
    }

    void hasTable(const TableTennisPlayer &player) {
        /* Display table information */
        std::cout << player.getName();
        if (player.getTable())
            std::cout << " has table";
        else
            std::cout << " hasn't table";
        std::cout.put('\n');
    }
}

