//
// Created by Maksym on 21-May-21.
//

#include "EllipticCurve.hpp"

EllipticCurve::EllipticCurve(const Large_Number& a,
                             const Large_Number& b,
                             const Large_Number& p) :
        a_(a), b_(b), p_(p) {}


Large_Number EllipticCurve::A() const {
    return a_;
}

Large_Number EllipticCurve::B() const {
    return b_;
}

Large_Number EllipticCurve::P() const {
    return p_;
}

std::string EllipticCurve::to_string() const {
    std::ostringstream stream;
    stream << "y^2 = x^3 + " << a_ << "x + " << b_ << " mod " << p_;
    return stream.str();
}

std::ostream &operator<<(std::ostream &os, const EllipticCurve &ellipticCurve) {
    os << ellipticCurve.to_string();
    return os;
}

bool EllipticCurve::operator==(const EllipticCurve &rhs) const {
    return a_ == rhs.a_ &&
           b_ == rhs.b_ &&
           p_ == rhs.p_;
}

bool EllipticCurve::operator!=(const EllipticCurve &rhs) const {
    return !(*this == rhs);
}


