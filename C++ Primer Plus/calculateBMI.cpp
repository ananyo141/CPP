// Calculate the BMI using height and weight
#include <iostream>
const int FEET_TO_INCHES = 12;
const float INCH_TO_METERS = 0.0254f;
const float KG_TO_POUNDS = 2.2f;


int main() {
    using namespace std;
    
    unsigned short heightFeet, heightIn;
    unsigned short weightPounds;

    cout << "Your height in feet: __\b\b";
    cin >> heightFeet;
    cout << "Your height in inches: __\b\b";
    cin >> heightIn;
    cout << "Your weight in pounds: ___\b\b\b";
    cin >> weightPounds;

    heightIn = (heightFeet * FEET_TO_INCHES) + heightIn;
    float heightMeter = heightIn * INCH_TO_METERS;
    float weightKg = weightPounds / KG_TO_POUNDS;

    float BMI = weightKg / (heightMeter * heightMeter);

    cout << "Your BMI is: " << BMI << endl;
    
    return 0;
}
