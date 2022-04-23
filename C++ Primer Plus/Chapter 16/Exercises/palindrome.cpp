// Create a predicate function that tests if a given string is
// a palindrome or not

#include <iostream>
#include <cctype>
#include <algorithm>
#include <iterator>

bool isPalindrome(const std::string &str);

int main() {
    std::string input;
    for (;;) {
        std::cout << "Enter string (quit to quit): ";
        std::cin >> std::ws;
        getline(std::cin, input);
        if (input == "quit") break;
        std::cout << '`' << input << "` is "
                  << (isPalindrome(input) ? "" : "not ") 
                  << "a palindrome\n";
        }
}

bool isPalindrome(const std::string &str) {
    std::string normStr, reverseStr;
    std::remove_copy_if(str.cbegin(), str.cend(), 
            std::back_insert_iterator<std::string> (normStr), 
            [] (char ch) {
                return ispunct(ch) || isspace(ch);
        });
    std::transform(normStr.cbegin(), normStr.cend(), normStr.begin(), tolower);
    std::reverse_copy(normStr.cbegin(), normStr.cend(), 
            std::back_insert_iterator<std::string> (reverseStr));
    return normStr == reverseStr;
}

