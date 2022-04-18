/*
 * Types of iterators:
 * Use:
 * Copy algorithm
 * ostream and istream adapters
 * reverse_iterator, back_insert_iterator, 
 * front_insert_iterator, insert_iterator
 */

#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>
const int SIZE = 10;

int main() {
    int arr[SIZE];
    std::vector<int> db;
    // get input from user using istream adapter and insert iterator
    std::cout << "Enter values:\n";
    std::istream_iterator<int, char> isItr(std::cin);
    std::back_insert_iterator<std::vector<int>> ipItr(db);

    // get inputs from input stream iterator
    std::copy(isItr,
            std::istream_iterator<int, char>(), // denotes read-failure
            ipItr);
    if (db.size() == 0) {
        std::cerr << "No values entered\n";
        std::exit(EXIT_FAILURE);
    }

    // initialize ostream_iterator
    std::ostream_iterator<int, char> osItr(std::cout, " ");
    std::copy(db.begin(), db.end(), osItr);
    std::cout.put('\n');
    // use reverse iterator
    std::vector<int>::reverse_iterator rIt;
    // for(rIt = db.rbegin(); rIt != db.rend(); rIt++)
    std::copy(db.rbegin(), db.rend(), osItr);
    std::cout.put('\n');

    // copy first SIZE elements of vector into array
    std::copy(db.begin(), db.begin() + SIZE, arr);
    std::for_each(arr, arr + SIZE, [&osItr](const int a) { *osItr++ = a; });
    std::cout.put('\n');

    return 0;
}

