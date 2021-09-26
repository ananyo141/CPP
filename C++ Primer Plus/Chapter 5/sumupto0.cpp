/***********************************************************************************
3. Write a program that asks the user to type in numbers.After each entry, the pro-
gram should report the cumulative sum of the entries to date.The program should
terminate when the user enters 0.
************************************************************************************/
#include <iostream>

int main() {
    using namespace std;
    double num, sum = 0;
    do {
        cout << "Enter number: ";
        cin >> num;
        sum += num;
    } while (num != 0);

    cout << "The sum of the numbers is " << sum << endl;

    return 0;
}
