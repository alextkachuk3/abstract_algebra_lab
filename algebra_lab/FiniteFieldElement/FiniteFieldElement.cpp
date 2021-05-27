//
// Created by Maksym on 21-May-21.
//

#include "FiniteFieldElement.hpp"

FiniteFieldElement::FiniteFieldElement(Large_Number value, const std::shared_ptr<EllipticCurve> &ptr) {
    ec_ = ptr;
    value_ = getNormalized(value);
}

FiniteFieldElement::FiniteFieldElement(const std::shared_ptr<EllipticCurve> &ptr) {
    ec_ = ptr;
    value_ = 0;
}


Large_Number FiniteFieldElement::getNormalized(Large_Number value) const {
    Large_Number result = value;
    const Large_Number L_2(2);
    if (value < 0) {
        result = (value % ec_->P()) + L_2 * ec_->P();
    }

    result %= ec_->P();

    return result;
}

FiniteFieldElement::FiniteFieldElement() {
    value_ = 0;
    ec_ = nullptr;
}

FiniteFieldElement FiniteFieldElement::operator+(const FiniteFieldElement &rhs) const {
    return FiniteFieldElement(value_ + rhs.value_, ec_);
}

FiniteFieldElement FiniteFieldElement::operator-(const FiniteFieldElement &rhs) const {
    return FiniteFieldElement(value_ - rhs.value_, ec_);
}

FiniteFieldElement FiniteFieldElement::operator-() const {
    return FiniteFieldElement(-value_, ec_);
}

FiniteFieldElement FiniteFieldElement::operator*(const FiniteFieldElement &rhs) const {
    return FiniteFieldElement(value_ * rhs.value_, ec_);
}

FiniteFieldElement FiniteFieldElement::operator/(const FiniteFieldElement &rhs) const {
    return FiniteFieldElement(value_ * inv_mod(rhs.value_, ec_->P()), ec_);
}


FiniteFieldElement FiniteFieldElement::operator+(Large_Number rhs) const {
    return FiniteFieldElement(value_ + rhs, ec_);
}

FiniteFieldElement FiniteFieldElement::operator-(Large_Number rhs) const {
    return FiniteFieldElement(value_ - rhs, ec_);
}

FiniteFieldElement FiniteFieldElement::operator*(Large_Number rhs) const {
    return FiniteFieldElement(value_ * rhs, ec_);
}

FiniteFieldElement FiniteFieldElement::operator/(Large_Number rhs) const {
    return FiniteFieldElement(value_ / rhs, ec_);
}


bool FiniteFieldElement::operator<(const FiniteFieldElement &rhs) const {
    return value_ < rhs.value_;
}

bool FiniteFieldElement::operator>(const FiniteFieldElement &rhs) const {
    return value_ > rhs.value_;
}

bool FiniteFieldElement::operator==(const FiniteFieldElement &rhs) const {
    return value_ == rhs.value_;
}

bool FiniteFieldElement::operator!=(const FiniteFieldElement &rhs) const {
    return value_ != rhs.value_;
}


bool FiniteFieldElement::operator<(const Large_Number& rhs) const {
    return value_ < rhs;
}

bool FiniteFieldElement::operator>(const Large_Number& rhs) const {
    return value_ > rhs;
}

bool FiniteFieldElement::operator==(const Large_Number& rhs) const {
    return value_ == rhs;
}

bool FiniteFieldElement::operator!=(const Large_Number& rhs) const {
    return Large_Number(value_) !=  rhs;
}

std::string FiniteFieldElement::to_string() const {
    return value_.to_string();
}

std::ostream &operator<<(std::ostream &os, const FiniteFieldElement &element) {
    os << element.to_string();
    return os;
}

Large_Number FiniteFieldElement::inv_mod(Large_Number x, Large_Number n) const {
    //n = Abs(n);
    x = x % n; // % is the remainder function, 0 <= x % n < |n|
    Large_Number u, v, g, z;
    g = EGCD(x, n, u, v);
    if (g != 1) {
        // x and n have to be relative prime for there to exist an x^-1 mod n
        z = 0;
    } else {
        z = u % n;
    }
    return z;
}

Large_Number FiniteFieldElement::EGCD(Large_Number a, Large_Number b, Large_Number &u, Large_Number &v) const {
    u = 1;
    v = 0;
    Large_Number g = a;
    Large_Number u1 = 0;
    Large_Number v1 = 1;
    Large_Number g1 = b;
    while (g1 != 0) {
        Large_Number q = g / g1; // Integer divide
        Large_Number t1 = u - q * u1;
        Large_Number t2 = v - q * v1;
        Large_Number t3 = g - q * g1;
        u = u1;
        v = v1;
        g = g1;
        u1 = t1;
        v1 = t2;
        g1 = t3;
    }

    return g;
}


