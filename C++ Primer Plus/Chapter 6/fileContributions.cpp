/* 9. Do Programming Exercise 6 but modify it to get information from a file.The first
item in the file should be the number of contributors, and the rest of the file should
consist of pairs of lines, with the first line of each pair being a contributor’s name
and the second line being a contribution.That is, the file should look like this:
4
Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000
*/
#include <iostream>
#include <fstream>
const int GRAND_PATRON_DONATION_AMT = 10000;

struct Contributors {
    std::string name;
    double donation;
};

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cout << "Usage <fileContributions> /path/to/file";
        exit(EXIT_FAILURE);
    }
    std::ifstream inFile;
    inFile.open(argv[1]);
    if (!inFile.is_open()) {
        std::cerr << "Unable to open file " << argv[1] << std::endl;
        exit(EXIT_FAILURE);
    }
    int numContributors;
    (inFile  >> numContributors).get();
    Contributors *database = new Contributors[numContributors];

    for (int i = 0; i < numContributors; i++) {
        getline(inFile, database[i].name);
        (inFile >> database[i].donation).get(); 
    }
    inFile.close();
    
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

