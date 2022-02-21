// Client Code for Student Classes
// The formatting is approximate; not intended to be precise with 
// variable input

#include <iostream>
#include <iomanip>
#include "studcont.hpp"
#include "studinh.hpp"
const int NUM_STUD = 3;
const int NUM_QUIZ = 5;
const int FIELD_WID = 40;

int main() {
    int i, j;
    std::string name;
    stud::Student    databaseWithCont[NUM_STUD];
    studinh::Student databaseWithInh [NUM_STUD];
    // Get input
    for (i = 0; i < NUM_STUD; i++) {
        util::readVal(name, "Please enter student's name: ");
        databaseWithCont[i] = stud::Student(name, NUM_QUIZ);
        databaseWithInh [i] = studinh::Student(name, NUM_QUIZ);
        std::cout << "Please enter " << NUM_QUIZ << " quiz scores:\n";
        for (j = 0; j < NUM_QUIZ; j++) {
            util::readVal(databaseWithCont[i][j], "");
            databaseWithInh[i][j] = databaseWithCont[i][j];
        }
    }

    // Print Formatted output
    std::cout << std::left << std::setw(FIELD_WID) << "\nStudent List(Cont): " << "Stud List(Inh):\n";
    for (i = 0; i < NUM_STUD; i++) {
        std::cout << std::left << std::setw(FIELD_WID) << databaseWithCont[i].getName()
                  << databaseWithInh[i].getName() << '\n';
    }

    std::cout << std::left << std::setw(FIELD_WID) << "\nResults: " << "Results:\n";
    for (i = 0; i < NUM_STUD; i++) {
        std::cout << "Scores for: " << std::left << std::setw(FIELD_WID-13) << databaseWithCont[i].getName() 
                  << "Scores for: " << databaseWithInh[i].getName()  << '\n';
        for (j = 0; j < NUM_QUIZ; j++)
            std::cout << databaseWithCont[i][j] << (j < NUM_QUIZ-1 ? ", " : "");
        std::cout << std::left << std::setw(NUM_QUIZ*4+1) << "";
        for (j = 0; j < NUM_QUIZ; j++)
            std::cout << databaseWithInh[i][j] 
                      << (j < NUM_QUIZ-1 ? ", " : "\n");
        std::cout << "Average: " << std::left << std::setw(FIELD_WID-10) << databaseWithCont[i].average()
                  << "Average: " << databaseWithInh[i].average() << "\n\n";
    }

    // using inherited methods of private inheritance
    // Using size
    std::cout << "Size:\n";
    for (i = 0; i < NUM_STUD; i++)
        std::cout << databaseWithInh[i].size() << ", ";
    std::cout.put('\n');
    for (i = 0; i < NUM_STUD; i++)
        std::cout << "Max: "   << databaseWithInh[i].max()
                  << " Min: " << databaseWithInh[i].min() << '\n';

    return 0;
}

