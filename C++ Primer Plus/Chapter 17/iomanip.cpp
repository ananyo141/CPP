
#include <iostream>
#include <iomanip>
#include <cmath>

int main() {
    double root;
    std::cout << std::right;
    std::cout << std::setw(10) << 'N' << ' ' << std::setw(15) 
              << "square root" << ' ' << std::setw(15) << "fourth root" 
              << '\n';
    for (int i = 10; i <= 100; i += 10) {
        root = std::sqrt(i);
        std::cout << std::setfill('.') << std::setw(10) << i
                  << std::setfill(' ') << std::setw(15) << std::fixed << std::setprecision(3) 
                  << root << std::setw(15) << std::setprecision(4) << std::sqrt(root) << '\n';
    }

    return 0;
}
