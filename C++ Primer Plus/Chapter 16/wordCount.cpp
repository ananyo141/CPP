// Give frequency of words entered

#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <iterator>
#include <cctype>

template <typename T>
static void showContainer(T container) {
    for_each(container.cbegin(), container.cend(), [] (typename T::value_type x) {
            std::cout << x << ' ';
        });
    std::cout.put('\n');
}

static std::string toLower (const std::string &str) {
    /* Convert a string to lowercase */
    std::string temp;
    transform(str.cbegin(), str.cend(), 
              std::back_insert_iterator<std::string> (temp), 
              tolower);
    return temp;
}

int main() {
    std::vector<std::string> words;
    std::string temp;
    std::cout << "Enter words:\n";
    // input text from user
    while (std::cin >> temp && temp != "quit")
        words.push_back(temp);

    // convert to lowercase
    std::transform(words.begin(), words.end(), words.begin(), toLower);

    std::cout << "You entered words:\n";
    showContainer(words);

    // create ordered set
    std::set<std::string> orderedWords;
    std::copy(words.cbegin(), words.cend(),
            std::insert_iterator<std::set<std::string>> (orderedWords, orderedWords.begin()));
    std::cout << "Alphabetically sorted words:\n";
    showContainer(orderedWords);

    // create frequency map object
    std::map<std::string, int> wordFreq;
    for (const auto &word: orderedWords)
        wordFreq[word] = std::count(words.cbegin(), words.cend(), word);

    // print results
    std::cout << "Word Frequency:\n";
    for_each(wordFreq.cbegin(), wordFreq.cend(), [] (const std::pair<std::string, int> &item) {
                std::cout << item.first << ": " << item.second << '\n';
            });
    std::cout.put('\n');

    return 0;
}

