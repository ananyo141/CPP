
#include <iostream>
#include <sstream>

int main() {
    std::string word;
    std::string sentence = "It was a dark and stromy day, and "
                           "the full moon glowed brilliantly. ";
    std::istringstream instream(sentence);
    while (instream >> word)
        std::cout << word << '\n';

    return 0;
}
