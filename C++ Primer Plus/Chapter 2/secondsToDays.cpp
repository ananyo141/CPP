// Convert given seconds to days, hours, mins and seconds
#include <iostream>
const char SECS_TO_MIN  (60);
const char MINS_TO_HOUR (60);
const char HOURS_TO_DAY (24);

int main() {
    using namespace std;

    long long seconds;
    cout << "Enter the number of seconds: ";
    cin >> seconds;
    cout << seconds << " seconds = ";

    unsigned short days = seconds / (SECS_TO_MIN * MINS_TO_HOUR * HOURS_TO_DAY);

    return 0;
}
