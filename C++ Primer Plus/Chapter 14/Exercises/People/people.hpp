#ifndef PEOPLE_HPP_
#define PEOPLE_HPP_

/* 4. A Person class holds the first name and the last name of a person. In addition to its
constructors, it has a Show() method that displays both names.A Gunslinger class
derives virtually from the Person class. It has a Draw() member that returns a type
double value representing a gunslinger’s draw time.The class also has an int mem-
ber representing the number of notches on a gunslinger’s gun. Finally, it has a
Show() function that displays all this information.

A PokerPlayer class derives virtually from the Person class. It has a Draw() mem-
ber that returns a random number in the range 1 through 52, representing a card
value. (Optionally, you could define a Card class with suit and face value members
and use a Card return value for Draw().) The PokerPlayer class uses the Person
show() function.The BadDude class derives publicly from the Gunslinger and
PokerPlayer classes. It has a Gdraw() member that returns a bad dude’s draw time
and a Cdraw() member that returns the next card drawn. It has an appropriate
Show() function. Define all these classes and methods, along with any other neces-
sary methods (such as methods for setting object values) and test them in a simple
program similar to that in Listing 14.12.  */

#include <iostream>

namespace people {
    // Abstract Base Class
    class Person {
    private:
        std::string fname_;
        std::string lname_;
    protected:
        void showData() const;
    public:
        Person(): fname_("None"), lname_("None") { }
        Person(const std::string &fname, const std::string &lname)
            : fname_(fname), lname_(lname) { }
        virtual ~Person()  = 0;
        virtual void get() = 0;
        virtual void show() const = 0;
    };
    
    class Gunslinger: virtual public Person {
    protected:
        enum {DEF_GUNSL = -1};
        void getData();
        void showData() const;
    private:
        double drawTime_ = DEF_GUNSL;
        int numNotch_    = DEF_GUNSL;
    public:
        Gunslinger() { }    // Defaults with default base class constructor
        Gunslinger(const std::string &fname, const std::string &lname,
                   double drawTime, int numNotch);
        Gunslinger(const Person &p, double drawTime=DEF_GUNSL, double numNotch=DEF_GUNSL);
        virtual void get();
        virtual void show() const;
        double draw() const { return drawTime_; }
    };

    class PokerPlayer: virtual public Person {
    public:
        class Card {
        public:
            enum {NUM_SUITS = 4, NUM_FACES = 13};
            enum class suits: short {
                SPADE=1, HEART, CLUB, DIAMOND
            };
            enum class faces: short {
                ACE=1, TWO, THREE, FOUR, FIVE, 
                SIX, SEVEN, EIGHT, NINE, 
                TEN, JACK, QUEEN, KING
            };
        private:
            suits suit_;
            faces face_;
            static const char *suit_str[NUM_SUITS];
            static const char *face_str[NUM_FACES];
        public:
            Card();
            Card(int suitVal, int faceVal);
            Card(suits suit, faces face);
            void showCard() const;
        };

        PokerPlayer() { }
        PokerPlayer(const std::string &fname, const std::string &lname)
            : Person(fname, lname) { }
        PokerPlayer(const Person &p) : Person(p) { }
        virtual void get() { Person::get(); }
        virtual void show() const;
        virtual Card draw() const;
    };

    class BadDude: public Gunslinger, public PokerPlayer {
    public:
        BadDude() { }
        BadDude(const std::string &fname, const std::string &lname,
                double drawTime=DEF_GUNSL, int numNotch=DEF_GUNSL);
        BadDude(const Person &p, 
                double drawTime=DEF_GUNSL, int numNotch=DEF_GUNSL);

        virtual void get(); 
        virtual void show() const;
        double gunDraw()  const;
        Card   cardDraw() const;
    };
}

#endif

