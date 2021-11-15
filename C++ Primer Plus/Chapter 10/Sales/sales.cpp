#include <iostream>
#include "sales.h"

namespace SALES {
    Sales::Sales() {
        salesItem salesStore[QUARTERS];
        for (int i = 0; i < QUARTERS; i++) {
            std::cout << "Enter Quarter #" << i+1 << ": ";
            std::cin  >> salesStore[i];
        }
        *this = Sales(salesStore, QUARTERS);
    }
    Sales::Sales(const salesItem ar[], int n) {
        salesItem max, min, total = 0;
        max = min = ar[0];
        for (int i = 0; i < QUARTERS; i++) {
            sales_[i] = i<n ? ar[i] : 0;
            if (sales_[i] < min) min = sales_[i];
            if (sales_[i] > max) max = sales_[i];
            total += sales_[i];
        }
        max_ = max;
        min_ = min;
        average_ = total / float(QUARTERS);
    }
    void Sales::showSales() const {
        std::cout << "Sales Records: ";
        for (int i = 0; i < QUARTERS; i++) 
            std::cout << sales_[i] << " ";
        std::cout << "\nMax: " << max_
                  << "\nMin: " << min_
                  << "\nAverage: " << average_
                  << "\n";
    }
}

