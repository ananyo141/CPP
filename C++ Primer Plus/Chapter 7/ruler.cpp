// Create a ruler using recursion
#include <iostream>
const int LEN = 66;
const int DIVS = 6;

// prototype //
void subdivide(char arr[], int high, int low, int level);

int main() {
    char ruler[LEN];
    for (int i = 1; i < LEN-2; i++)
        ruler[i] = ' ';
    ruler[LEN - 1] = '\0';
    int max = LEN-2, min = 0;
    ruler[max] = ruler[min] = '|';

    // make 6 versions of the ruler with 6 levels of divisions
    for (int i = 1; i <= DIVS; i++) {
        subdivide(ruler, max, min, i);
        std::cout << ruler << std::endl;
        for (int j = 1; j < LEN-2; j++) // reset the ruler for next version
            ruler[j] = ' ';
    }

    return 0;
}

void subdivide(char arr[], int high, int low, int level) {
    /* Divide the ruler array by halving into subdivisions until and
    deduct level at every step, so recursion terminates at level 0 */
    if (level == 0) return;
    int mid = (high + low) / 2;
    arr[mid] = '|';
    subdivide(arr, high, mid, level - 1);
    subdivide(arr, mid, low, level - 1);
}
