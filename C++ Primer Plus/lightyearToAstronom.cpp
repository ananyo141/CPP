// Convert lightyears to astronomical units
#include <iostream>

double light_to_astro(double lightyears) {
    double astronomical = 63240 * lightyears;
    return astronomical;
}

int main() {
    double lightyears, astronomical;
    std::cout << "Enter the distance in lightyears: ";
    std::cin >> lightyears;
    astronomical = light_to_astro(lightyears);
    std::cout << "The distance in astronomical units is: "
              << astronomical << " astronomical units" << std::endl;

    return 0;
}
