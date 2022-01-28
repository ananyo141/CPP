#include <iostream>
#include <stdexcept>
#include "brassBank.hpp"
const int CLIENTNUM = 4;

int main() {
    using Brass::readVal;
    int i;
    std::string tempname;
    bool isBrassPlus;
    unsigned long tempAccNum;
    double rate, overdraft, tempBal;
    Brass::BrassBase *clients[CLIENTNUM];
    for (i = 0; i < CLIENTNUM; i++) {
        readVal(tempname, "Enter client name: ");
        readVal(tempAccNum, "Enter account: ");
        readVal(tempBal, "Enter opening balance: ");
        readVal(isBrassPlus, "Enter 0 for Brass Account or "
                             "1 for BrassPlus Account: ");
        if (!isBrassPlus) {
            clients[i] = new Brass::Brass(tempname, tempAccNum, tempBal);
            continue;
        }
        readVal(overdraft, "Enter overdraft limit: ");
        readVal(rate, "Enter interest rate: ");
        clients[i] = new Brass::BrassPlus(tempname, tempAccNum, 
                         tempBal, overdraft, rate);
    }

    std::cout.put('\n');
    for (i = 0; i < CLIENTNUM; i++) {
        clients[i]->showaccount();
        delete clients[i];
    }

    return 0;
}

