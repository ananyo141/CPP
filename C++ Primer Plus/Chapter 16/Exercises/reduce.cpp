// Reduce a given array

#include <iostream>
#include <algorithm>

template <typename T>
int reduce(T arr[], int n);

template <typename T>
void showArr(T arr[], int n);

int main() {
    std::cout << "Testing for int\n";
    int arr[] = {1, 3, 3, 4, 1, 3, 4, 1};
    int len = sizeof(arr) / sizeof(arr[0]);
    showArr(arr, len);

    len = reduce(arr, len);
    showArr(arr, len);

    std::cout << "\nTesting for string\n";
    std::string arr2[] = {"this", "that", "this", "ok", "that", "ok"};
    int len2 = sizeof(arr2) / sizeof(arr2[0]);
    showArr(arr2, len2);

    len2 = reduce(arr2, len2);
    showArr(arr2, len2);

    return 0;
}

template <typename T>
int reduce(T arr[], int n) {
    std::sort(arr, arr + n);
    return std::unique(arr, arr + n) - arr; // new length
}

template <typename T>
void showArr(T arr[], int n) {
    for (int i = 0; i < n; i++)
        std::cout << arr[i] << ' ';
    std::cout.put('\n');
}

