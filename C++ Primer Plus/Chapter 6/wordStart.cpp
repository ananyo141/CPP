/*
7. Write a program that reads input a word at a time until a lone q is entered.The
program should then report the number of words that began with vowels, the num-
ber that began with consonants, and the number that fit neither of those categories.
One approach is to use isalpha() to discriminate between words beginning with
letters and those that don’t and then use an if or switch statement to further iden-
tify those passing the isalpha() test that begin with vowels.A sample run might
look like this:
Enter words (q to quit):
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q
5 words beginning with vowels
4 words beginning with consonants
2 others
*/
#include <iostream>
#include <cstring>
#include <cctype>
const char *VOWELS = "aeiouAEIOU";

int main() {
    char fistLetter;
    std::string word;
    int vowels = 0, consonants = 0, others = 0;
    std::cout << "Enter words (q to quit):\n";
    while(std::cin >> word) {
        if (word == "q") break;
        if (strchr(VOWELS, word[0]) != nullptr)
            vowels++;
        else if (isalpha(word[0])) 
            consonants++;
        else others++;
    }
    std::cout << std::endl;
    std::cout << vowels << " words begin with vowels\n"
              << consonants << " words begin with consonants\n"
              << others << " others\n";

    return 0;
}
