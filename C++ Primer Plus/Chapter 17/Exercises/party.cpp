/*
5. Mat and Pat want to invite their friends to a party, much as they did in Program-
ming Exercise 8 in Chapter 16, except now they want a program that uses files.
They have asked you to write a program that does the following:

>> Reads a list of Mat’s friends’ names from a text file called mat.dat, which lists
one friend per line.The names are stored in a container and then displayed in
sorted order.

>> Reads a list of Pat’s friends’ names from a text file called pat.dat, which lists
one friend per line.The names are stored in a container and then displayed in
sorted order.

>> Merges the two lists, eliminating duplicates and stores the result in the file
matnpat.dat, one friend per line.
*/

/*
Change: Use terminate variadic template
Change: Use list (linked-list) container
*/

#include <iostream>
#include <set>
#include <fstream>
#include <list>
#include <iterator>
#include <algorithm>
#include "../terminate.hpp"

template <typename T>
void printContainer(T& items);

int main(int argc, char *argv[]) {
    using isItr = std::istream_iterator<std::string, char>;
    using listBackInsItr = std::back_insert_iterator<std::list<std::string>>;
    using ter::terminate;

    if (argc < 3 || argc > 4)
        terminate("Usage: ", *argv, " MATFILE PATFILE [OUTFILE]\n");
    const char *matfilename = argv[1];
    const char *patfilename = argv[2];
    const char *outfilename = (argc == 4) ? argv[3] : "partyguests.out";

    std::ifstream matfile(matfilename), patfile(patfilename);
    if (!matfile.is_open())
        terminate("Unable to open ", matfilename);
    if (!patfile.is_open())
        terminate("Unable to open ", patfilename);
    std::ofstream outfile(outfilename);
    if (!outfile.is_open())
        terminate("Unable to open", outfilename);

    // Redirect output to stdout to output file 
    // (like freopen() in C or redirection in shell)
    std::streambuf* cout_old = std::cout.rdbuf(outfile.rdbuf());

    std::list<std::string> matfriends;
    std::list<std::string> patfriends;

    std::copy(isItr (matfile), isItr (),
              listBackInsItr (matfriends));
    matfriends.sort();
    std::cout << "\nGot matfriends:\n";
    printContainer(matfriends);

    std::copy(isItr (patfile), isItr (),
              listBackInsItr (patfriends));
    patfriends.sort();
    std::cout << "\nGot patfriends:\n";
    printContainer(patfriends);

    matfriends.merge(patfriends);
    matfriends.unique();
    std::cout << "\nGuest List:\n";
    printContainer(matfriends);

    // Expliclity close all files
    matfile.close();
    patfile.close();
    outfile.close();
    // restore cout
    std::cout.rdbuf(cout_old);

    return 0;
}

template <typename T>
void printContainer(T& items) {
    /* Print the contents of the container */
    for (const auto &item: items)
        std::cout << item << '\n';
}
