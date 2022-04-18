#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

static void showWords(const std::vector<std::string> &words) {
    std::cout << "Words:\n";
    for (const auto &word: words)
        std::cout << word << ' ';
    std::cout.put('\n');
}

int main() {
    const std::string s1[] = {"fine", "fish", "fashion", "fate"};
    const std::string s2[] = {"busy", "bats"};     // insert back
    const std::string s3[] = {"silly", "singers"}; // insert at front

    std::vector<std::string> words(s1, s1 + (sizeof(s1) / sizeof(s1[0])));
    showWords(words);
    std::copy(s2, s2 + (sizeof(s2) / sizeof(s2[0])),
            std::back_insert_iterator<std::vector<std::string>> (words));
    showWords(words);
    std::copy(s3, s3 + (sizeof(s3) / sizeof(s3[0])),
            std::insert_iterator<std::vector<std::string>> (words, words.begin()));
    showWords(words);

    return 0;
}

