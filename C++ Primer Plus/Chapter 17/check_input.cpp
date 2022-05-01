
#include <iostream>

int main() {
    int input, sum = 0;
    std::cout << "Enter numbers: ";
    while (std::cin >> input)
        sum += input;
    std::cout << "Last input entered: " << input  // input value lost
              << "\nSum = " << sum << '\n';
    return 0;
}
