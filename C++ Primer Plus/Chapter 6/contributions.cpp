/*
6. Put together a program that keeps track of monetary contributions to the Society
for the Preservation of Rightful Influence. It should ask the user to enter the num-
ber of contributors and then solicit the user to enter the name and contribution of
each contributor.The information should be stored in a dynamically allocated array
of structures. Each structure should have two members: a character array (or else a
string object) to store the name and a double member to hold the amount of the
contribution.After reading all the data, the program should display the names and
amounts donated for all donors who contributed $10,000 or more.This list should
be headed by the label Grand Patrons.After that, the program should list the
remaining donors.That list should be headed Patrons. If there are no donors in one
of the categories, the program should print the word “none.”Aside from displaying
two categories, the program need do no sorting.
*/
#include <iostream>
const int GRAND_PATRON_DONATION_AMT = 10000;

struct Contributors {
    std::string name;
    double donation;
};

int main() {
    int numContributors;
    std::cout << "How many contributors are there? ";
    (std::cin  >> numContributors).get();
    Contributors *database = new Contributors[numContributors];

    for (int i = 0; i < numContributors; i++) {
        std::cout << "Enter " << i+1 << " donor name: ";
        getline(std::cin, database[i].name);
        std::cout << "Donation amount: ";
        (std::cin  >> database[i].donation).get(); 
    }
    bool found = false;
    std::cout << "\n\tGrand Patrons:\n";
    for (int i = 0; i < numContributors; i++) {
        if (database[i].donation >= GRAND_PATRON_DONATION_AMT) {
            std::cout << database[i].name << std::endl;
            found = true;
        }
    }
    if (!found) std::cout << "None\n";
    found = false;

    std::cout << "\n\tPatrons:\n";
    for (int i = 0; i < numContributors; i++) {
        if (database[i].donation < GRAND_PATRON_DONATION_AMT) {
            std::cout << database[i].name << std::endl;
            found = true;
        }
    }
    if (!found) std::cout << "None\n";

    return 0;
}
