#pragma once

#include <string>
#include <sstream>
#include "EllipticCurve.hpp"
#include "../Large_Number.h"

// Елемент на скінченому полі
// Характеристика поля лежить у вкладеному класі еліптичної кривої
class FiniteFieldElement {
public:
    FiniteFieldElement();

    FiniteFieldElement(Large_Number value, const std::shared_ptr<EllipticCurve> &ptr);
    FiniteFieldElement(const std::shared_ptr<EllipticCurve> &ptr);

    FiniteFieldElement operator+(const FiniteFieldElement& rhs) const;
    FiniteFieldElement operator-(const FiniteFieldElement& rhs) const;
    FiniteFieldElement operator-() const;
    FiniteFieldElement operator*(const FiniteFieldElement& rhs) const;
    FiniteFieldElement operator/(const FiniteFieldElement& rhs) const;

    bool operator<(const FiniteFieldElement& rhs) const;
    bool operator>(const FiniteFieldElement& rhs) const;
    bool operator==(const FiniteFieldElement& rhs) const;
    bool operator!=(const FiniteFieldElement& rhs) const;


    FiniteFieldElement operator+(Large_Number rhs) const;
    FiniteFieldElement operator-(Large_Number rhs) const;
    FiniteFieldElement operator*(Large_Number rhs) const;
    FiniteFieldElement operator/(Large_Number rhs) const;

    bool operator<(const Large_Number& rhs) const;
    bool operator>(const Large_Number& rhs) const;
    bool operator==(const Large_Number& rhs) const;
    bool operator!=(const Large_Number& rhs) const;

    std::string to_string() const;
    friend std::ostream& operator <<(std::ostream& os, const FiniteFieldElement& element);

//    FiniteFieldElement operator

private:

    // Нормалізує значення по скінченому полю
    Large_Number getNormalized(Large_Number value) const;

    // Розширений алгоритм евкліда
    Large_Number EGCD(Large_Number a, Large_Number b, Large_Number &u, Large_Number &v) const;

    // Вирішує x * z == 1 (mod n) для z
    Large_Number inv_mod(Large_Number x, Large_Number n) const;

    Large_Number value_;
    std::shared_ptr<EllipticCurve> ec_;
};


