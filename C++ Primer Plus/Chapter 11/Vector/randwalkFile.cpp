/* 1. Modify Listing 11.15 so that it writes the successive locations of the random walker
into a file. Label each position with the step number.Also have the program write
the initial conditions (target distance and step size) and the summarized results to
the file. */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "vector.h"

// Function prototypes //
bool isnumber(const std::string str);
static void terminate(const std::string &msg);

// Usage: Target-Dist Step-Size Filename
int main(int argc, char *argv[]) {
    using VECTOR::Vector;
    if (argc != 4)
        terminate("\nUsage: Target-Dist Step-Size Filename");
    // Check args
    const char *targetStr = argv[1];
    const char *stepStr   = argv[2];
    const char *filename  = argv[3];
    if (!(isnumber(targetStr) && isnumber(stepStr)))
        terminate("Target and step-size should be valid positive integers");

    // Open and check the output file
    std::fstream outputFile;
    outputFile.open(filename, std::ios::app);
    if (!outputFile)
        terminate(std::string("Unable to open file '")
                  + filename + "' for writing");
    // Convert distance and step args
    int target = atoi(targetStr);
    int step   = atoi(stepStr);

    // seed random generator
    srand(time(0));
    // Write initial conditions to file
    outputFile << "Target Distance: " << target
               << ", Step Size: "     << step << "\n\n";

    // Generate Random Walker
    unsigned long totalSteps = 0;
    Vector netMovement(0,0);
    // Write output for every step taken
    while (netMovement.get_mag() < target) {
        outputFile << totalSteps << ":" << netMovement;
        netMovement = netMovement + Vector(step, rand() % 360, Vector::POL);
        totalSteps++;
    }

    // Write summarized results to file
    outputFile << "\n*************** Summary ********************\n";
    outputFile << "\nAfter " << totalSteps << " steps, the subject "
                  "has the following location:\n";
    outputFile << netMovement << "or\n";
    netMovement.polar_mode();
    outputFile << netMovement;

    outputFile << "Average outward distance per step: = "
               << netMovement.get_mag() / double(totalSteps)
               << "\n--------------------------------------------\n\n";
    // Close the file
    outputFile.close();
    std::cout << "Output successfully generated\n";

    return 0;
}

// Definitions //
bool isnumber(const std::string str) {
    /* Find if the given string is a
       number or not */
    for (const char &ch: str)
        if (!isdigit(ch)) return false;
    return true;
}

void terminate(const std::string &msg) {
    /* Terminate with error message to 
       stderr */
    std::cerr << msg << std::endl;
    exit(EXIT_FAILURE);
}

