
#include <iostream>
#include <filesystem>
#include <algorithm>
#include <fstream>
#include "../../Chapter 16/readUtils.hpp"
#include "../terminate.hpp"
#include "record.hpp"
/*
   1. Displays the current contents of the planets.dat file.
   2. Asks which record you want to modify.
   3. Modifies that record.
   4. Shows the revised file.
   
   By using the techniques in this program, you can extend it so that it allows you to add
   new material and delete records.
   Also the example doesn’t bother to verify input, so you could add code to check for numeric input
   where appropriate.

   MENU loop 2 and 3
 */

int main(int argc, char *argv[]) {
    if (argc != 2)
        ter::terminate("Usage: ", *argv, "FILE");
    const char *filename = argv[1];
    bool exists = std::filesystem::exists(filename);

    rec::recdb records;
    rec::Record input;
    std::ifstream infile(filename);
    if (!infile.is_open())
        ter::terminate("Unable to open file", filename);

    if (exists) {
        // Read records in memory
        std::cout << "Here are the contents of " << filename << ":\n";
        while (infile.read(reinterpret_cast<char *> (&input), sizeof (rec::Record)) ) {
            std::cout << input;
            records.push_back(input);
        }
    } else {
        std::cout << filename << " doesn't exist. Creating file.\n";
    }

    int command, index;
    // Menu Loop
    for (;;) {
        std::cout << "1. Add Entry      2. Delete Entry\n"
                     "3. Modify Entry   4. Quit\n";
        rd::readvalue(command, "Command: ");
        if (command < 1 || command > 4) {
            std::cerr << "Invalid choice\n";
            continue;
        }
        switch (command) {
            case 1: std::cin >> input;
                    records.push_back(input);
                    break;
            case 2: rd::readvalue(index, "Delete position: ");
                    if (index < 0 || index >= records.size()) {
                        std::cerr << "Invalid position\n";
                        continue;
                    }
                    records.erase(records.begin() + index);
                    break;
            case 3: rd::readvalue(index, "Modify position: ");
                    if (index < 0 || index >= records.size()) {
                        std::cerr << "Invalid position\n";
                        continue;
                    }
                    std::cin >> input;
                    records[index].~Record();   // explicitly calling destructor
                    records[index] = input;
                    break;
            case 4: goto exitloop;

        }
        std::for_each(records.cbegin(), records.cend(), [] (const rec::Record &r) { std::cout << r; });
    }
    exitloop:
    infile.close();
    std::fstream outfile(filename, 
            std::ios_base::in | std::ios_base::out | std::ios_base::trunc | std::ios_base::binary);
    rec::PutRecords()(outfile, records);
    rec::GetRecords()(outfile);

    return 0;
}

