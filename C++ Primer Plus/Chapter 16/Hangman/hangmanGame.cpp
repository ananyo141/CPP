// Implement a hangman game using a list of random words

#include <iostream>
#include <fstream>
#include <ctime>
#include <cctype>
#include "hangmanUtils.hpp"
const int DEF_GUESSES = 6;

// Function Declarations
static inline void terminate(const std::string &errmsg) {
    /* Internal termination protocol */
    std::cerr << errmsg << '\n';
    std::exit(EXIT_FAILURE);
}

// Main Game
int main(int argc, const char *argv[]) {
    std::srand(std::time(0));
    if (argc < 2)
        terminate(std::string("Usage: ") + *argv + " WORDSFILE [NUM GUESSES]");

    // if 3rd cmd arg exists, use it as the number for guess limit
    int numGuesses = (argc > 2) ? std::atoi(argv[2]) : DEF_GUESSES;
    hman::wordlist_t wordlist;
    try {
        wordlist = hman::getRandomWordlist(argv[1]); // first cmd arg is
                                                     // random filename
    } catch (const hman::iofail &exc) {
        terminate(exc.what());
    }
    int numWords  = wordlist.size();
    if (!numWords)
        terminate("No words found in file");

    // Main game loop
    char choice;
    hman::PlayHangman gameSession(numGuesses);
    for (;;) {
        std::cout << "Do you want to play a game? <y/n>: ";
        if (!(std::cin >> choice 
             && std::tolower(choice) == 'y')) break;
        gameSession.play(wordlist[std::rand() % wordlist.size()]);
        std::cout.put('\n');
        gameSession.displayStats(gameSession.getStats());
    }
    return 0;
}

