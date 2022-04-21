// Create a valarray of 4x3 matrix
// Fill up with random numbers
// extract 2nd column
// extract 2nd row
// assign 10 to last column
// first column is sum of next two

#include <iostream>
#include <valarray>
#include <cstdlib>
#include <ctime>
#include <iomanip>
const int ROW = 4;
const int COL = 3;
const int MATSIZ = ROW * COL;
const int RANDUPPER = 20;

template <typename T>
static void printContMatrix(const std::valarray<T> &, int = 1);

int main() {
    std::srand(std::time(0));
    std::valarray<int> contMatrix(MATSIZ);

    // Fill up with random numbers
    for (int i = 0; i < MATSIZ; i++)
        contMatrix[i] = std::rand() % RANDUPPER;
    std::cout << "Generated matrix:\n";
    printContMatrix(contMatrix, COL);

    // extract 2nd column
    int col_extract = 2;
    std::valarray<int> col_2 (contMatrix[std::slice(col_extract - 1, ROW, COL)]);
    std::cout << col_extract << " column:\n";
    printContMatrix(col_2);

    // extract 2nd row
    int row_extract = 2;
    std::valarray<int> row_2 (contMatrix[std::slice(COL * (row_extract-1), COL, 1)]);
    std::cout << row_extract << " row:\n";
    printContMatrix(row_2, COL);

    // assign 10 to last column
    contMatrix[std::slice(COL-1, ROW, COL)] = 10;
    std::cout << "Assigned 10 to last column:\n";
    printContMatrix(contMatrix, COL);

    // first column is sum of next two
    using valint = std::valarray<int>;
    contMatrix[std::slice(0, ROW, COL)] = valint(contMatrix[std::slice(1, ROW, COL)]) +
        valint(contMatrix[std::slice(2, ROW, COL)]);
    std::cout << "First column is sum of next two:\n";
    printContMatrix(contMatrix, COL);

    return 0;
}

template <typename T>
void printContMatrix(const std::valarray<T> &mat, int col) {
    int i, size = mat.size();
    for (i = 0; i < size; i++) {
        std::cout << std::setw(3) << mat[i];
        std::cout << (i % col == col-1 ? '\n' : ' ');
    }
    if (i % col == col-1)
        std::cout.put('\n');
}

