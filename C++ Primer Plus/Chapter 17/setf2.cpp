
#include <iostream>
#include <cmath>

static void generateTable(const std::string &header) {
    std::cout << header << '\n';
    for (int i = 1; i <= 41; i += 10) {
        std::cout.width(4);
        std::cout << i << '|';
        std::cout.width(12);
        std::cout << std::sqrt(i) << " |\n";
    }
}

int main() {
    generateTable("Default Table");

    std::cout.precision(3);
    // std::cout << std::left;
    std::cout.setf(std::ios_base::left, std::ios_base::adjustfield);
    std::ios_base::fmtflags old = std::cout.setf(
            std::ios_base::scientific, std::ios_base::floatfield);
    std::cout.setf(std::ios_base::showpos);
    std::cout.setf(std::ios_base::showpoint);
    generateTable("Left justification with scientific notation");

    std::cout.setf(std::ios_base::internal, std::ios_base::adjustfield);
    std::cout.setf(old, std::ios_base::floatfield);
    // std::cout.unsetf(std::ios_base::showpoint);
    generateTable("Internal Justification old notation");

    std::cout.setf(std::ios_base::right, std::ios_base::adjustfield);
    std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
    generateTable("Right justification fixed notation");
    
    return 0;
}

