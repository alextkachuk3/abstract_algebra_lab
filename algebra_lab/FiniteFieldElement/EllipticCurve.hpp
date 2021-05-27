#pragma once
#include <string>
#include <sstream>

#include "../Large_Number.h"

// Еліптична крива y^2 = x^3 + Ax + B mod P
class EllipticCurve {
public:

    EllipticCurve(const Large_Number& a, const Large_Number& b, const Large_Number& p);

    // Коефіцієнт Ax
    Large_Number A() const;

    // Коефіцієнт B
    Large_Number B() const;

    // Характеристика поля
    Large_Number P() const;




    bool operator==(const EllipticCurve& rhs) const;
    bool operator!=(const EllipticCurve& rhs) const;

    std::string to_string() const;
    friend std::ostream& operator <<(std::ostream& os, const EllipticCurve& ellipticCurve);

private:
    Large_Number a_, b_, p_;
};