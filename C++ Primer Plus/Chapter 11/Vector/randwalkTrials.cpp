/*  Modify Listing 11.15 so that instead of reporting the results of a single trial for a
*   particular target/step combination, it reports the highest, lowest, and average num-
*   ber of steps for N trials, where N is an integer entered by the user.
*/

#include <iostream>
#include <cstdlib>      // rand(), srand() prototypes
#include <ctime>        // time() prototype
#include "vector.h"

// prototype //
template<typename T>
void getValue(T &var, const std::string &prompt);

int main() {
    using VECTOR::Vector;
    int trials;
    double target, dstep, randAng;
    unsigned long stepPerTrial, highest, 
                  lowest, totalSteps = 0;
    Vector netMovement, perStep;

    // get user input
    getValue(target, "Enter target distance: ");
    getValue(dstep,  "Enter step length: ");
    getValue(trials, "Enter number of trails: ");

    // repeat N number of trials
    for (int i = 0; i < trials; i++) {
        // Reset for every trial
        stepPerTrial = 0;
        netMovement.reset(0,0);
        while (netMovement.get_mag() < target) {
            randAng = rand() % 360;
            perStep.reset(dstep, randAng, Vector::POL);
            netMovement = netMovement + perStep;
            stepPerTrial++;
        }
        // set highest and lowest
        if (i == 0)
            highest = lowest = stepPerTrial;
        else {
            highest = stepPerTrial > highest ? stepPerTrial : highest;
            lowest  = stepPerTrial < lowest  ? stepPerTrial : lowest;
        }
        // set total
        totalSteps += stepPerTrial;
    }

    // Show Trial Results summary
    std::cout << "\n************* Results of Trials ****************"
              << "\nTrial Num:   "  << trials
              << "\nTarget Dist: "  << target
              << "\nStep Dist:   "  << dstep << '\n';
    std::cout << "\nHighest Steps: " << highest
              << "\nLowest  Steps: " << lowest
              << "\nAverage Steps: " << totalSteps / double(trials) 
              << '\n';

    return 0; 
}

template<typename T>
void getValue(T &var, const std::string &prompt) {
    for(;;) {
        std::cout << prompt;
        if (std::cin >> var) break;      // exit if read successful
        std::cin.clear();                // else clear input error
        while (std::cin.get() != '\n') ; // clear buffer upto newline
        std::cerr << "Expected (" << typeid(var).name() 
                  << ") input\n";        // print error and repeat
    }
}

