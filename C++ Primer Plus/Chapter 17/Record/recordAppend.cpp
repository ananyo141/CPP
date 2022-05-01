
#include <iostream>
#include <fstream>
#include <filesystem>
#include <iomanip>
#include "record.hpp"
#include "../terminate.hpp"

int main() {
    std::string filename;
    std::cout << "Enter filename: ";
    std::cin  >> filename;  // single worded filename without whitespace
    if (filename.size() == 0)
        ter::terminate("Filename not given");

    bool file_exists = std::filesystem::exists(filename);
    std::fstream file(filename, 
            std::ios_base::in | std::ios_base::app | std::ios_base::binary);
    if (!file.is_open())
        ter::terminate("Unable to open file", filename);

    // Display file if already exists
    if (file_exists) {
        std::cout << "Here are the current contents of " << filename << '\n';
        rec::GetRecords()(file);
    }
    rec::Record record;
    rec::recdb records;
    // append to file interactively
    while (std::cin >> record)
        records.push_back(record);

    rec::PutRecords()(file, records);
    std::cout << "\nNew Contents\n";
    std::cin.clear();
    rec::GetRecords()(file);

    return 0;
}

