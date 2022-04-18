#include <iostream>
#include <string>
#define printStr(elem) std::cout << #elem << " = " << elem << '\n'

/*
 * Specialized Ctors:-
 * Size-char ctor
 * Iterator ctor
 * String slice ctor
 * Literal-upto ctor
 */

int main() {
    using std::string;

    string one;
    one = "Lottery Winner!";
    printStr(one);

    // size-char ctor
    string two(20, '$');             // str of len 20 filled with '$' char
    printStr(two);

    string three(one);
    three += " Oops!";
    printStr(three);

    // literal-upto ctor
    char literal[] = "All's well that ends well";
    string four(literal, 20);        // literal slicing
    printStr(four);

    two = "Sorry that was ";
    one[0] = 'P';
    string five = two + one;
    printStr(five);

    string six(&five[3], &five[8]); // iterator ctor
    string seven(five, 3, 5);       // string object slicing
    printStr(six);
    printStr(seven);
    std::cout << std::boolalpha;
    printStr((six == seven));

    return 0;
}

