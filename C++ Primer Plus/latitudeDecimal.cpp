// Convert latitude in degree, minutes and seconds to decimal format.
#include <iostream>
const float SEC_TO_MIN = 60.0f;
const float MIN_TO_DEG = 60.0f;

int main() {
    using namespace std;

    unsigned short degree, minute, second;
    cout << "Enter a latitude in degrees, minutes, and seconds: \n"
            "First, enter the degrees: ";
    cin >> degree;
    cout << "Next, enter the minutes of arc: ";
    cin >> minute;
    cout << "Finally, enter the seconds of arc: ";
    cin >> second;

    double decimalDegrees = degree + (minute + (second / SEC_TO_MIN)) 
                                       / MIN_TO_DEG;

    cout << degree << " degrees, " << minute << " minutes, " << second
         << " seconds = " << decimalDegrees << " degrees" << endl;

    return 0;
}
