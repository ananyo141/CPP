// Implementation File for Vector Class

#include <iostream>
#include <cmath>
#include <stdexcept>
#include "vector.h"

namespace VECTOR {
    void Vector::checkmode(Mode mode) {
        if (mode != RECT && mode != POL)
            throw std::invalid_argument (
                    "Invalid Mode specified"
                  );
    }

    Vector::Vector() {
        x_ = y_ = 0.0;
        mode_ = RECT;
    }

    Vector::Vector(double arg1, double arg2, Mode mode) {
        checkmode(mode);
        mode_ = mode;
        if (mode_ == RECT) {
            x_ = arg1;  // if mode is rect,
            y_ = arg2;  // save x and y values directly
        } else {        // otherwise if mode is polar,
            double angle = arg2 / RAD_TO_DEG; // arg1 is magnitude
            x_ = arg1 * std::cos(angle);      // find x component
            y_ = arg1 * std::sin(angle);      // find y component
        }
    }
    
    Vector::~Vector() { }                     // empty destructor

    void Vector::reset(double arg1, double arg2, Mode mode) {
        checkmode(mode);
        *this = Vector(arg1, arg2, mode);
    }

    void Vector::polar_mode() {
        mode_ = POL;
    }
    
    void Vector::rect_mode() {
        mode_ = RECT;
    }

    double Vector::get_mag() const {
        return sqrt(x_*x_ + y_*y_);
    }

    double Vector::get_angle() const {
        return atan2(y_, x_) * RAD_TO_DEG;
    }
    
    Vector::operator double() const {
        return this->get_mag();
    }

    Vector Vector::operator+(const Vector &v2) const {
        return Vector(x_ + v2.x_, y_ + v2.y_);
    }

    Vector Vector::operator-(const Vector &v2) const {
        return Vector(x_ - v2.x_, y_ - v2.y_);
    }

    Vector Vector::operator-() const {
        return Vector(-x_, -y_);
    }

    Vector Vector::operator*(double scalar) const {
        return Vector(scalar * x_, scalar * y_);
    }

    Vector operator*(double scalar, const Vector &v2) {
        return v2 * scalar;
    }

    std::ostream &
        operator<<(std::ostream &os, const Vector &v1) {
        if (v1.mode_ == Vector::RECT) {
            os << "(X,Y): ("  << v1.get_x()
               << ", " << v1.get_y() << ")\n";
        } else {
            os << "(Mag,Angle): ("  << v1.get_mag()
               << ", " << v1.get_angle()   << ")\n";
        }
        return os;
    }
}

