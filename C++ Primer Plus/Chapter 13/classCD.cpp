/* Derive a Classic class that adds an array of char members that will hold a string
   identifying the primary work on the CD. If the base class requires that any func-
   tions be virtual, modify the base-class declaration to make it so. If a declared
   method is not needed, remove it from the definition.  */

#include <iostream>
#include <cstring>

class Cd {
private:
    char *performers_;
    char *label_;
    int selections_;
    double playtime_;

protected:  // protected access controlled class method
    static char *stralloc(const char *strcopy) {
        unsigned len = std::strlen(strcopy);
        char *buffer = new char[len+1];
        std::strcpy(buffer, strcopy);
        return buffer;
    }

public:
    Cd() {
        performers_ = label_ = nullptr;
        selections_ = playtime_ = 0;
    }
    virtual ~Cd() {
        delete[] performers_;
        delete[] label_; 
    }
    Cd(const char *perfm, const char *lab, int sel, double play) {
        performers_ = stralloc(perfm);
        label_      = stralloc(lab);
        selections_ = sel;
        playtime_   = play;
    }
    Cd(const Cd &c) {
        performers_ = stralloc(c.performers_);
        label_      = stralloc(c.label_);
        selections_ = c.selections_;
        playtime_   = c.playtime_;
    }
    Cd & operator=(const Cd &c) {
        delete[] performers_;
        delete[] label_;
        performers_ = stralloc(c.performers_);
        label_      = stralloc(c.label_);
        selections_ = c.selections_;
        playtime_   = c.playtime_;
        return *this;
    }
    virtual void report() const {
        std::cout << "Performers: "   << performers_
                  << "\nLabel:      " << label_
                  << "\nSelections: " << selections_
                  << "\nPlaytime:   " << playtime_
                  << '\n';
    }
};

class Classic: public Cd {
    private:
        char *primary_;

    public:
        Classic()           { primary_ = nullptr; }
        virtual ~Classic()  { delete[] primary_; }

        Classic(const char *prim, const char *perfm,
                    const char *lab, int sel, double play)
                : Cd(perfm, lab, sel, play) {   // parent init
            primary_ = stralloc(prim);
        }

        Classic(const char *prim, const Cd &c)  // convenience constr
                : Cd(c) { primary_ = stralloc(prim); }        // call parent copy constr

        Classic(const Classic &d)               // derived class copy constructor
                : Cd(d) { primary_ = stralloc(d.primary_); }  // call parent copy constr

        Classic & operator=(const Classic &d) {
            delete[] primary_;
            primary_ = stralloc(d.primary_);
            Cd::operator=(d);                   // call base class operator
            return *this;
        }

        virtual void report() const {
            Cd::report();
            std::cout << "Primary Work: " << primary_ << '\n';
        }
};

// Call by Base class reference
void bravo(const Cd &disk) { disk.report(); }

int main() {
    Cd c1("Beatles", "Capitol", 14, 35.5);
    //Classic c2 = Classic();
    Classic c2 = Classic("Piano Sonata in B Flat, Fantasia in C",
                         "Alfred Brendel", "Philips", 2, 57.17);
    Cd *pcd = &c1;
    std::cout << "Using object directly:\n";
    c1.report();
    c2.report();

    std::cout << "Using type cd * pointer to objects:\n";
    pcd->report();
    pcd = &c2;
    pcd->report();

    std::cout << "Calling a function with a Cd reference arg:\n";
    bravo(c1);
    bravo(c2);

    std::cout << "Testing Assignment: ";
    Classic copy;
    copy = c2;
    copy.report();

    return 0;
}

