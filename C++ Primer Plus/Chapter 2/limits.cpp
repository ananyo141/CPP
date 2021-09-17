// Print the size limits of the different datatypes
#include <iostream>
#include <climits>

int main() {
    using namespace std;
    int n_int = INT_MAX;            // max int value
    short n_short = SHRT_MAX;       // max short value
    long n_long = LONG_MAX;         // max long value
    long long n_llong = LLONG_MAX;  // max long long value

    // sizeof to get size of type of variable
    cout << "int is " << sizeof(int) << " bytes.\n"; 
    cout << "short is " << sizeof n_short << " bytes.\n";
    cout << "long is " << sizeof n_long << " bytes.\n";
    cout << "long long is " << sizeof n_llong << " bytes.\n";
    cout << endl;

    // maximum values
    cout << "Maximum values:\n";
    cout << "int: " << n_int << endl;
    cout << "short: " << n_short << endl;
    cout << "long: " << n_long << endl;
    cout << "long long: " << n_llong << endl;

    // minimum values
    cout << "Minimum int value: " << INT_MIN << endl;
    cout << "Bits per byte: " << CHAR_BIT << endl;

    return 0;
}
