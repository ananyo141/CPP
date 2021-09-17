// Convert given seconds to days, hours, mins and seconds
#include <iostream>
const char SECS_TO_MIN  (60);
const char MINS_TO_HOUR (60);
const char HOURS_TO_DAY (24);

int main() {
    using namespace std;

    long long num_seconds;
    cout << "Enter the number of seconds: ";
    cin >> num_seconds; 
    cout << num_seconds << " seconds = ";

    unsigned short days    = num_seconds / (SECS_TO_MIN * MINS_TO_HOUR * HOURS_TO_DAY);
    num_seconds -= days * (SECS_TO_MIN * MINS_TO_HOUR * HOURS_TO_DAY);
    unsigned short hours   = num_seconds / (SECS_TO_MIN * MINS_TO_HOUR);
    num_seconds -= hours * (SECS_TO_MIN * MINS_TO_HOUR);
    unsigned short mins    = num_seconds / (SECS_TO_MIN);
    num_seconds -= mins * SECS_TO_MIN;

    cout << days << " days, " << hours << " hours, "
         << mins << " mins, " << num_seconds << " seconds.\n";

    return 0;
}
