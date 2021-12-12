/* Define a complex class so that the following program can use it with correct
results: */

#include <iostream>

class Complex {
private:
    double real_;
    double img_;
public:
    Complex() {      // default constructor
        real_ = img_ = 0.0;
    }

    Complex(double real, double img) {
        real_ = real;
        img_  = img;
    }

    ~Complex() { }   // default destructor

    Complex operator~() const {
        return Complex(real_, -img_);
    }

    Complex operator+(const Complex &n1) const {     // complex addition
        return Complex(real_+n1.real_, img_+n1.img_);
    }

    Complex operator-(const Complex &n1) const {     // complex substraction
        return Complex(real_-n1.real_, img_-n1.img_);
    }

    Complex operator*(const Complex &n1) const {              // multiply two complex (a+bi)(c+di)
        double realPart = (real_*n1.real_) - (img_*n1.img_ ); // Real: (ac-bd)
        double imgPart  = (real_*n1.img_ ) + (img_*n1.real_); // Img:  (ad+bc)i
        return Complex(realPart, imgPart);
    }

    friend Complex operator*(double scalar, const Complex &obj) {  // scalar multiplication
        return Complex(scalar*obj.real_, scalar*obj.img_);
    }

    friend Complex operator*(const Complex &obj, double scalar) {  // reverse order; calls the
        return scalar * obj;                                       // scalar multiplication
    }

    friend std::ostream &
        operator<<(std::ostream &os, const Complex &obj) {
        os << '(' << obj.real_ << ',' << obj.img_ << "i)";
        return os;
    }

    friend std::istream &
        operator>>(std::istream &is, Complex &obj) {
        double tempReal, tempImg;
        std::cout << "Real: ";
        is >> tempReal;
        std::cout << "Img:  ";
        is >> tempImg;
        obj = Complex(tempReal, tempImg);
        return is;
    }
};

int main() {
    Complex a(3, 4), c;

    for (;;) {
        std::cout << "Enter a complex number (q to quit):\n";
        if (!(std::cin >> c)) break;
        std::cout << "\nC is: " << c << '\n'
                  << "Complex Conjugate is: " << ~c << '\n'
                  << "A is: " << a << '\n';
        std::cout << a << " + " << c << " is " << a + c << '\n'
                  << a << " - " << c << " is " << a - c << '\n'
                  << a << " * " << c << " is " << a * c << '\n'
                  << "2 * " << c << " is " << 2 * c << "\n\n";
    }
    std::cout << "\n\nDone!\n";

    return 0;
}

