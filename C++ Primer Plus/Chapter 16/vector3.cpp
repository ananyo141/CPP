// Another variation of vector.cpp that uses sort, for_each, random_shuffle

#include <iostream>
#include <vector>
#include <algorithm>
#include <cctype>
#include "readUtils.hpp"

namespace {
    struct book_t {
        std::string name;
        int rating;
        void show() const {
            std::cout << rating << "\t " << name << '\n';
        }
    };

    using bookdb_t = std::vector<book_t>;
    int getBooks(bookdb_t &db);
    void showDb(const bookdb_t &db);
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
            [](const book_t &b1, const book_t &b2) {
                return b1.rating < b2.rating;
        });
    showDb(database);

    std::cout << "Sorted with rating, name if same\n";
    std::sort(database.begin(), database.end(),
            [](const book_t &b1, const book_t &b2) {
            // if ratings are same, compare by title
            return (b1.rating == b2.rating) 
                    ? b1.name < b2.name 
                    : b1.rating < b2.rating;
        });
    showDb(database);

    std::cout << "After shuffling:\n";
    std::random_shuffle(database.begin(), database.end());
    showDb(database);
    return 0;
}

namespace {
    int getBooks(bookdb_t &db) {
        /* Return a vector container of book_t structures
         * until the user enters 'quit' */
        int tempRating;
        std::string tempName;
        for (;;) {
            if (convertLower(rd::readvalue(tempName, "Enter book name: ")) == "quit")
                break;
            rd::readvalue(tempRating, "Enter rating: ");
            db.push_back(book_t{tempName, tempRating});
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
        for_each(db.begin(), db.end(), [](const book_t &b) 
                { b.show(); });
    }
}

