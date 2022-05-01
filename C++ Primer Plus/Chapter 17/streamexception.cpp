
#include <iostream>
#include <cctype>

int main() {
    int input, sum = 0;
    std::cout << "Enter numbers: ";
    // throw exception if failbit is triggered
    std::cin.exceptions(std::ios_base::failbit);  
    try {
        while (std::cin >> input)
            sum += input;
    } catch (std::ios_base::failure &exc) {
        std::cout << "Exception specification: " << exc.what() << '\n';
        std::cout << (std::cin.eof() ? "EOF" : "Failbit") << " encountered\n";
    }
    // clear
    std::cin.clear();
    while (!std::isspace(std::cin.get()))
        ;
    std::cout << "Last value entered: " << input 
              << "\nSum: " << sum << '\n';

    return 0;
}

