#include <iostream>

struct Big {
    double stuff[200000];
};

int main() {
    Big *ptr;
    try {
        ptr = new Big[10000];
    } catch (std::bad_alloc &exc) {
        std::cerr << "Caught exception:\n" << exc.what() << '\n';
    }

    return 0;
}
