#include <iostream>
#include "sales.h"

namespace SALES {
    void setSales(Sales & s, const double ar[], int n) {
    /* copies the lesser of 4 or n items from the array ar
       to the sales member of s and computes and stores the
       average, maximum, and minimum values of the entered items;
       remaining elements of sales, if any, set to 0 */ 
        double max, min, total = 0;
        for (int i = 0; i < QUARTERS; i++) {
            s.sales[i] = i<n ? ar[i] : 0;
            if (i == 0) {
                max = s.sales[i];
                min = s.sales[i];
            }
            if (s.sales[i] < min) min = s.sales[i];
            if (s.sales[i] > max) max = s.sales[i];
            total += s.sales[i];
        }
        s.max = max;
        s.min = min;
        s.average = total / QUARTERS;
    }
    void setSales(Sales & s) {
    /* gathers sales for 4 quarters interactively, stores them
       in the sales member of s and computes and stores the
       average, maximum, and minimum values */
        double salesStore[QUARTERS];
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << "Enter Quarter #" << i+1 << ": ";
            std::cin  >> salesStore[i];
        }
        setSales(s, salesStore, QUARTERS);
    }
    void showSales(const Sales & s) {
    /* display all information in structure s */
        std::cout << "Sales Records: ";
        for (int i = 0; i < QUARTERS; i++)
            std::cout << s.sales[i] << " ";
        std::cout << "\nMax: " << s.max
                  << "\nMin: " << s.min
                  << "\nAverage: " << s.average
                  << "\n";
    }
}

