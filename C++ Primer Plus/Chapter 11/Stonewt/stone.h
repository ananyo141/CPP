// A class that represents weights in stone and pounds

#ifndef STONE_H_
#define STONE_H_

namespace WEIGHT {
    const float STN_TO_LBS = 14;    // float, so doesn't inadvertently cause
                                    // problems in client code if divided by
    class Weight {
    public:
        enum class Mode :short {STONE, POUNDS}; // scoped enum required; else
    private:                                    // giving ambiguous error due to
        double pounds_;                         // implicit conversion from enum to int
        Mode mode_;
        void checkmode(Mode) const;
    public:
        Weight();
        ~Weight();
        double getval() const;
        explicit operator double() const;       // explicit; to prevent ambiguity with builtins
        void resetMode(Mode);
        Weight(double arg, Mode mode=Mode::POUNDS);
        Weight(int stn, double pounds, Mode mode=Mode::STONE);
        // For Objects (second arg can still be implicitly converted)
        bool operator==(const Weight &) const;
        bool operator!=(const Weight &) const;
        bool operator> (const Weight &) const;
        bool operator< (const Weight &) const;
        bool operator>=(const Weight &) const;
        bool operator<=(const Weight &) const;
        Weight operator*(double) const;                     // member (*) overload
        // Support implicit conversion and then operation
        friend Weight operator+(const Weight &, const Weight &);
        friend Weight operator-(const Weight &, const Weight &);
        friend Weight operator*(double, const Weight &);    // non-member (*) overload
        friend std::ostream & 
             operator<<(std::ostream &os, const Weight &obj);
        friend std::istream &
             operator>>(std::istream &is, Weight &obj);
    };
}

#endif

