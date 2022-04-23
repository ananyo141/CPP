/* 7. A common game is the lottery card.The card has numbered spots of which a cer-
tain number are selected at random.Write a Lotto() function that takes two argu-
ments.The first should be the number of spots on a lottery card, and the second
should be the number of spots selected at random.The function should return a
vector<int> object that contains, in sorted order, the numbers selected at random. */

#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>

static std::vector<int> lotto(int total, int sample);

int main() {
    std::srand(std::time(0));
    auto winners = lotto(51, 6);
    for (const int i: winners)
        std::cout << i << ' ';
    std::cout.put('\n');

    return 0;
}

static std::vector<int> lotto(int total, int sample) {
    /* Return a vector of ints containing sample number of 
       random values from total numbers */
    std::vector<int> allPosVal(total);
    for (int i = 0; i < total; i++)
        allPosVal[i] = i + 1;
    std::random_shuffle(allPosVal.begin(), allPosVal.end());
    std::vector<int> valueSample (allPosVal.cbegin(), allPosVal.cbegin() + sample);
    std::sort(valueSample.begin(), valueSample.end());
    return valueSample;
}

