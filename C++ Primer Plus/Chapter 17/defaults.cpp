#include <iostream>
#define PRINT(expr) std::cout << "(" #expr ")" << " = " << (expr) << '\n'

int main() {
    const char *numbers = "12345678901234567890";
    char ch = 'K';
    int num1 = 273;
    PRINT(numbers) << '\n';
    std::cout.put(ch).put('\n');
    PRINT(num1);
    PRINT(-num1) << '\n';

    double f1 = 1.200;
    PRINT(f1);
    PRINT(f1 + 1.0 / 9.0);

    double f2 = 1.67E2;
    std::cout.setf(std::ios_base::uppercase);
    PRINT(f2);
    f2 += (1.0 / 9);
    PRINT(f2);
    PRINT(f2 * 1.0e4);

    // std::cout << std::hex;
    std::cout.setf(std::ios_base::hex, std::ios_base::basefield);

    double f3 = 2.3e-4;
    PRINT(f3);
    PRINT(f3 / 10);

    return 0;
}

