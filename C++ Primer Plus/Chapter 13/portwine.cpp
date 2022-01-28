/* 4. The Benevolent Order of Programmers maintains a collection of bottled port.To
   describe it, the BOP Portmaster has devised a Port class, as declared here:
   The Show() method presents information in the following format:
   Brand: Gallo
   Kind: tawny
   Bottles: 20

   The operator<<() function presents information in the following format (with no
   newline character at the end):
   Gallo, tawny, 20

   You get the job of completing the VintagePort work.
   a. Your first task is to re-create the Port method definitions because the former
   Portmaster immolated his upon being relieved.
   b. Your second task is to explain why certain methods are redefined and others
   are not.
   c. Your third task is to explain why operator=() and operator<<() are not
   virtual.
   d. Your fourth task is to provide definitions for the VintagePort methods.  */

#include <iostream>
#include <cstring>

namespace {
    class Port {
    private:
        enum {CHRMAX = 25};
        char *brand_;
        char style_[CHRMAX];
        int bottles_;
    protected:
        static char *stralloc(const char *tocopy) {
            char *buffer = new char[std::strlen(tocopy) + 1];
            std::strcpy(buffer, tocopy);
            return buffer;
        }
    public:
        Port(const char *br = "none", const char *st = "none", int b = 0) {
            brand_ = stralloc(br);
            std::strncpy(style_, st, CHRMAX-1);
            style_[CHRMAX-1] = '\0';        // always null terminated
            bottles_ = b;
        }
        Port(const Port &p) {
            brand_ = stralloc(p.brand_);
            std::strcpy(style_, p.style_);  // no need to check for null,
            bottles_ = p.bottles_;          // previous constr guarantees null termination
        }
        virtual ~Port() { delete[] brand_; }
        Port & operator=(const Port &p) {
            if (this == &p) return *this;
            delete[] brand_;
            brand_ = stralloc(p.brand_);
            std::strcpy(style_, p.style_);
            bottles_ = p.bottles_;
            return *this;
        }
        Port & operator+=(int b) {
            bottles_ += b;
            return *this;
        }
        Port & operator-=(int b) {
            bottles_ -= b;
            return *this;
        }
        int bottleCount() const { return bottles_; }
        virtual void show() const {
            std::cout << "Brand: "     << brand_
                      << "\nKind: "    << style_
                      << "\nBottles: " << bottles_
                      << '\n';
        }
        friend std::ostream &
        operator<<(std::ostream &os, const Port &p) {
            os << p.brand_ << ", " << p.style_ << ", " << p.bottles_;
            return os;
        }
    };

    class VintagePort: public Port {
    private:
        char *nickname_;
        int year_;
    public:
        VintagePort() : Port("unnamed", "Vintage", 0) {
            nickname_ = nullptr;
            year_ = -1;
        }
        VintagePort(const char *br, int b, const char *nn, int y)
                : Port(br, "Vintage", b)  {
            nickname_ = stralloc(nn);
            year_ = y;
        }
        VintagePort(const VintagePort &vp)
                : Port (vp)               {
            nickname_ = stralloc(vp.nickname_);
            year_ = vp.year_;
        }
        ~VintagePort() { delete[] nickname_; }
        VintagePort & operator=(const VintagePort &vp) {
            delete[] nickname_;
            Port::operator=(vp);
            nickname_ = stralloc(vp.nickname_);
            year_ = vp.year_;
            return *this;
        }
        void show() const {
            Port::show();
            std::cout << "Nickname: " << nickname_
                      << "\nYear: "   << year_
                      << '\n';
        }
        friend std::ostream &
        operator<<(std::ostream &os, const VintagePort &vp) {
            os << dynamic_cast<const Port &> (vp);
            os << ", " << vp.nickname_ << ", " << vp.year_;
            return os;
        }
    };
}

// Testing Class
int main() {
    Port p1("Old", "Tawny", 3);
    VintagePort v1("Bang", 2, "The Noble", 2001);

    p1.show();
    v1.show();

    std::cout << p1 << '\n' << v1 << '\n';

    return 0;
}

