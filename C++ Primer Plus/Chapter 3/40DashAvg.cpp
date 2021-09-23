/******************************************************************************************
10. Write a program that requests the user to enter three times for the 40-yd dash (or
40-meter, if you prefer) and then displays the times and the average. Use an array
object to hold the data. (Use a built-in array if array is not available.)
*******************************************************************************************/
#include <iostream>
#include <array>
const int DASHCOUNT = 3;

std::string digitSuffix(int number) {
    if ((number / 10) % 10 == 1) return "-th"; // if the ten's place is 1, return 'th'
    int digit = number % 10;
    switch(digit) {
        case 1:   return "-st"; 
        case 2:   return "-nd"; 
        case 3:   return "-rd"; 
        default:  return "-th"; 
    }
} 

int main() {
    using namespace std;
    array<double, DASHCOUNT> dashTimes;
    double maxTime, totalTime = 0;
    for (int i = 0; i < DASHCOUNT; i++) {        // input values
        cout << "Enter " << i+1 << digitSuffix(i+1) << " dash time: ";
        cin >> dashTimes[i];
        if (i == 0 || dashTimes[i] > maxTime)   // find max
            maxTime = dashTimes[i];
        totalTime += dashTimes[i];              // add time to total
    }
    
    // display max, total and average
    cout << "Max time taken out of " << DASHCOUNT << " dashes is "
         << maxTime << endl;
    cout << "Total time: " << totalTime << "\nAverage Time: "
         << totalTime / DASHCOUNT << endl;

    return 0;
}
