#include <iostream>
const int FIELD_WIDTH = 10;

int main() {
    std::cout.fill('-');
    int defWidth = std::cout.width();
    std::cout.put('\n') << "Default width: " << defWidth << '\n';
    std::cout.width(FIELD_WIDTH);
    std::cout << 'N' << ':';
    std::cout.width(FIELD_WIDTH);
    std::cout << "N * N" << ":\n";
    for (int i = 1; i <= 100; i *= 10) {
        std::cout.width(FIELD_WIDTH);
        std::cout << i << ":";
        std::cout.width(FIELD_WIDTH);
        std::cout << i * i << ":\n";
    }

    return 0;
}

