#pragma once

#include <string>
#include <sstream>
#include "EllipticCurve.hpp"

// Елемент на скінченому полі
// Характеристика поля лежить у вкладеному класі еліптичної кривої
class FiniteFieldElement {
public:
    FiniteFieldElement();
    // todo change type
    FiniteFieldElement(int value, const std::shared_ptr<EllipticCurve> &ptr);
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


    FiniteFieldElement operator+(int rhs) const;
    FiniteFieldElement operator-(int rhs) const;
    FiniteFieldElement operator*(int rhs) const;
    FiniteFieldElement operator/(int rhs) const;

    bool operator<(int rhs) const;
    bool operator>(int rhs) const;
    bool operator==(int rhs) const;
    bool operator!=(int rhs) const;

    std::string to_string() const;
    friend std::ostream& operator <<(std::ostream& os, const FiniteFieldElement& element);

//    FiniteFieldElement operator

private:

    // Нормалізує значення по скінченому полю
    int getNormalized(int value) const;

    // Розширений алгоритм евкліда
    int EGCD(int a, int b, int& u, int &v) const;

    // Вирішує x * z == 1 (mod n) для z
    int inv_mod(int x, int n) const;

    // todo change type
    int value_;
    std::shared_ptr<EllipticCurve> ec_;
};


