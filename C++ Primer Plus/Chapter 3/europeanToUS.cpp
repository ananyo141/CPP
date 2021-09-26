/* Write a program that asks you to enter an automobile gasoline consumption figure
in the European style (liters per 100 kilometers) and converts to the U.S. style of
miles per gallon. Note that in addition to using different units of measurement, the
U.S. approach (distance / fuel) is the inverse of the European approach (fuel / dis-
tance). Note that 100 kilometers is 62.14 miles, and 1 gallon is 3.875 liters.Thus, 19
mpg is about 12.4 l/100 km, and 27 mpg is about 8.7 l/100 km. */

#include <iostream>
const float LITR_TO_GALLON (0.258f);
const float HUND_KILOMETER_TO_MILES (62.14f);

double euroToUSMileage(double euroMileage) {
    double gallons = euroMileage * LITR_TO_GALLON;
    return 1 / (gallons / HUND_KILOMETER_TO_MILES);
}

int main() {
    using namespace std;

    double euroLitres;
    cout << "Enter litres per 100 kilometres: ";
    cin >> euroLitres;
    double usUnits = euroToUSMileage(euroLitres);

    cout << "The US mileage is " << usUnits << " miles per gallon.\n";

    return 0;
}
