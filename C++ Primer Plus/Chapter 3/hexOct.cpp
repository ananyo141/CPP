// Use hex and oct manipulators to display hex and oct values
#include <iostream>

int main() {
    using namespace std;
    int chest = 42;     // decimal integer literal
    int waist = 042;    // octal integer literal
    int inseam = 0x42;  // hexadecimal integer literal

    cout << hex;
    cout << "(hex) Chest: " << chest << endl;
    cout << dec;
    cout << "(dec) Waist: " << waist << endl;
    cout << oct;
    cout << "(oct) Inseam: " << inseam << endl;
    
    return 0;
}
