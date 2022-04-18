// Use String reserve and capacity

#include <iostream>
#include <algorithm>
#define debug(elem) std::cerr << #elem << " = " << elem << '\n'

int main() {
    std::string one, two;

    debug(one.size());
    debug(one.capacity());
    one = "A quick brown fox jumps over the lazy dog";
    debug(one.size());
    debug(one.capacity());

    two.reserve(50);
    debug(two.capacity());
    for(int i = 0; i < 101; i++)
        two += std::to_string(i);
    debug(two.size());
    debug(two.capacity());

    std::string strarr[30];
    std::cout << "\nArray String element capacities:\n";
    for_each(strarr, strarr + 5, [](const std::string &str) {
            debug(str.capacity()); 
        });

    return 0;
}

