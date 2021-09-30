// Read a text file containing numbers and report the sum and average
#include <iostream>
#include <fstream>

int main() {
    char filename[FILENAME_MAX];
    std::cout << "Enter name of data file: ";
    std::cin.getline(filename, FILENAME_MAX);

    std::ifstream infile;
    infile.open(filename); 
    if (!infile.is_open()) {
        std::cout << "Could not open file: " << filename << std::endl;
        exit(EXIT_FAILURE);
    }

    int count = 0; 
    double number, total = 0;
    while (infile >> number) {
        total += number;
        count++;
    } 

    if (infile.eof())       std::cout << "End of file reached\n";
    else if (infile.fail()) std::cerr << "Input terminated due to data mismatch\n";
    else                    std::cerr << "Unknown error\n";

    infile.close();

    if (count == 0) std::cout << "No data processed!";
    else {
        std::cout << "Items read: " << count
                  << "\nSum: "        << total
                  << "\nAverage: "  << total / count << std::endl;
    }


    return 0;
}
