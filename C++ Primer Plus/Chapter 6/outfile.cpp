// writing to a file
#include <iostream>
#include <fstream>

int main(int argc, char *argv[]) {
    if (argc < 2) { 
        std::cout << "Usage: <program> <filepath>" << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string make;
    unsigned short year;
    double asking_price, discount;

    std::ofstream outfile;
    outfile.open(argv[1]);
    if (!outfile.is_open()) {
        std::cerr << "Error opening file\n";
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter the make and model of automobile: ";
    getline(std::cin, make);
    std::cout << "Enter the model year: ";
    std::cin  >> year;
    std::cout << "Enter the asking price: ";
    std::cin  >> asking_price;
    std::cout << "Enter discount (%): ";
    std::cin  >> discount;
    discount /= 100;

    outfile << std::fixed;
    outfile.precision(2);
    outfile.setf(std::ios_base::showpoint);
    outfile << "Make and model: " << make << "\n";
    outfile << "Year: " << year << "\n";
    outfile << "Was asking Rs." << asking_price << "\n";
    outfile << "Now asking Rs." << asking_price * (1 - discount) << "\n";

    outfile.close();

    return 0;
}
