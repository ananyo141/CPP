#ifndef BRASS_BANK_HPP_
#define BRASS_BANK_HPP_
#include <iostream>

/* 
Brass: deposit, withdraw, show balance, view acc info
BrassPlus: 
    extra: maxloan, rate, owesbank
    extra methods: reset max, reset rate, reset owes (setters)
    method polymorphs: viewacc, withdraw
*/

namespace Brass {
    // Abstract Base Class for Brass Accounts
    class BrassBase {
    private:
        std::string name_;
        unsigned long accountNum_;
        double balance_;

    protected:
        enum {MAXLOAN=500, RATE=6};
        struct Format {
            std::ios_base::fmtflags fmt;
            std::streamsize prec;
        };
        Format saveFmt (std::ostream &os, const Format &newfmt =
                                Format{std::ios_base::fixed,2})  const;
        void restoreFmt(std::ostream &os, const Format &prevfmt) const;

    public:
        BrassBase(const std::string &name="none", unsigned long accNum=0, double bal=0);
        virtual ~BrassBase() { }
        void deposit(double amt);
        double showbalance() const { return balance_; }
        virtual bool withdraw(double amt) = 0;  // pure virtual methods//
        virtual void showaccount() const  = 0;
        friend std::ostream &
            operator<<(std::ostream &os, const BrassBase &bb);
    };

    class Brass: public BrassBase {
    public:
        Brass(const std::string &name="none", unsigned long accNum=0, double bal=0);
        virtual bool withdraw(double amt);
        virtual void showaccount() const;
        friend std::ostream &
            operator<<(std::ostream &os, const Brass &b);
    };

    class BrassPlus: public BrassBase {
    private:
        double maxloan_;
        double rate_;
        double owesbank_;

    public:
        BrassPlus(const std::string &name="none", unsigned long accNum=0, double bal=0,
                    double maxloan=MAXLOAN, double rate=RATE, double owes=0);
        explicit BrassPlus(const Brass &br, double maxloan=MAXLOAN,
                    double rate=RATE, double owes=0);
        void resetMax(double newmax)   { maxloan_  = newmax;  }
        void resetRate(double newrate) { rate_     = newrate; }
        void resetOwes(double owes)    { owesbank_ = owes;    }
        virtual bool withdraw(double amt);
        virtual void showaccount() const;
        friend std::ostream &
            operator<<(std::ostream &os, const BrassPlus &bp);
    };

    template <typename T>
    void readVal(T &var, const std::string &prompt) {
        /* Read an arbitrary item from user (stdin) */
        std::runtime_error eofError("Unexpected EOF");
        for (;;) {
            std::cout << prompt;
            if (!(std::cin >> var)) {
                if (std::cin.eof())
                    throw eofError;
                std::cin.clear();
                while (std::cin.get() != '\n') ;
                std::cerr << "Invalid input\n";
            }
            else break;
        }
    }

    template<>
    void readVal(std::string &var, const std::string &prompt);
}

#endif

