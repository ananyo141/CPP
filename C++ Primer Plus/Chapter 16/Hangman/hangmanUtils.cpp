// Logic for hangman utilites
#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include "hangmanUtils.hpp"

namespace hman {
    wordlist_t getRandomWordlist(const std::string &fname) {
        /* Return a set of random words in a vector container */
        std::string word;
        wordlist_t wordlist;
        std::ifstream randomfile;
        if (randomfile.open(fname), !randomfile.is_open())
            throw iofail("Unable to open file '" + fname + '\'');
        while (getline(randomfile, word))
            if (word != "")
                wordlist.push_back(word);
        randomfile.close();
        return wordlist;
    }

    void PlayHangman::displayStats(const PlayHangman::GameStats &stats) {
        /* Display formatted score output stats */
        // display header
        std::cout << std::setw(15) << std::setfill('-') << " Stats: "
                  << std::setw(15) << std::setfill('-') << '\n';
        // display score stats
        std::cout << "Wins: " << stats.wins << " Lost: " << stats.lost
                  << "\nPoints: " << stats.points << " Total Points: " << stats.totalPoints 
                  << "\nTotal Games: " << stats.numGames << '\n';
    }

    // PlayHangman definitions
    void PlayHangman::checkNumGuess(long numGuesses) {
        /* Throw exception if numGuesses <= 0 */
        if (numGuesses <= 0)
            throw std::invalid_argument("Guesses can't be 0 or negative");
    }

    bool PlayHangman::play(const std::string &word) {
        /* Play a round of Hangman, return true if won the round
           or false if failed */
        char letterGuess;
        int index, badGuesses = 0;
        std::vector<char> badLetters;
        std::string constructedWord(word.size(), '-');
        std::cout << "I am a " << word.size() << " lettered word\n"
                     "You get " << numGuesses_ << " guesses. Guess what I am?: ";

         while (badGuesses < numGuesses_ &&
                constructedWord != word  &&
                std::cin >> letterGuess) {
            // if letter is already guessed either correctly or incorrectly
            if ( (std::find(badLetters.begin(), badLetters.end(), letterGuess) 
                        != badLetters.end()) ||
                 (constructedWord.find(letterGuess) 
                        != std::string::npos) ) {
                std::cout << "You already guessed that, try again\n";
                continue;
            }
            // if letter is not guessed and is correct
            if (word.find(letterGuess) != std::string::npos) {
            index = -1;
            // Replace all the instances of the guessed letter in the
            // constructedWord
            while ( (index = word.find(letterGuess, index+1)) != std::string::npos)
                constructedWord[index] = letterGuess;
            std::cout << "That was correct!\n"
                         "Word constructed: " << constructedWord << '\n';
            // else is bad guess
            } else {
                badGuesses++;
                std::cout << "That was a bad guess!\n";
                badLetters.push_back(letterGuess);
                std::cout << " Guesses left: " << numGuesses_ - badGuesses << "\nBad guesses: ";
                for (const auto &ch: badLetters)
                    std::cout << ch << ' ';
                std::cout.put('\n');
            }
        }
        numGames_++;
        points_ = numGuesses_ - badGuesses;
        points_ = points_ == 0 ? -1 : points_; // -1 for not getting it
        totalPoints_ += points_;

        // Round Won
        if (constructedWord == word) {
            wins_++;
            std::cout << "You correctly guessed " << word 
                      << " in " << badGuesses << " guesses\n";
            return true;
        // Round Lost
        } else {
            lost_++;
            std::cout << "You couldn't guess " << word 
                      << " in " << numGuesses_ << " guesses\n";
            return false;
        }
    }
}

