// Utilties for Hangman Game
#ifndef HANGMAN_UTILS_HPP_
#define HANGMAN_UTILS_HPP_

#include <string>
#include <vector>
#include <stdexcept>

namespace hman {
    // type alias for wordlist
    using wordlist_t = std::vector<std::string>;

    // function to read and return a constructed set of random words
    wordlist_t getRandomWordlist(const std::string &fname);

    // throw exception in getRandomWordlist()
    class iofail: public std::runtime_error {
    public:
        explicit iofail(const std::string &what_arg)
            : runtime_error(what_arg) {}
        virtual ~iofail() {}
    };

    // class to play and reserve stats for hangman session
    class PlayHangman {
    private:
        unsigned numGuesses_;
        int wins_        = 0;   // supply default value (0)
        int lost_        = 0;   // to avoid initializing
        int points_      = 0;   // each everytime on
        int totalPoints_ = 0;   // constructor(s)
        int numGames_    = 0;

    protected:
        static void checkNumGuess(long numGuesses);
    public:
        // A struct type to hold points return values
        struct GameStats {
            int wins;
            int lost;
            int points;
            int totalPoints;
            int numGames;
        };

        // virtual methods to allow subclassing required methods
        explicit PlayHangman(long numGuesses=6) { setGuesses(numGuesses); }
        virtual ~PlayHangman() { }
        virtual bool play(const std::string &word);
        virtual void setGuesses(long numGuesses) { checkNumGuess(numGuesses); 
                                                   numGuesses_ = numGuesses; }
        virtual GameStats getStats() const { return GameStats{wins_, lost_, points_,
                                            totalPoints_, numGames_}; }
        // Class method to display formatted stats
        static void displayStats(const PlayHangman::GameStats &);
    };
}

#endif

