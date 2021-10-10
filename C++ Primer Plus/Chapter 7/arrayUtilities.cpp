/*
6. Write a program that uses the following functions:
Fill_array() takes as arguments the name of an array of double values and an
array size. It prompts the user to enter double values to be entered in the array. It
ceases taking input when the array is full or when the user enters non-numeric
input,and it returns the actual number of entries.
Show_array() takes as arguments the name of an array of double values and an
array size and displays the contents of the array.
Reverse_array() takes as arguments the name of an array of double values and an
array size and reverses the order of the values stored in the array.
The program should use these functions to fill an array, show the array, reverse the
array, show the array, reverse all but the first and last elements of the array,and then
show the array.
*/

#include <iostream>
const int MAXLEN = 5;

// prototypes //
int fill_array(double array[], int maxlen);
void show_array(const double array[], int size);
void reverse_array(double array[], int size);

int main() {
    double array[MAXLEN];
    int len = fill_array(array, MAXLEN);
    std::cout << "\nUser input: ";
    show_array(array, len);
    std::cout << "Reversing the array: ";
    reverse_array(array, len);
    show_array(array, len);
    std::cout << "Reversing the array, this time "
                 "\nkeeping first and last element same: ";
    reverse_array(array + 1, len - 2);
    show_array(array, len);

    return 0;
}

int fill_array(double array[], int maxlen) {
    /* Fill the array with user input and return number of values stored;
    stop at the first occurrence of non-numerical input or before maxlen,
    whichever comes first */

    for (int i = 0; i < maxlen; i++) {
        std::cout << "Enter array[" << i << "] value: ";
        std::cin  >> array[i];
        if (!std::cin) {
            std::cin.clear();
            return i;
        }
    }
    return maxlen;
}

void show_array(const double array[], int size) {
    /* Print out the given array sequentially */
    for (int i = 0; i < size; i++)
        std::cout << ' ' << array[i];
    std::cout << std::endl;
}

void reverse_array(double array[], int size) {
    /* Reverse the array */
    double temp;
    for (int i = 0; i < size && i < size/2; i++) {
        temp = array[i];
        array[i] = array[size-i-1];
        array[size-i-1] = temp;
    }
}
