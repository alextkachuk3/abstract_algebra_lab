#pragma once

#include <memory>
#include <string>
#include <sstream>
#include "EllipticCurve.hpp"
#include "FiniteFieldElement.hpp"

class Point {
public:
    Point(const FiniteFieldElement &x,
          const FiniteFieldElement &y,
          const EllipticCurve &elliptic_curve);

    Point(FiniteFieldElement x,
          FiniteFieldElement y,
          std::shared_ptr<EllipticCurve> ptr);

    Point(int x, int y, const EllipticCurve &elliptic_curve);

    Point(int x, int y, std::shared_ptr<EllipticCurve> ptr);

    bool operator==(const Point &rhs) const;

    Point operator+(const Point &rhs) const;

    Point operator-() const;

    std::string to_string() const;
    friend std::ostream& operator <<(std::ostream& os, const Point& point);

private:
    std::shared_ptr<EllipticCurve> ec_;
    FiniteFieldElement x_, y_;
};



