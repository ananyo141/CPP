// Calculate the mileage of car in litres per 100 kilometres
#include <iostream>

int main() {
    using namespace std;

    unsigned long distance;
    unsigned litres;

    cout << "Enter the distance in kilometres: ";
    cin >> distance;

    cout << "Enter the petrol in litres consumed: ";
    cin >> litres;

    cout << "You car has mileage: " << (litres / double(distance)) * 100 
         << " litres/100km\n";

    return 0;
}
