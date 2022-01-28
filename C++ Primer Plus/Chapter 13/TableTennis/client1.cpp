#include <iostream>
#include "table_tennis.hpp"

int main() {
    tt::TableTennisPlayer player1("Chuck", "Blizzard", true),
        player2("Tara", "Boomdea");
    tt::hasTable(player1);
    tt::hasTable(player2);

    return 0;
}

