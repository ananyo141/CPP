/* 4. Do Programming Exercise 4 from Chapter 9 but convert the Sales structure and
its associated functions to a class and its methods. Replace the setSales(Sales &,
double [], int) function with a constructor. Implement the interactive
setSales(Sales &) method by using the constructor. Keep the class within the
namespace SALES. */

#include <iostream>
#include "sales.h"
const int QUARTERS = 4;

int main() {
    SALES::salesItem salesInfo[QUARTERS] = {600.5, 303.4, 134.22, 620.3};
    SALES::Sales s1;
    SALES::Sales s2(salesInfo, QUARTERS);
    s1.showSales();
    s2.showSales();

    return 0;
}

