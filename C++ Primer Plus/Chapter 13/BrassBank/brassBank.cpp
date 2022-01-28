// Implementation file for Brass Bank

#include <stdexcept>
#include "brassBank.hpp"

namespace Brass {
    // BrassBase Methods //
    BrassBase::Format BrassBase::saveFmt(std::ostream &os, const Format &newfmt) const {
        Format prevfmt;
        prevfmt.fmt = os.setf(newfmt.fmt);
        prevfmt.prec = os.precision(newfmt.prec);
        return prevfmt;
    }

    void BrassBase::restoreFmt(std::ostream &os, const Format &prevfmt) const {
        os.setf(prevfmt.fmt);
        os.precision(prevfmt.prec);
    }

    BrassBase::BrassBase(const std::string &name, unsigned long accNum, double bal)
            : name_(name) {
        accountNum_ = accNum;
        balance_ = bal;
    }

    void BrassBase::deposit(double amt) {
        std::runtime_error InvalidAmount("Amount can't be negative");
        if (amt < 0) throw InvalidAmount;
        balance_ += amt;
    }

    bool BrassBase::withdraw(double amt) {
        if (amt > balance_) {
            std::cerr << "Amount exceeds balance. Transaction Cancelled\n";
            return false;
        }
        balance_ -= amt;
        return true;
    }
    
    void BrassBase::showaccount() const {
        std::cout << *this;
    }

    std::ostream & operator<<(std::ostream &os, const BrassBase &bb) {
        os << "Name:    "   << bb.name_
           << "\nAccNum:  " << bb.accountNum_
           << "\nBalance: " << bb.balance_ 
           << '\n';
        return os;
    }

    // Brass Methods //
    Brass::Brass(const std::string &name, unsigned long accNum, double bal)
            : BrassBase(name, accNum, bal) { }

    bool Brass::withdraw(double amt) {
        return BrassBase::withdraw(amt);
    }

    void Brass::showaccount() const {
        std::cout << *this;
    }

    std::ostream & operator<<(std::ostream &os, const Brass &b) {
        Brass::Format prev = b.saveFmt(os);
        os << dynamic_cast<const BrassBase &> (b);  // access parent overload
        b.restoreFmt(os, prev);
        return os;
    }

    // BrassPlus Methods //
    BrassPlus::BrassPlus(const std::string &name, unsigned long accNum, double bal,
                         double maxloan, double rate, double owes) 
            : BrassBase(name, accNum, bal) {
        maxloan_ = maxloan;
        rate_ = rate;
        owesbank_ = owes;
    }

    BrassPlus::BrassPlus(const Brass &br, double maxloan, double rate,
                         double owes) : BrassBase(br) {
        maxloan_ = maxloan;
        rate_ = rate;
        owesbank_ = owes;
    }

    bool BrassPlus::withdraw(double amt) {
        BrassPlus::Format prev = saveFmt(std::cout);
        double balance = showbalance();
        if (amt > balance + maxloan_ - owesbank_) {
            std::cerr << "Credit limit exceeded. Transaction cancelled\n";
            return false;
        }
        else if (amt <= balance)
            BrassBase::withdraw(amt);
        else {
            double advance = amt - balance;
            double interest = advance * (rate_/100.0);
            owesbank_ += interest;
            BrassBase::withdraw(amt - advance);
            std::cout << "Bank advance: $" << advance
                      << "\nFinance Charge: $" << interest
                      << '\n';
        }
        return true;
        restoreFmt(std::cout, prev);
    }

    void BrassPlus::showaccount() const {
        std::cout << *this;
    }

    std::ostream & operator<<(std::ostream &os, const BrassPlus &bp) {
        BrassPlus::Format prev = bp.saveFmt(os);
        os << "*** BrassPlus Account ***\n";
        os << dynamic_cast<const BrassBase &> (bp);
        os << "Max Loan:  "   << bp.maxloan_
           << "\nRate:      " << bp.rate_
           << "\nOwes Bank: " << bp.owesbank_
           << '\n';
        bp.restoreFmt(os, prev);
        return os;
    }

    template<>
    void readVal(std::string &var, const std::string &prompt) {
        /* Explicit specialization for std::string */
        std::runtime_error eofError("Unexpected EOF");
        for (;;) {
            std::cout << prompt;
            std::cin >> std::ws;
            if (!std::getline(std::cin, var)) {
                if (std::cin.eof())
                    throw eofError;
                std::cin.clear();
                while (std::cin.get() != '\n') ;
                std::cerr << "Invalid input\n";
            }
            else break;
        }
    }
}

