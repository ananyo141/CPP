// Implementation file for people.hpp

#include <iostream>
#include <cstdlib>
#include <cassert>
#include "people.hpp"
#include "../../StudentClass/studcont.hpp"
#define DEBUG(elem) std::cerr << #elem " = " << elem << '\n'
#undef DEBUG
#define DEBUG(elem)

namespace people {
    // Person Definitions
    Person::~Person() { }

    void Person::show() const {
        std::cout << "Person:\n";
        showData();
    }

    void Person::get() {
        util::readVal(fname_, "Enter first name: ");
        util::readVal(lname_, "Enter last name: ");
    }

    void Person::showData() const {
        std::cout << "FirstName: "  << fname_
                  << "\nLastName: " << lname_
                  << '\n';
    }

    // Gunslinger Definitions
    Gunslinger::Gunslinger(const std::string &fname, const std::string &lname,
                double drawTime, int numNotch) : Person(fname, lname) {
        drawTime_ = drawTime;
        numNotch_ = numNotch;
    }

    Gunslinger::Gunslinger(const Person &p, double drawTime, double numNotch)
        : Person(p), drawTime_(drawTime), numNotch_(numNotch) { }

    void Gunslinger::show() const {
        std::cout << "Gunslinger:\n";
        Person::showData();
        showData();
    }

    void Gunslinger::getData() {
        util::readVal(drawTime_, "Enter drawing time: ");
        util::readVal(numNotch_, "Enter number of notch: ");
    }

    void Gunslinger::get() {
        Person::get();
        getData();
    }
    void Gunslinger::showData() const {
        std::cout << "Draw time: " << drawTime_
                  << "\nNum of Notch: " << numNotch_
                  << '\n';
    }

    // Card Definitions
    const char* PokerPlayer::Card::suit_str[] = {
        "SPADE", "HEART", "CLUB", "DIAMOND"
    };

    const char* PokerPlayer::Card::face_str[] = {
        "ACE", "TWO", "THREE", "FOUR", "FIVE", 
        "SIX", "SEVEN", "EIGHT", "NINE", 
        "TEN", "JACK", "QUEEN", "KING"
    };

    PokerPlayer::Card::Card() {
        int suitVal = std::rand() % Card::NUM_SUITS;
        int faceVal = std::rand() % Card::NUM_FACES;
        suit_ = suits(suitVal);
        face_ = faces(faceVal);
        //Card(suitVal, faceVal);
    }

    PokerPlayer::Card::Card(int suitVal, int faceVal) {
        assert(suitVal > 0 && suitVal <= NUM_SUITS);
        assert(faceVal > 0 && faceVal <= NUM_FACES);
        suit_ = suits(suitVal);
        face_ = faces(faceVal);
    }

    PokerPlayer::Card::Card(suits suit, faces face) {
        suit_ = suit;
        face_ = face;
    }

    void PokerPlayer::Card::showCard() const {
        DEBUG(int(face_));
        DEBUG(int(suit_));
        std::cout << "Card: " << face_str[int(face_)] // both start
                  << " of "   << suit_str[int(suit_)] // from value 1
                  << '\n';
    }

    // PokerPlayer Definitions
    void PokerPlayer::show() const {
        std::cout << "PokerPlayer:\n";
        Person::showData();
        std::cout << "Card drawn: ";
        draw().showCard();
    }

    PokerPlayer::Card PokerPlayer::draw() const {
        return Card();
    }

    // BadDude Definitions
    BadDude::BadDude(const std::string &fname, const std::string &lname,
            double drawTime, int numNotch)
        : Person(fname, lname), Gunslinger(fname, lname, drawTime, numNotch)
    { }

    BadDude::BadDude(const Person &p, 
            double drawTime, int numNotch)
        : Person(p), Gunslinger(p, drawTime, numNotch)
    { }

    void BadDude::show() const {
        std::cout << "BadDude:\n";
        Person::showData();
        Gunslinger::showData();
    }

    void BadDude::get() {
        PokerPlayer::get(); 
        Gunslinger::getData(); 
    }

    double BadDude::gunDraw() const {
        return Gunslinger::draw();
    }

    BadDude::Card BadDude::cardDraw() const {
        return PokerPlayer::draw();
    }
}

