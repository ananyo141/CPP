/* 
2. Write a program that reads up to 10 donation values into an array of double. (Or, if
you prefer, use an array template object.) The program should terminate input on
non-numeric input. It should report the average of the numbers and also report
how many numbers in the array are larger than the average.
*/
#include <iostream>
#include <array>
const int ARRAYSIZE = 10;

int main() {
    std::array<double, ARRAYSIZE> donations;
    std::cout << "Enter donations: ";
    int numDonations;
    double average = 0;
    for (numDonations = 0; 
        std::cin >> donations[numDonations]; 
        numDonations++) 
        average += donations[numDonations];

    average /= numDonations;

    int moreThanAvg = 0;
    for (int i = 0; i < numDonations; i++)
        if (donations[i] > average)
            moreThanAvg++;

    std::cout << "Average: " << average
              << "\nDonations above Average: " << moreThanAvg 
              << std::endl;

    return 0;
}
