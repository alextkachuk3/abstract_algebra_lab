#pragma once
#include <string>
#include <sstream>

// Еліптична крива y^2 = x^3 + Ax + B mod P
class EllipticCurve {
public:

    // todo change type
    EllipticCurve(int a, int b, int p);

    // todo change type
    // Коефіцієнт Ax
    int A() const;

    // todo change type
    // Коефіцієнт B
    int B() const;

    // todo change type
    // Характеристика поля
    int P() const;




    bool operator==(const EllipticCurve& rhs) const;
    bool operator!=(const EllipticCurve& rhs) const;

    std::string to_string() const;
    friend std::ostream& operator <<(std::ostream& os, const EllipticCurve& ellipticCurve);

private:
    // todo change type
    int a_, b_, p_;
};