// Simulate the Plodson case
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stackTemp.hpp"
const int NUM_FILES = 10;

int main() {
    stack::Stack<const char *> in_basket;   // processing counter of Plodson
    // Store the static character pointers, (thereby creating them)
    const char *in_box[NUM_FILES] = {       // file cabinet of office
        "1. Hank Gilgamesh",  "2. Kiki Ishtar",
        "3. Betty Rocker",    "4. Ian Flagranti",
        "5. Wolfgang Kibble", "6. Portia Koop",
        "7. Joy Almondo",     "8. Xaverie Paprika",
        "9. Juan Moore",      "10. Misha Mache"
    };
    const char *out_box[NUM_FILES];         // files that are processed
    std::srand(std::time(0));

    int inb_i = 0, outb_i = 0;
    while (inb_i < NUM_FILES) {
        // If inbasket is empty, place one from counter
        if (in_basket.isempty())
            in_basket.push(in_box[inb_i++]);
        // if inbasket is full, take one out and process
        else if (in_basket.isfull())
            in_basket.pop(out_box[outb_i++]);
        // if inbetween, toss to do which one
        else if (std::rand() % 2 < 1)
            in_basket.pop(out_box[outb_i++]);
        else
            in_basket.push(in_box[inb_i++]);
    }
    while (!in_basket.isempty())
            in_basket.pop(out_box[outb_i++]);

    for (int i = 0; i < outb_i; i++)
        std::cout << out_box[i] << '\n';

    return 0;
}

