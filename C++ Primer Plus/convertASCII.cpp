// Convert an entered character to it's ASCII value
#include <iostream>

int main() {
    using namespace std;

    char ch;
    cout << "Enter the character: ";
    cin >> ch;
    cout << "The ASCII value for '" << ch << "' is: " << (int) ch << endl
         << "Adding 1 to the value...\n"
            "The ASCII character for value " << (int) ++ch << " is: ";
    cout.put(ch) << endl;

    return 0;
}
