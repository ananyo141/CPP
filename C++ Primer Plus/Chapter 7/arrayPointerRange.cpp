/*
7. Redo Listing 7.7, modifying the three array-handling functions to each use two
pointer parameters to represent a range.The fill_array() function, instead of
returning the actual number of items read, should return a pointer to the location
after the last location filled; the other functions can use this pointer as the second
argument to identify the end of the data.
*/
#include <iostream>
const int MAX = 5;

// prototypes //
double *fill_array(double *start, int maxlimit);
void show_array(const double *start, const double *end);
void revalue(double *start, double *end, float factor);

int main() {
    double revalueF, array[MAX];
    double *upperBound = fill_array(array, MAX);
    show_array(array, upperBound);
    std::cout << "Enter revaluation factor: ";
    std::cin  >> revalueF;
    revalue(array, upperBound, revalueF);
    show_array(array, upperBound);

    return 0;
}

double *fill_array(double *start, int maxlimit) {
    /* fill the given array starting from pointer 'start' upto the first
    non-numeric input or max elements limit, whichever comes first */
    for (double *ptr = start; ptr < start + maxlimit; ptr++) {
        std::cout << "Enter value #" << ptrdiff_t(ptr - start) + 1 << ": ";
        std::cin  >> *ptr;
        if (*ptr < 0) return ptr;   // handle negative input
        if (!std::cin) {            // handle non-numeric input
            std::cin.clear();
            while (std::cin.get() != '\n') ;
            return ptr;
        }
    }
    return start + maxlimit;
}

void show_array(const double *start, const double *end) {
    /* Display the properties array */
    for (const double *ptr = start; ptr < end; ptr++) 
        std::cout << "Property #" << ptrdiff_t(ptr - start) + 1 
                  << ": $" << *ptr << '\n';
}

void revalue(double *start, double *end, float factor) {
    /* revalue all the property values by multiplying with a factor */
    while (start < end)
        *start++ *= factor;
}
