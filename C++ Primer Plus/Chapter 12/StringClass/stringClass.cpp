// Implementation file for StringClass

#include <iostream>
#include <cstring>
#include "stringClass.h"

// Internal private function //
static char * 
setAndAllocateStr(const char *src) {
    int len = std::strlen(src);
    char *dst = new char [len+1]; // memory for the string and null character
    std::strcpy(dst, src);
    return dst;
}

// Class Implementation //
namespace Str {
    // initialize the static attribute
    unsigned Str::numStr_ = 0;

    Str::Str() {
        numStr_++;
        str_ = new char[1];
        str_[0] = '\0';
    }

    Str::Str(const char *string) {
        str_ = setAndAllocateStr(string);
        numStr_++;
    }

    Str::Str(const Str &copy) {
        str_ = setAndAllocateStr(copy.str_);
        numStr_++;
    }

    Str::~Str() {
        // free the dynamically allocated memory
        delete [] str_;
        numStr_--;
    }

    Str & Str::operator=(const Str &copy) {
        delete [] str_; // delete previous allocation
        str_ = setAndAllocateStr(copy.str_);
        return *this;
    }

    Str & Str::operator=(const char *copy) {
        delete [] str_;
        str_ = setAndAllocateStr(copy);
        return *this;
    }

    Str Str::operator+(const Str &s2) const {
        /* Return a newly concatenated string 
           developed using dynamic memory */
        Str string;
        string.str_ = new char[this->len() + s2.len() + 1];
        std::strcpy(string.str_, str_);
        std::strcpy(string.str_+this->len(), s2.str_);
        return string;
    }

    Str operator+(const char *s1, const Str &s2) {
        return Str(s1) + s2;
    }

    Str Str::upper() const {
        Str uppercase(*this);   // invoke copy constructor
        int i = 0, len = uppercase.len();
        for (; i < len; i++) 
            uppercase[i] = toupper(uppercase[i]);
        return uppercase;
    }

    Str Str::lower() const {
        Str lowercase(*this);
        int i = 0, len = lowercase.len();
        for (; i < len; i++)
            lowercase[i] = tolower(lowercase[i]);
        return lowercase;
    }

    int Str::count(char ch) const {
        int count = 0;
        for (int i = 0; i < this->len(); i++)
            if (this->operator[](i) == ch)
                count++;
        return count;
    }

    std::ostream & operator<<(std::ostream &os, Str &obj) {
        os << obj.str_;
        return os;
    }

    std::istream & operator>>(std::istream &is, Str &obj) {
        char temp[Str::CINMAX];
        is.get(temp, Str::CINMAX);
        if (is)         // if stream has no errors
            obj = temp; // use overloaded assignment
        while (is && is.get() != '\n') // clear buffer
            continue;
        return is;
    }
}

