// Get the chance of winning a lottery, where you get to pick six cards from a pack of 51 cards. 
// Use Combination formula: TotalCards (Combination) Chances

#include <iostream>

double findProbability(unsigned totalCards, unsigned chances);

int main() {
    char ch;
    unsigned totalCards, chances;
    std::cout << "Enter the total number of choices on the game card and the number of picks allowed: ";
    while (true) {
        while(!(std::cin >> totalCards >> chances)) {
            std::cin.clear();
            while (std::cin.get(ch)) {
                if (ch == '\n') break;
                else if (ch == 'q')  {
                    std::cout << "bye\n";
                    exit(EXIT_SUCCESS);
                }
            }
            std::cout << "Please enter integer values: ";
        }
        double probability = findProbability(totalCards, chances);
        std::cout << "You have one chance in " << probability << " of winning." << std::endl;
        std::cout << "Next two numbers (q to quit): ";
    }
    return 0;
}

double findProbability(unsigned totalCards, unsigned chances) {
    double probability = 1.0;
    while (chances > 0) 
        probability *= totalCards-- /(float) chances--;
    return probability;
}
