// This program demonstrates the overflow and underflow of data 
// due to assignment to out of range values
#include <iostream>
#include <climits>
#define ZERO 0

using std::cout;
using std::endl;

void displayAccounts(int sam, int sue) {
    cout << "Sam has " << sam << " dollars and Sue has " << sue
         << " dollars deposited." << endl;
}

int main() {
    short sam = SHRT_MAX;            // initializing to max value
    unsigned short sue = SHRT_MAX;   // initializing to max value

    displayAccounts(sam, sue);
    cout << "Add $1 to each account." << endl << "Now ";

    sam++;
    sue++;

    displayAccounts(sam, sue);
    cout << "Poor Sam!" << endl;

    sam = ZERO;
    sue = ZERO;

    displayAccounts(sam, sue);
    cout << "Take $1 from each account." << endl << "Now ";

    sam--;
    sue--;

    displayAccounts(sam, sue);
    cout << "Lucky Sue!" << endl;

    return 0;
}
