// Use the valarray

#include <iostream>
#include <valarray>
#include <vector>
#include <iomanip>

int main() {
    double temp;
    std::vector<double> input;
    while (std::cin >> temp && temp > 0)
        input.push_back(temp);
    std::sort(input.begin(), input.end());

    int inputSize = input.size();
    std::valarray<double> numbers (input.data(), inputSize);
    std::valarray<double> sqrt_arr(inputSize), result(inputSize);

    sqrt_arr = numbers.apply(sqrt);
    result = numbers + 2.0 * sqrt_arr;

    std::cout.setf(std::ios_base::fixed);
    std::cout.precision(4);

    std::for_each(std::begin(result), std::end(result), [] (double num) {
            std::cout << num << ' ';
        });
    std::cout.put('\n');

    for (int i = 0; i < inputSize; i++) {
        std::cout << std::setw(8) << std::left << numbers[i] << ": "
                  << result[i] << '\n';
    }

    return 0;
}

