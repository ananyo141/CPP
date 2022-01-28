#ifndef TABLE_TENNIS_HPP_
#define TABLE_TENNIS_HPP_
#include <string>

namespace tt {
    // Base Class
    class TableTennisPlayer {
    private:
        std::string firstname_;
        std::string lastname_;
        bool hasTable_;
    protected:
        const std::string &
            getfirstname() const { return firstname_; }
        const std::string &
            getlastname()  const { return lastname_;  }
    public:
        TableTennisPlayer(const std::string &fname="none",
                    const std::string &lname="none", bool htab=false);
        virtual ~TableTennisPlayer()        { }
        virtual std::string getName() const { return lastname_ + ", " + firstname_; }
        bool getTable()               const { return hasTable_; }
        void resetTable(bool htab)          { hasTable_ = htab; }
    };

    // Derived Class
    class RatedTTPlayer: public TableTennisPlayer {
    private:
        int rating_;
    public:
        RatedTTPlayer(const std::string &fname="none",
                    const std::string &lname="none", bool htab=false, int rating=0);
        RatedTTPlayer(int rating, const TableTennisPlayer &ttp);
        virtual std::string getName() const { return getfirstname() + " " + getlastname(); }
        int getRating()               const { return rating_;   }
        void resetRating(int rating)        { rating_ = rating; }
    };

    void hasTable(const TableTennisPlayer &player);
}

#endif

