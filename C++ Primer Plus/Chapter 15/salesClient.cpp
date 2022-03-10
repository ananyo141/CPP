#include <iostream>
#include <cstdlib>
#include <ctime>
#include "sales.hpp"

int main() {
    std::srand(std::time(0));
    const int MONTHS = 12;
    double grossArr[] = {
        1220, 1100, 1200, 1300, 1400, 1500,
        1600, 1700, 1800, 1900, 2000, 2001
    };

    Sales::Sales baseObj(2011, grossArr, MONTHS);
    Sales::LabeledSales derivedObj("Pragma", 2011, grossArr, MONTHS);

    Sales::Sales::bad_index * ptr;
    for (int i = 0; i <= sizeof(grossArr) / sizeof(grossArr[0]); i++) {
        try {
            if (std::rand() % 2)
                derivedObj[20];
            else
                baseObj[20];
        } catch (Sales::Sales::bad_index &exc) {
            Sales::LabeledSales::lbad_index *ptr;
            std::cout << "Caught Exception: " << typeid(exc).name() << '\n';
            if ((ptr = dynamic_cast<Sales::LabeledSales::lbad_index *> (&exc)))
                std::cout << "Derived Exception " << ptr->get_label();
            else
                std::cout << "Base Exception";
            std::cout.put('\n');
        }
    }
    return 0;
}

