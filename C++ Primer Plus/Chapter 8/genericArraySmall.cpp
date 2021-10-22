/* 6. Write a template function maxn() that takes as its arguments an array of items of
type T and an integer representing the number of elements in the array and that
returns the largest item in the array.Test it in a program that uses the function tem-
plate with an array of six int value and an array of four double values.The pro-
gram should also include a specialization that takes an array of pointers-to-char as
an argument and the number of pointers as a second argument and that returns the
address of the longest string. If multiple strings are tied for having the longest
length, the function should return the address of the first one tied for longest.Test
the specialization with an array of five string pointers. */

#include <iostream>
#include <cstring>
#define ArrLen(array) (sizeof(array)/sizeof(array[0]))

// prototypes //
template<typename T>
T smallVal(T array[], unsigned limit);
template<> const char *smallVal(const char *array[], unsigned limit);

int main() {
    int intArr[] = {3, 1, 6, 5, 3, 7, 10, 9};
    double doubArr[] = {3.3, 1.1, 6.6, 5.5, 3.3, 7.7, 10.10, 9.9};
    const char *strArr[] = {"Okay, this is nice",
                            "How are you doing mister?",
                            "This is to say to you, you're nice!",
                            "Me and my pup <3"};
    std::cout << "Smallest of ints: "      << smallVal(intArr,  ArrLen(intArr))
              << "\nSmallest of doubles: " << smallVal(doubArr, ArrLen(doubArr))
              << "\nSmallest of strings: " << smallVal(strArr,  ArrLen(strArr)) << "\n";

    return 0;
}

template<typename T>
T smallVal(T array[], unsigned limit) {
    T smallest = array[0];
    for (int i = 0; i < limit; i++)
        if (array[i] < smallest) smallest = array[i];
    return smallest;
}
template<> // explicit specialization of the previous template
const char *smallVal(const char *array[], unsigned limit) { // array is (char **)
    const char *smallest = *array;  // the first element array[0] (pointer-to-char)
    for (const char **ptr = array; ptr < array + limit; ptr++) 
        if (strlen(*ptr) < strlen(smallest))
            smallest = *ptr;
    return smallest;
}
