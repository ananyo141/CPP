#include <iostream>
#include <vector>
#include <algorithm>
#include "readUtils.hpp"
const int NUM = 5;

int main() {
    using book_t = std::pair<std::string, int>;
    std::vector<book_t> book_db(NUM, {"None", 0});

    std::cout << "You will do exactly as told. You will enter "
              << NUM << " book titles and your ratings (0-10).\n";

    std::string temp;
    for (int i = 0; i < NUM; i++) {
        rd::readvalue(book_db[i].first, "Enter title #" + std::to_string(i+1) + ": ");
        rd::readvalue(book_db[i].second, "Enter your rating (0-10): ");
    }
    std::cout << "\nThank you. You entered the following:\n";
    std::cout << "Rating\t Book\n";
    for (const auto &bookPair: book_db)
        std::cout << bookPair.second << "\t " << bookPair.first << '\n';

    return 0;
}

