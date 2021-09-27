/*************************************************************************************
7. Design a structure called car that holds the following information about an auto-
mobile: its make, as a string in a character array or in a string object, and the year
it was built, as an integer.Write a program that asks the user how many cars to cata-
log.The program should then use new to create a dynamic array of that many car
structures. Next, it should prompt the user to input the make (which might consist
of more than one word) and year information for each structure. Note that this
requires some care because it alternates reading strings with numeric data (see
Chapter 4). Finally, it should display the contents of each structure.A sample run
should look something like the following:
How many cars do you wish to catalog? 2
Car #1:
Please enter the make: Hudson Hornet
Please enter the year made: 1952
Car #2:
Please enter the make: Kaiser
Please enter the year made: 1951
Here is your collection:
1952 Hudson Hornet
1951 Kaiser
***************************************************************************************/
#include <iostream>
struct Car {
    std::string make;
    unsigned year;
};

int main() {
    unsigned numCars;
    std::cout << "How many cars you want to catalog? ";
    (std::cin >> numCars).get();

    Car *const carsArr = new Car[numCars];
    for (int i = 0; i < numCars; i++) {
        std::cout << "Car #" << i + 1 << "\nEnter the make: ";
        getline(std::cin, carsArr[i].make);
        std::cout << "Please enter the year made: ";
        (std::cin >> carsArr[i].year).get();
    }

    std::cout << "Here's your collection:\n";
    for (int i = 0; i < numCars; i++) {
        std::cout << carsArr[i].year << " "
                  << carsArr[i].make << std::endl;
    }

    return 0;
}
