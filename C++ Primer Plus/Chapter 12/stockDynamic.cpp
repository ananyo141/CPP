#include <iostream>
#include <cstring>

namespace Stock {

    // Private allocation function //
    static char *
    setString(const char *str) {
        char *copy = new char [std::strlen(str) + 1];
        std::strcpy(copy, str);
        return copy;
    }

    // Stock Class //
    class Stock {
    private:
        char *company_;
        int shares_;
        double share_val_;

    public:
        Stock() {
            company_   = nullptr;
            shares_    = 0;
            share_val_ = 0;
        }

        Stock(const char *company, long num_shares=0, double price=0) {
            company_   = setString(company);
            shares_    = num_shares < 0 ? std::cerr << "Shares can't be negative\n", 0 : num_shares;
            share_val_ = price < 0 ? std::cerr << "Price can't be negative\n", 0 : price;
        }

        ~Stock() {
            delete [] company_;
        }

        double getTotal() const {
            return shares_ * share_val_;
        }

        void buy(long num, double price) {
            if (num < 0) 
                std::cerr << "Number of shares can't be negative\n";
            else if (num > shares_)
                std::cerr << "You can't sell more than you have\n";
            else {
                shares_ -= num;
                share_val_ = price;
            }
        }

        void sell(long num, double price) {
            if (num < 0)
                std::cout << "Number of shares can't be negative\n";
            else if (num > shares_) 
                std::cout << "You can't sell more than you have!\n";
            else {
                shares_ -= num;
                share_val_ = price;
            }
        }

        void update(double price) {
            share_val_ = price;
        }

        friend std::ostream &
            operator<<(std::ostream &os, const Stock &obj) {

            std::ios_base::fmtflags orig = os.setf(std::ios_base::fixed, std::ios_base::floatfield);
            std::streamsize prec = os.precision(3);

            os << "Company: " << obj.company_
            << "\nShares: " << obj.shares_
            << "\nShare Price: $" << obj.share_val_;
            os.precision(2);
            os << "\nTotal Worth: $" << obj.getTotal() << "\n";

            os.setf(orig, std::ios_base::floatfield);
            os.precision(prec);

            return os;
        }

        const Stock & topval(const Stock &s) const {
            return (s.getTotal() > this->getTotal())
                ? s
                : *this;
        }
            
    };
}

const int STKS = 4;
int main() {
    using Stock::Stock;
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    std::cout << "Stock Holdings:\n";
    int st;
    for (st = 0; st < STKS; st++) 
        std::cout << stocks[st];
    const Stock *top = stocks;  // first element
    for (st = 1; st < STKS; st++) 
        top = &top->topval(stocks[st]);
    std::cout << "\nMost valuable Holding:\n";
    std::cout << *top;

    return 0;
}

