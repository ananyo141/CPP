// Class declaration file for Vector

#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>
#include <cmath>

namespace VECTOR {
    const double RAD_TO_DEG = 45.0 / atan(1.0);     // tan-1(1)rad is 45 deg

    class Vector {
    public:
        enum Mode {RECT, POL};
    private:
        double x_;
        double y_;
        // Generate Polar Values on the fly instead
        // of keeping and updating both fields
        Mode mode_;
        void checkmode(Mode mode);  // a private method that
    public:                         // checks the mode entered
        Vector();
        Vector(double arg1, double arg2, Mode mode=RECT);
        ~Vector();
        void reset(double arg1, double arg2, Mode mode=RECT);
        void polar_mode();
        void rect_mode();
        double get_x() const  {return x_;}
        double get_y() const  {return y_;}
        double get_mag()   const;  
        double get_angle() const; 
        operator double()  const;
        Vector operator+(const Vector &v2) const;
        Vector operator-(const Vector &v2) const;   // binary '-'
        Vector operator-() const;                   // unary  '-'
        Vector operator*(double scalar) const;
        friend Vector operator*(double scalar, const Vector &v2);
        friend std::ostream & 
            operator<<(std::ostream &os, const Vector &v1);
    };
}

#endif

