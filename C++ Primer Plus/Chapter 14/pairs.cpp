// A container class that holds two generic values

#include <iostream>
#include "pairs.hpp"

int main() {
    using pairs::Pairs;
    using rating_t = Pairs<std::string, int>;
    rating_t ratingDB[] = {
        rating_t("The Purpled Duck", 5),
        rating_t("Jaquie's Frisco Al Fresco", 4),
        rating_t("Cafe Souffle", 5),
        rating_t("Bertie's Eats", 3),
    };
    int num_cafe = sizeof(ratingDB) / sizeof(rating_t);
    std::cout << "Rating:\t Eatery\n";
    for (int i = 0; i < num_cafe; i++)
        std::cout << ratingDB[i].second() << ":\t "
                  << ratingDB[i].first () << '\n';
    std::cout << "Oops!, Revised Rating:\n";
    int lastCafe = num_cafe-1;
    ratingDB[lastCafe].first()  = "Bertie's Fab Eats";
    ratingDB[lastCafe].second() = 6;
    std::cout << ratingDB[lastCafe].second() << ":\t "
              << ratingDB[lastCafe].first() << '\n';
    return 0;
}

