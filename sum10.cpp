// Find the sum of digits from 1 to 10
#include <iostream>

int main() {
    int sum = 0;
    std::cout << "Finding the sum of digits from 1 to 10 (inclusive)" << std::endl;
    for (int i = 1; i <= 10; i++)
        sum += i;

    std::cout << "The result is " << sum << std::endl;

    return 0;
}
