/* 8. Mat and Pat want to invite their friends to a party.They ask you to write a program
that does the following:
Allows Mat to enter a list of his friends’ names.The names are stored in a
container and then displayed in sorted order.
Allows Pat to enter a list of her friends’ names.The names are stored in a sec-
ond container and then displayed in sorted order.
Creates a third container that merges the two lists, eliminates duplicates, and
displays the contents of this container. */


#include <iostream>
#include <set>
#include <fstream>
#include <iterator>
#include <algorithm>

static void terminate(const std::string &msg) {
    std::cerr << msg << std::endl;
    std::exit(EXIT_FAILURE);
}

template <typename T>
void printSet(const std::set<T> & itemset);

int main(int argc, char *argv[]) {
    if (argc != 3)
        terminate(std::string("Usage: ") + *argv + " MATFILE PATFILE\n");
    const char *matfilename = argv[1];
    const char *patfilename = argv[2];
    std::ifstream matfile(matfilename), patfile(patfilename);
    if (!matfile)
        terminate(std::string("Unable to open ") + matfilename);
    if (!patfile)
        terminate(std::string("Unable to open ") + patfilename);

    std::set<std::string> matfriends;
    std::set<std::string> patfriends;

    std::copy(std::istream_iterator<std::string, char> (matfile),
            std::istream_iterator<std::string, char> (),
            std::insert_iterator<std::set<std::string>> (matfriends, matfriends.begin()));

    std::copy(std::istream_iterator<std::string, char> (patfile),
            std::istream_iterator<std::string, char> (),
            std::insert_iterator<std::set<std::string>> (patfriends, patfriends.begin()));

    std::cout << "\nGot matfriends:\n";
    printSet(matfriends);
    std::cout << "\nGot patfriends:\n";
    printSet(patfriends);

    std::set<std::string> guestList;
    std::set_union(matfriends.cbegin(), matfriends.cend(),
            patfriends.cbegin(), patfriends.cend(),
            std::insert_iterator<std::set<std::string>> (guestList, guestList.begin()));
    std::cout << "\nGuest List:\n";
    printSet(guestList);

    return 0;
}

template <typename T>
void printSet(const std::set<T> & itemset) {
    /* Print the contents of the set */
    for (const auto &item: itemset)
        std::cout << item << '\n';
}
