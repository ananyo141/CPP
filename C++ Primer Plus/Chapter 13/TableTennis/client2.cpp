#include <iostream>
#include "table_tennis.hpp"

int main() {
    tt::TableTennisPlayer player1("Tara", "Boomdea", false);
    tt::RatedTTPlayer player2("Mallory", "Duck", true, 1140);

    tt::hasTable(player1);
    tt::hasTable(player2);
    std::cout << player2.getName() << " has rating: "
              << player2.getRating() << '\n';
    tt::RatedTTPlayer player3(1212, player1);
    std::cout << player3.getName() << "; Rating: "
              << player3.getRating() << '\n';
    
    return 0;
}

