// Header file for string class //

#ifndef STRING_CLASS_H_
#define STRING_CLASS_H_
#include <iostream>
#include <cstring>

namespace Str {
    class Str {
    private:
        enum {CINMAX = 50};
        char *str_;
        static unsigned numStr_; // class attribute
    public:
        Str();                   // default constructor
        ~Str();                  // destructor
        Str(const char *);       // non-default 
        Str(const Str  &);       // copy constructor
        Str & operator=(const Str  &);        // assignment overload
        Str & operator=(const char *);        // overload for efficiency
        char & operator[](int i) { return str_[i]; }             // subscript overload
        const char & operator[](int i) const { return str_[i]; } // const subscript overload
        Str operator+(const Str &) const;                 // method to concatenate two Str objects
        friend Str operator+(const char *, const Str &);  // friend function to concat C-style and Str object
        /* inline comparision methods */
        explicit operator const char *() const { return str_; }
        operator bool() const { return str_[0]; }   // test true if there is atleast one character that is not null
        bool operator>(const Str &v2)  const { return strcmp(str_, v2.str_) > 0; }
        bool operator<(const Str &v2)  const { return strcmp(str_, v2.str_) < 0; }
        bool operator==(const Str &v2) const { return !strcmp(str_, v2.str_); } // return true if strcmp result is 0
        /* Object Method functions */
        Str upper() const;
        Str lower() const;
        int count(char) const;
        unsigned len() const { return std::strlen(str_); }
        /* iostream method */
        friend std::ostream &
             operator<<(std::ostream &, Str &);
        friend std::istream &
             operator>>(std::istream &, Str &);
        /* static class method */
        static unsigned totalStr() { return numStr_; }
    };
}

#endif

