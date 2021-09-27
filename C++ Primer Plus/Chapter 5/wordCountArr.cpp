/**************************************************************************************
 8. Write a program that uses an array of char and a loop to read one word at a time
 until the word done is entered.The program should then report the number of
 words entered (not counting done).A sample run could look like this:
 Enter words (to stop, type the word done):
 anteater birthday category dumpster
 envy finagle geometry done for sure
 You entered a total of 7 words.
 You should include the cstring header file and use the strcmp() function to
 make the comparison test.
**************************************************************************************/
#include <iostream>
#include <cstring>
#include <cctype>
const int ARRSIZE = 40;

int main() {
    char word[ARRSIZE];
    int wordCount = 0;
    std::cout << "Enter words (to stop, type the word done):\n";
    do {
        int i = 0 , ch;
        while (isspace(ch = std::cin.get())) ;
        word[i++] = ch;
        // Extract a single word 
        while ((ch = std::cin.get()) != ' ') {
            if (i == ARRSIZE - 1 || ch == '\n') break;
            word[i++] = ch;
        }        
        word[i] = '\0';
        wordCount++;
    } while (strcmp(word, "done") != 0);

    std::cout << "You entered a total of " << wordCount - 1 
              << " word(s) (excluding 'done')\n";

    return 0;
}
