/*
4. Many state lotteries use a variation of the simple lottery portrayed by Listing 7.4. In
these variations you choose several numbers from one set and call them the field
numbers. For example, you might select five numbers from the field of 1–47).You
also pick a single number (called a mega number or a power ball, etc.) from a sec-
ond range, such as 1–27.To win the grand prize, you have to guess all the picks cor-
rectly.The chance of winning is the product of the probability of picking all the
field numbers times the probability of picking the mega number. For instance, the
probability of winning the example described here is the product of the probability
of picking 5 out of 47 correctly times the probability of picking 1 out of 27 cor-
rectly. Modify Listing 7.4 to calculate the probability of winning this kind of lottery.
*/

#include <iostream>
const int FIELD_RANGE = 47;
const int FIELD_GUESS =  5;
const int MEGA_RANGE  = 27;
const int MEGA_GUESS  =  1;

double nCr(int n, int r);

int main() {
    std::cout << "If get to choose " << FIELD_GUESS << " field cards from a pack of "
              << FIELD_RANGE << " cards, and " << MEGA_GUESS << " Mega Card from "
              << MEGA_RANGE;
    std::cout << "\nThe probability of winning the lottery is 1 in ";

    double result = nCr(FIELD_RANGE, FIELD_GUESS) * nCr(MEGA_RANGE, MEGA_GUESS);
    std::cout << std::fixed;
    std::cout.precision(2);
    std::cout << result << std::endl;

    return 0;
}

double nCr(int n, int r) {
    // find the combination for the given input //
    if (n == r || r == 0) return 1;

    return nCr(n-1, r) + nCr(n-1, r-1);
}
