#include <iostream>
#include "brassBank.hpp"

int main() {
    Brass::Brass Piggy("Porcelot Pigg", 381299, 4000);
    Brass::BrassPlus Hoggy("Horatio Hogg", 382288, 3000);
    Piggy.showaccount();
    std::cout.put('\n');
    std::cout << Hoggy << '\n';
    std::cout << "Depositing $1000 into Hogg Account\n";
    Hoggy.deposit(1000);

    std::cout << "New Balance: $" << Hoggy.showbalance()
              << "\n\nWithdrawing $4200 from Pigg Account:\n";
    if (!Piggy.withdraw(4200)) 
        std::cerr << "Withdrawal cancelled\n";
    std::cout << "Pigg account balance: $" << Piggy.showbalance()
              << "\nWithdrawing $4200 from Hogg account:\n";
    Hoggy.withdraw(4200);
    Hoggy.showaccount();

    return 0;
}

