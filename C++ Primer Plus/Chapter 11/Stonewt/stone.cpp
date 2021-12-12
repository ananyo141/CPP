// Implementation File for Stone Class

#include <iostream>
#include <cmath>
#include "stone.h"

namespace WEIGHT {
    void Weight::checkmode(Weight::Mode mode) const {
        switch(mode) {
            case Mode::STONE: case Mode::POUNDS:
                return;
            default: std::cerr << "Invalid Mode\n";
                     exit(EXIT_FAILURE);
        }
    }

    Weight::Weight() {
        pounds_ = 0.0;
        mode_   = Mode::STONE;
    }

    Weight::~Weight() { }

    Weight::operator double() const {
        return this->getval();
    }

    double Weight::getval() const {
        if (mode_ == Mode::STONE)
            return pounds_ / STN_TO_LBS;
        else 
            return pounds_;
    }

    void Weight::resetMode(Mode mode) {
        checkmode(mode);
        mode_ = mode;
    }

    Weight::Weight(double arg, Weight::Mode mode) {
        checkmode(mode);
        mode_ = mode;
        if (mode_ == Mode::STONE)
            pounds_ = arg * STN_TO_LBS;
        else 
            pounds_ = arg;
    }


    Weight::Weight(int stn, double pounds, Mode mode) {
        checkmode(mode);
        mode_   = mode;
        pounds_ = stn * STN_TO_LBS + pounds;
    }


    bool Weight::operator!=(const Weight &obj) const {
        return pounds_ != obj.pounds_;
    }

    bool Weight::operator==(const Weight &obj) const {
        return pounds_ == obj.pounds_;
    }

    bool Weight::operator> (const Weight &obj) const {
        return pounds_ > obj.pounds_;
    }

    bool Weight::operator< (const Weight &obj) const {
        return pounds_ < obj.pounds_;
    }

    bool Weight::operator>=(const Weight &obj) const {
        return pounds_ >= obj.pounds_;
    }

    bool Weight::operator<=(const Weight &obj) const {
        return pounds_ <= obj.pounds_;
    }

    Weight operator+(const Weight &obj1, const Weight &obj2) {
        return Weight(obj1.pounds_ + obj2.pounds_, Weight::Mode::POUNDS);
    }

    Weight operator-(const Weight &obj1, const Weight &obj2) {
        return Weight(obj1.pounds_ - obj2.pounds_, Weight::Mode::POUNDS);
    }

    Weight Weight::operator*(double val) const {
        return Weight(pounds_ * val, Mode::POUNDS);
    }

    Weight operator*(double val, const Weight &obj) {
        return obj * val;
    }

    std::ostream & operator<<(std::ostream &os, const Weight &obj) {
        if (obj.mode_ == Weight::Mode::STONE) {
            int stones    = obj.pounds_ / STN_TO_LBS;   // int division
            double pounds = fmod(obj.pounds_, STN_TO_LBS);
            os << stones << " Stones, " << pounds << " Pounds";
        }
        else
            os << obj.pounds_ << " Pounds";
        return os;
    }

    std::istream & operator>>(std::istream &is, Weight &obj) {
        double tempPounds;
        is >> tempPounds;
        obj = Weight(tempPounds, Weight::Mode::POUNDS);
        return is;
    }
}

