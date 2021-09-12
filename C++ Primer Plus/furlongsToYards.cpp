// Convert furlongs to yards (1 furlong = 220 yards)
#include <iostream>

int main() {
    double numFurlongs;
    std::cout << "Enter number of furlongs: ";
    std::cin >> numFurlongs;
    std::cout << "Equivalent yards is: " << numFurlongs * 220 
              << " yards" << std::endl;

    return 0;
}
