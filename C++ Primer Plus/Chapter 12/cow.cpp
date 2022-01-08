#include <iostream>
#include <cstring>

static char *
setString(const char *tocopy) {
    /* Allocate memory and copy string */
    char *str = new char[std::strlen(tocopy) + 1];
    std::strcpy(str, tocopy);
    return str;
}

class Cow {
private:
    enum {MAX = 20};
    char name_[MAX];
    char *hobby_;
    double weight_;

public:
    Cow() {
        hobby_ = new char[1];
        name_[0] = hobby_[0] = '\0';
        weight_ = 0;
    }

    Cow(const char *name, const char *hobby, double wt) {
        std::strncpy(name_, name, MAX);
        name_[MAX-1] = '\0';
        hobby_  = setString(hobby);
        weight_ = wt;
    }

    Cow(const Cow &c) {
        std::strcpy(name_, c.name_);
        name_[MAX-1] = '\0'; // guarantee termination
        hobby_ = setString(c.hobby_);
        weight_ = c.weight_;
    }
    
    ~Cow() {
        delete [] hobby_;
    }

    Cow & operator=(const Cow &c) {
        delete [] hobby_;
        std::strcpy(name_, c.name_);
        name_[MAX-1] = '\0'; // guarantee termination
        hobby_ = setString(c.hobby_);
        weight_ = c.weight_;
        return *this;
    }

    void show() const {
        std::cout << "Name: "     << name_
                  << "\nHobby: "  << hobby_
                  << "\nWeight: " << weight_
                  << '\n';
    }

};

int main() {
    Cow c1("Dora", "Explorer", 50),
        c2("Jack", "Recon",    54),
        c3("Piper", "Steal",   46);
    Cow c4(c1), c5; // copy constructor
    c5 = c2;        // assignment operator (overload)
    std::cout << "\nc1:\n";
    c1.show();
    std::cout << "\nc2:\n";
    c2.show();
    std::cout << "\nc3:\n";
    c3.show();
    std::cout << "\nc4:\n";
    c4.show();
    std::cout << "\nc5:\n";
    c5.show();

    return 0;
}

