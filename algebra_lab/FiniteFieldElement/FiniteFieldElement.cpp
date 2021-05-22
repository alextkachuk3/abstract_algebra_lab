//
// Created by Maksym on 21-May-21.
//

#include "FiniteFieldElement.hpp"

FiniteFieldElement::FiniteFieldElement(int value, const std::shared_ptr<EllipticCurve> &ptr) {
    ec_ = ptr;
    value_ = getNormalized(value);
}

FiniteFieldElement::FiniteFieldElement(const std::shared_ptr<EllipticCurve> &ptr) {
    ec_ = ptr;
    value_ = 0;
}


int FiniteFieldElement::getNormalized(int value) const {
    int result = value;

    if (value < 0) {
        result = (value % ec_->P()) + 2 * ec_->P();
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


FiniteFieldElement FiniteFieldElement::operator+(int rhs) const {
    return FiniteFieldElement(value_ + rhs, ec_);
}

FiniteFieldElement FiniteFieldElement::operator-(int rhs) const {
    return FiniteFieldElement(value_ - rhs, ec_);
}

FiniteFieldElement FiniteFieldElement::operator*(int rhs) const {
    return FiniteFieldElement(value_ * rhs, ec_);
}

FiniteFieldElement FiniteFieldElement::operator/(int rhs) const {
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


bool FiniteFieldElement::operator<(int rhs) const {
    return value_ < rhs;
}

bool FiniteFieldElement::operator>(int rhs) const {
    return value_ > rhs;
}

bool FiniteFieldElement::operator==(int rhs) const {
    return value_ == rhs;
}

bool FiniteFieldElement::operator!=(int rhs) const {
    return value_ != rhs;
}

std::string FiniteFieldElement::to_string() const {
    return std::to_string(value_);
}

std::ostream &operator<<(std::ostream &os, const FiniteFieldElement &element) {
    os << element.to_string();
    return os;
}

int FiniteFieldElement::inv_mod(int x, int n) const {
    //n = Abs(n);
    x = x % n; // % is the remainder function, 0 <= x % n < |n|
    int u, v, g, z;
    g = EGCD(x, n, u, v);
    if (g != 1) {
        // x and n have to be relative prime for there to exist an x^-1 mod n
        z = 0;
    } else {
        z = u % n;
    }
    return z;
}

int FiniteFieldElement::EGCD(int a, int b, int &u, int &v) const {
    u = 1;
    v = 0;
    int g = a;
    int u1 = 0;
    int v1 = 1;
    int g1 = b;
    while (g1 != 0) {
        int q = g / g1; // Integer divide
        int t1 = u - q * u1;
        int t2 = v - q * v1;
        int t3 = g - q * g1;
        u = u1;
        v = v1;
        g = g1;
        u1 = t1;
        v1 = t2;
        g1 = t3;
    }

    return g;
}


