#include <iostream>

int main() {
    std::cout.fill('*');
    const char *staff[] = { "Waldo Whipsnade", "Wilmarie Wooper" };
    long bonus[] = { 900, 1350 }; 
    const unsigned staffsize = (sizeof(staff) / sizeof(staff[0]));
    static_assert ( staffsize == (sizeof(bonus) / sizeof(bonus[0])), 
            "staffsize should be equal to the staff bonus length");

    for (int i = 0; i < staffsize; i++) {
        std::cout << staff[i] << ": $";
        std::cout.width(8);
        std::cout << bonus[i] << '\n';
    }

    return 0;
}

