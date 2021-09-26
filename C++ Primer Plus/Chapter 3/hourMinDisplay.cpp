// Enter the hour and minutes and print time
#include <iostream>

void displayTime(unsigned hours, unsigned minutes) {
    std::cout << "Time: " << hours << ":" 
              << minutes << std::endl;
}

int main() {
    unsigned hours, minutes;

    std::cout << "Enter the number of hours: ";
    std::cin >> hours;
    std::cout << "Enter the number of minutes: ";
    std::cin >> minutes;

    displayTime(hours, minutes);

    return 0;
}
