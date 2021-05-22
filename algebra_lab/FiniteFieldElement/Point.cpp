//
// Created by Maksym on 21-May-21.
//

#include "Point.hpp"

#include <utility>

Point::Point(const FiniteFieldElement &x,
             const FiniteFieldElement &y,
             const EllipticCurve &elliptic_curve) :
        Point(x, y, std::make_shared<EllipticCurve>(elliptic_curve)) {}


Point::Point(FiniteFieldElement x,
             FiniteFieldElement y,
             std::shared_ptr<EllipticCurve> ptr) :
        ec_(std::move(ptr)),
        x_(std::move(x)),
        y_(std::move(y)) {}


Point::Point(int x, int y, const EllipticCurve &elliptic_curve) :
        Point(x, y, std::make_shared<EllipticCurve>(elliptic_curve)) {}


Point::Point(int x, int y, std::shared_ptr<EllipticCurve> ptr) {
    ec_ = std::move(ptr);
    x_ = (std::move(FiniteFieldElement(x, ec_)));
    y_ = (std::move(FiniteFieldElement(y, ec_)));
}


Point Point::operator+(const Point &rhs) const {
    if (*ec_ != *(rhs.ec_)) {
        throw std::runtime_error("cannot add two points from different elliptic curves");
    }

    if (x_ == 0 && y_ == 0) {
        return rhs;
    }

    if (rhs.x_ == 0 && rhs.y_ == 0) {
        return *this;
    }

    if (y_ == -rhs.y_) {
        return Point(0, 0, ec_);
    }


    FiniteFieldElement slope(ec_);
    FiniteFieldElement x(ec_);
    FiniteFieldElement y(ec_);

    if (*this == rhs) {
        // 2P
        slope = ((x_ * x_) * 3 + ec_->A()) / (y_ * 2);
        x = ((slope * slope) - x_ * 2);
    } else {
        // P+Q
        slope = (y_ - rhs.y_) / (x_ - rhs.x_);
        x = ((slope * slope) - x_ - rhs.x_);
    }

    if (slope == 0) {
        x = FiniteFieldElement(0, ec_);
        y = FiniteFieldElement(0, ec_);
    } else {
        y = (-y_ + slope * (x_ - x));
    }
    return Point(x, y, ec_);
}

Point Point::operator-() const {
    return Point(x_, -y_, ec_);
}

std::string Point::to_string() const {
    std::ostringstream ss;
    ss << "(" << x_ << "; " << y_ << ")";
    return ss.str();
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
    os << point.to_string();
    return os;
}

bool Point::operator==(const Point &rhs) const {
    return x_ == rhs.x_ &&
           y_ == rhs.y_ &&
           *ec_ == *rhs.ec_;
}
