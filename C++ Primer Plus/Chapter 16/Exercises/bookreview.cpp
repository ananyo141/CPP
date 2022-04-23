// Another variation of vector.cpp that uses sort, for_each, random_shuffle

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>
#include <cctype>
#include "../readUtils.hpp"

namespace {
    struct book_t {
        std::string name;
        int rating;
        unsigned price;
        void show() const {
            std::cout << rating << "\t " << price << "\t " << name << '\n';
        }
    };

    using bookdb_t = std::vector<std::shared_ptr<book_t>>;
    int getBooks(bookdb_t &db);
    void showDb(const bookdb_t &db);
    template <typename Iterator>
    void showDb(const Iterator p1, const Iterator p2);
    std::string convertLower(const std::string &);
    std::string convertUpper(const std::string &);
}

int main() {
    bookdb_t database;
    getBooks(database);
    std::cout << "\nThank you. You entered " << database.size() << " ratings\n";
    showDb(database);
    std::cout << "Sorted with rating:\n";
    std::sort(database.begin(), database.end(), 
            [](const std::shared_ptr<book_t> b1, const std::shared_ptr<book_t> b2) {
                return b1->rating < b2->rating;
        });
    showDb(database);

    std::cout << "Sorted with rating, name if same\n";
    std::sort(database.begin(), database.end(),
            [](const std::shared_ptr<book_t> b1, const std::shared_ptr<book_t> b2) {
            // if ratings are same, compare by title
            return (b1->rating == b2->rating) 
                    ? b1->name < b2->name 
                    : b1->rating < b2->rating;
        });
    showDb(database);

    std::cout << "After shuffling:\n";
    std::random_shuffle(database.begin(), database.end());
    showDb(database);

    bookdb_t byTitle(database);
    bookdb_t byRating(database);
    bookdb_t byPrice(database);

    using bookptr = const std::shared_ptr<book_t>;
    std::sort(byTitle.begin(), byTitle.end(), [] (bookptr b1, bookptr b2) {
            return b1->name < b2->name;
        });
    std::sort(byRating.begin(), byRating.end(), [] (bookptr b1, bookptr b2) {
            return b1->rating < b2->rating;
        });
    std::sort(byPrice.begin(), byPrice.end(), [] (bookptr b1, bookptr b2) {
            return b1->price < b2->price;
        });

    int input;
    for (;;) {
        std::cout << 
            "Display in:\n"
            "1) Original order      2) Alphabetic\n"
            "3) Increasing Ratings  4) Decreasing Ratings\n"
            "5) Increasing Price    5) Decreasing Price\n"
            "7) Quit\n";
        rd::readvalue(input, "Command: ");
        switch (input) {
            case 1: showDb(database); break;
            case 2: showDb(byTitle); break;
            case 3: showDb(byRating); break;
            case 4: showDb(byRating.crbegin(), byRating.crend()); break;
            case 5: showDb(byPrice); break;
            case 6: showDb(byPrice.crbegin(), byPrice.crend()); break;
            case 7: goto exitloop; break;
        }
    }
    exitloop:
    std::cout << "Bye\n";

    return 0;
}

namespace {
    int getBooks(bookdb_t &db) {
        /* Return a vector container of book_t structures
         * until the user enters 'quit' */
        int tempRating;
        unsigned tempPrice;
        std::string tempName;
        for (;;) {
            if (convertLower(rd::readvalue(tempName, "Enter book name: ")) == "quit")
                break;
            rd::readvalue(tempRating, "Enter rating: ");
            rd::readvalue(tempPrice, "Enter Price: ");
            db.push_back(std::shared_ptr<book_t> (new book_t{tempName, tempRating, tempPrice}));
        }
        return db.size();
    }

    std::string convertLower(const std::string &str) {
        std::string temp;
        temp.reserve(str.size() + 1);
        for (const auto &ch: str)
            temp += tolower(ch);
        return temp;
    }

    std::string convertUpper(const std::string &str) {
        std::string temp;
        temp.reserve(str.size() + 1);
        for (const auto &ch: str)
            temp += std::toupper(ch);
        return temp;
    }

    void showDb(const bookdb_t &db) {
        std::cout << "Rating:\t Book:\n";
        for_each(db.begin(), db.end(), [](const std::shared_ptr<book_t> b) 
                { b->show(); });
    }

    template <typename Iterator>
    void showDb(const Iterator p1, const Iterator p2) {
        /* Overload to show the database with iterables */
        std::cout << "Rating:\t Book:\n";
        for_each(p1, p2, [](const std::shared_ptr<book_t> b) 
                { b->show(); });
    }
}

