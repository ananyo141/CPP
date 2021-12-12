#include <iostream>
#include "timeClass.h"
int main()
{
    using std::cout;
    using std::endl;
    using TIME::Time;
    Time weeding(4, 35);
    Time waxing(2, 47);
    Time total;
    Time diff;
    Time adjusted;
    cout << "weeding time = ";
    weeding.show();
    cout << endl;
    cout << "waxing time = ";
    waxing.show();
    cout << endl;
    cout << "total work time = ";
    total = weeding + waxing;
    // use operator+()
    total.show();
    cout << endl;
    diff = weeding - waxing;
    // use operator-()
    cout << "weeding time - waxing time = ";
    diff.show();
    cout << endl;
    adjusted = total * 1.5;
    // use operator+()
    cout << "adjusted work time = ";
    adjusted.show();
    cout << endl;
    return 0;
}

