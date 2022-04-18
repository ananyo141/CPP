// A variation of vector1.cpp program that uses erase, insert, swap

#include <iostream>
#include <vector>
#include "readUtils.hpp"
const int NUM = 5;

// useful type aliases
using book_t   = std::pair<std::string, int>;
using bookdb_t = std::vector<book_t>;

// utility function
void show_bookdb(const bookdb_t & bookdb);

int main() {
    bookdb_t book_db1(NUM);

    for (auto &book: book_db1) {
        rd::readvalue(book.first,  "Enter book name: ");
        rd::readvalue(book.second, "Enter rating: ");
    }

    std::cout << "\nYou entered:\n";
    show_bookdb(book_db1);
    auto book_db2(book_db1); // using copy ctor

    auto book_itr = book_db1.begin();   // using newer auto deduction
    // bookdb_t::iterator begin = book_db1.begin();
    book_db1.erase(book_itr + 1, book_itr + 3); // second 2 elements
    std::cout << "After Erasure:\n";
    show_bookdb(book_db1);

    book_db1.insert(book_itr + 3, book_db2.begin(), book_db2.begin() + 2);
    std::cout << "After Insertion:\n";
    show_bookdb(book_db1);

    book_db1.swap(book_db2);
    std::cout << "After Swapping:\n";
    show_bookdb(book_db1);

    return 0;
}

void show_bookdb(const bookdb_t & bookdb) {
    std::cout << "Rating\t Book\n";
    for (const auto &book: bookdb)
        std::cout << book.second << "\t " 
                  << book.first  << '\n';
    std::cout.put('\n'); // Lazy newline
}

