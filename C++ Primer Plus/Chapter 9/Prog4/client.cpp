/* The first file should be a header file that contains the namespace.The second file
should be a source code file that extends the namespace to provide definitions for
the three prototyped functions.The third file should declare two Sales objects. It
should use the interactive version of setSales() to provide values for one struc-
ture and the non-interactive version of setSales() to provide values for the sec-
ond structure. It should display the contents of both structures by using
showSales(). */

#include <iostream>
#include "sales.h"

int main() {
    double salesInfo[SALES::QUARTERS] = {600.5, 303.4, 134.22, 620.3};
    SALES::Sales s1, s2;
    SALES::setSales(s1);
    SALES::setSales(s2, salesInfo, SALES::QUARTERS);

    std::cout << "\n******** Showing Sales 1 ********\n";
    SALES::showSales(s1);
    std::cout << "******** Showing Sales 2 ********\n";
    SALES::showSales(s2);

    return 0;
}

