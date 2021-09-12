// Convert celcius to fahrenheit
#include <iostream>

// Calculate the temperature in celcius to fahrenheit
double celcius_to_fah(double celcius) {
    double fahrenheit = (9 * celcius / 5 ) + 32;
    return fahrenheit;
}

int main() {
    double celcius, fahrenheit;
    std::cout << "Enter the temperature in celcius: ";
    std::cin >> celcius;
    fahrenheit = celcius_to_fah(celcius);
    std::cout << "The equivalent temperature in fahrenheit is: "
              << fahrenheit << "F" << std::endl;

    return 0;
}
