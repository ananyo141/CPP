// Design a Time Class with operator overloading, friend functions

#include <iostream>
#include "timeClass.h"


namespace TIME {
    Time::Time () {                             // default constructor
        hours_ = 0;
        mins_  = 0;
    }

    Time::Time(double hours) {                  // Takes one double argument and converts
        hours_ = int(hours);                    // into corresponding hours-mins value,
        mins_  = (hours - hours_) * HR_TO_MIN;  // only supports explicit conversion
    }

    Time::Time(int hours, long mins) {
        hours_ = hours + int(mins / HR_TO_MIN); // integer division
        mins_  = mins % HR_TO_MIN;              // this constructor manages to convert the 
    }                                           // overstanding minutes to appropriate hours

    void Time::reset(double hours, int mins) {  // resets the existing object in-place,
        if (!mins)                              // invokes different constructors
            *this = Time(hours);                // as per given arguments
        else
            *this = Time(hours, mins);
    }

    long Time::toMins() const {                 // convert hours and minutes to total mins
        return (hours_ * HR_TO_MIN) + mins_;
    }
    
    /* FOR OPERATOR '-' */
    template<typename T>
    Time Time::operator-(const T &val) const {         // Invoke the next overloaded method
        return *this - (Time)val;
    }

    Time Time::operator-(const Time &obj) const {      // subtract the time of passed obj
        Time subtractedTime;                           // from invoking obj
        subtractedTime.mins_  = mins_  - obj.mins_;
        subtractedTime.hours_ = hours_ - obj.hours_;
        if (subtractedTime.mins_ < 0) {                // take care of underflow, in case
            subtractedTime.mins_ += HR_TO_MIN;         // mins become negative, borrow time
            --subtractedTime.hours_;                   // from hours
        }
        return subtractedTime;
    }

    template<typename T>
    Time operator-(const T &val, const Time &obj) {
        return obj - val;                              // invoke first operator method
    }

    /* FOR OPERATOR '+' */
    template<typename T>
    Time Time::operator+(const T &val) const {
        return *this + (Time)val;
    }

    Time Time::operator+(const Time &obj) const {
        int totalMins = this->toMins() + obj.toMins(); // calculate total minutes and pass
        return Time(0, totalMins);                     // to constructor for further formatting
    }

    template<typename T>
    Time operator+(const T &val, const Time &obj) {
        return obj + val;                              // invoke the obj.operator+(val) method
    }

    /* FOR OPERATOR '*' */
    template<typename T>
    Time Time::operator*(T &val) const {
        int totalMins = this->toMins() * val;
        return Time(0, totalMins);

    }

    Time Time::operator*(const Time &obj) const {
        long totalMins = this->toMins() + long(obj.toMins());
        return Time(0, totalMins);
    }

    Time operator*(double val, const Time &obj) {
        return obj * val;
    }

    void Time::show() const {
        std::cout << hours_ << " hours and "
                  << mins_  << " minutes\n";
    }

    std::ostream & operator<<(std::ostream &os, const Time &obj) {
        obj.show();
        return os;
    }
}

