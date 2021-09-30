// Recover from invalid input while reading golf scores of 5 rounds and find their average
#include <iostream>
const int ROUNDS = 5;

int main() {
    std::cout << "Please enter your golf scores.\n"
                 "You must enter " << ROUNDS << " rounds.\n";

    int score, total_score = 0;
    for (int i = 0; i < ROUNDS; i++) {
        std::cout << "Round #" << i + 1 << ": ";
        while (!(std::cin >> score))  {
            std::cin.clear();
            char ch;
            while (std::cin.get(ch)) 
                if (ch == ' ' || ch == '\n') break;
        }
        total_score += score;
    }
    std::cout << "The average is " << double(total_score) / ROUNDS << std::endl;

    return 0;
}
