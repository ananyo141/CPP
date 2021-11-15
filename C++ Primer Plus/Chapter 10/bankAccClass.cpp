/* 5. Define a class to represent a bank account. Data members should include the
depositor’s name, the account number (use a string), and the balance. Member func-
tions should allow the following:
#Creating an object and initializing it.
#Displaying the depositor’s name, account number, and balance
#Depositing an amount of money given by an argument
#Withdrawing an amount of money given by an argument
Just show the class declaration, not the method implementations. (Programming
Exercise 1 provides you with an opportunity to write the implementation.) */

#include <iostream>

class BankAcc {
private:
    std::string depositor_;
    std::string accNum_;
    double balance_;
public:
    BankAcc(std::string depositor="nil", std::string acc_num="nil", double baln=0.0) {
        /*Creating an object and initializing it.*/
        depositor_ = depositor;
        accNum_    = acc_num;
        balance_   = baln;
    }
    void showDetails() const {
        /*Displaying the depositor’s name, account number, and balance*/
        std::ios_base::fmtflags orig = std::cout.setf(std::ios_base::fixed, std::ios_base::floatfield);
        std::streamsize prec = std::cout.precision(3);
        int decor, LIM = 35;
        for (decor = 0; decor < LIM; decor++)
            std::cout << "-";
        std::cout << "\nDepositor: " << depositor_
                  << "\n  Acc No:  " << accNum_
                  << "\n  Balance: " << balance_ << '\n';
        for (decor = 0; decor < LIM; decor++)
            std::cout << "-";
        std::cout << '\n';
        std::cout.setf(orig, std::ios_base::floatfield);
        std::cout.precision(prec);
    }
    double deposit(double amt) {
        /*Depositing an amount of money given by an argument*/
        if (amt < 0) {
            std::cout << "You can't deposit negative.Aborted.\n";
            amt = 0;
        }
        balance_ += amt;
        return balance_;
    }
    double withdraw(double amt) {
        /*Withdrawing an amount of money given by an argument*/
        if (amt > balance_) {
            std::cout << "You can't withdraw more than you own\n";
            goto invalid;
        } else if (amt < 0) {
            std::cout << "You can't withdraw negative\n";
            goto invalid;
        } else {
            balance_ -= amt;
            return balance_;
        }
        invalid:
            return balance_;
    }
};
    
int main() {
    BankAcc person1("John", "1000293331AR24");
    BankAcc person2("Synthia", "20331JKI322FD", 3000332);

    person1.showDetails();
    person2.showDetails();

    person1.deposit(32222);
    person2.deposit(-1);

    person1.showDetails();
    person2.showDetails();

    person1.withdraw(200);
    person2.withdraw(30000000000);

    return 0;
}

