/*
2. Write a program that asks the user to enter up to 10 golf scores, which are to be
stored in an array.You should provide a means for the user to terminate input prior
to entering 10 scores.The program should display all the scores on one line and
report the average score. Handle input, display,and the average calculation with
three separate array-processing functions.
*/

#include <iostream>
const int SCORE_LIM = 10;

// prototypes //
int getScores(int scoreArray[], int size);
void showScores(int scoreArray[], int size);
double averageScore(int scoreArray[], int size);

int main() {
    int scores[SCORE_LIM];
    int num_scores = getScores(scores, SCORE_LIM);
    showScores(scores, num_scores);
    std::cout << "Average: " << averageScore(scores, num_scores) << std::endl;

    return 0;
}

int getScores(int scoreArray[], int size) {
    int i = 0;
    std::cout << "Enter scores\n(non-numerical value stops input): ";
    for (i = 0; i < SCORE_LIM; i++) {
        std::cin >> scoreArray[i];
        if (!std::cin) {
            std::cin.clear();
            return i;
        }
    }
}

void showScores(int scoreArray[], int size) {
    std::cout << "Scores: ";
    for (int i = 0; i < size; i++)
        std::cout << scoreArray[i] << ' ';
    std::cout << std::endl;
}

double averageScore(int scoreArray[], int size) {
    double total = 0;
    for (int i = 0; i < size; i++)
        total += scoreArray[i];
    return total / size;
}
