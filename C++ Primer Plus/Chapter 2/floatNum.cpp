// floating point types
#include <iostream>
#include <cfloat>

int main() {
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);   // fixed point

    int sig_digits_double = DBL_DIG;
    int sig_digits_float  = FLT_DIG;
    int sig_digits_long   = LDBL_DIG;
    
    float tub = 10.0 / 3.0;         // 6 significant 
    double mint = 10.0 / 3.0;       // 15 significant
    const float million = 1.0e6;

    cout << "tub = " << tub;
    cout << ", a million tubs = " << million * tub;
    cout << ",\nand ten million tubs = ";
    cout << 10 * million * tub << endl;

    cout << "mint = " << mint;
    cout << " and a million mints = " << million * mint << endl;

    cout << "\nDouble significant digits: "    << sig_digits_double << endl;
    cout << "Float significant digits: "       << sig_digits_float << endl;
    cout << "Long Double significant digits: " << sig_digits_long << endl;

    return 0;
}
