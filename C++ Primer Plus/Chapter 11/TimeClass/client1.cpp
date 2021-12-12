#include <iostream>
#include "timeClass.h"

int main() {
    using TIME::Time;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    std::cout << "Planning time = ";
    planning.show();
    std::cout << std::endl;

    std::cout << "Coding time = ";
    coding.show();
    std::cout << std::endl;

    std::cout << "Fixing time = ";
    fixing.show();
    std::cout << std::endl;

    total = coding + fixing;
    std::cout << "Coding + Fixing = ";
    total.show();
    std::cout << std::endl;
    
    return 0;
}

