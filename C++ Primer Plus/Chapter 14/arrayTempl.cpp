// Implementation file for arrayTempl.hpp

/*
Create a 2d array containing this matrix and find sum
and average
  1  2  3  4  5 : sum =  14, average = 1.5
  2  4  6  8 10 : sum =  30, average = 3
  3  6  9 12 15 : sum =  45, average = 4.5
  4  8 12 16 20 : sum =  60, average = 6
  5 10 15 20 25 : sum =  75, average = 7.5
  6 12 18 24 30 : sum =  90, average = 9
  7 14 21 28 35 : sum = 105, average = 10.5
  8 16 24 32 40 : sum = 120, average = 12
  9 18 27 36 45 : sum = 135, average = 13.5
 10 20 30 40 50 : sum = 150, average = 15
*/
#include <iostream>
#include <iomanip>
#include "arrayTempl.hpp"
const int MAT_HEIGHT = 10;
const int MAT_WIDTH  = 5;

int main() {
    int i, j, k, sum;
    arr::Array<arr::Array<int, MAT_WIDTH>, MAT_HEIGHT> matrix;

    // Create the Matrix
    for (i = 0; i < MAT_HEIGHT; i++)
        for (j = 0, k = i+1; j < MAT_WIDTH; j++, k += i+1)
            matrix[i][j] = k;

    // Display Matrix
    const int widthPerNum = 3;
    for (i = 0; i < MAT_HEIGHT; i++) {
        sum = 0;
        for (j = 0; j < MAT_WIDTH; j++) {
            std::cout << std::right << std::setw(widthPerNum) << matrix[i][j] << ' ';
            sum += matrix[i][j];
        }
        std::cout << " : sum = " << std::right << std::setw(widthPerNum) 
                  << sum << ", average = " <<  double(sum) / MAT_WIDTH << '\n';
    }
    return 0;
}

