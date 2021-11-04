/* 3. Begin with the following structure declaration:

Write a program that uses placement new to place an array of two such structures in
a buffer.Then assign values to the structure members (remembering to use
strcpy() for the char array) and use a loop to display the contents. Option 1 is to
use a static array, like that in Listing 9.10, for the buffer. Option 2 is to use regular
new to allocate the buffer. */

#include <iostream>
#include <new>
#include <cstring>
const int STR_ARR  = 2;
const int ARR_SIZE = 60;
const int BUFFER_SIZE = 500;

namespace {                                         // an unnamed namespace to keep
    typedef unsigned char BYTE;                     // global contents internally linked

    struct chaff {
        char dross[ARR_SIZE];
        int slag;
    };

    // create buffers
    BYTE buffer1[BUFFER_SIZE];                       // using array allocation
    BYTE *buffer2 = new BYTE[BUFFER_SIZE];           // using dynamic allocation
    const char *strCounter[] = {"First", "Second"};
}

void displayStrArr(chaff arr[], int len);

int main() {
    // Use placement new to place an array of two structs in each buffer
    // Allocating memory for array of two structs in two buffers each
    chaff *arr1 = new(buffer1) chaff[STR_ARR];
    chaff *arr2 = new(buffer2) chaff[STR_ARR];
    chaff *arrOfArr[] = {arr1, arr2};
    
    strcpy(arr1[0].dross, "First Buffer First Str");
    arr1[0].slag = 0;
    strcpy(arr1[1].dross, "First Buffer Second Str");
    arr1[1].slag = 1;
    strcpy(arr2[0].dross, "Second Buffer First Str");
    arr2[0].slag = 2;
    strcpy(arr2[1].dross, "Second buffer Second Str");
    arr2[1].slag = 3;

    std::cout.width(20);
    std::cout << "First buffer:\n";
    displayStrArr(arr1, STR_ARR);
    std::cout.width(20);
    std::cout << "Second buffer:\n";
    displayStrArr(arr2, STR_ARR);

    // cleanup handler
    delete [] buffer2;  // can't delete pointer from placement new as
                        // it was not collected from heap by regular new

    return 0;
}

void displayStrArr(chaff arr[], int len) {
    for (int i = 0; i < len; i++) 
        std::cout << "#" << i + 1 
                  << "\nDross: " << arr[i].dross
                  << "\nSlag:  " << arr[i].slag 
                  << "\n\n";
}

