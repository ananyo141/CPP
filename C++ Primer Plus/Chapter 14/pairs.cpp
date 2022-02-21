// A container class that holds two generic values

#include <iostream>

namespace {
    template <typename T1, typename T2>
    class Pairs {
    private:
        T1 a_;
        T2 b_;
    public:
        Pairs(const T1 &first, const T2 &second);
        T1 & first();
        T2 & second();
    };

    template <typename T1, typename T2>
    Pairs<T1, T2>::Pairs(const T1 &first, const T2 &second)
        : a_(first), b_(second)  { }

    template <typename T1, typename T2>
    T1 & Pairs<T1, T2>::first () { return a_; }

    template <typename T1, typename T2>
    T2 & Pairs<T1, T2>::second() { return b_; }
}

int main() {
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

