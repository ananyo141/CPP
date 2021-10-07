// Make a countdown program using recursion
#include <iostream>

void recursiveCount(int n) {
    std::cout << "Counting down ... " << n << std::endl;
    if (n > 0)
        recursiveCount(n - 1);
    std::cout << n << ": Kaboom!\n";
}

int main() {
    std::cout << "Enter start: ";
    int countdown;
    std::cin >> countdown;
    recursiveCount(countdown);

    return 0;
}
