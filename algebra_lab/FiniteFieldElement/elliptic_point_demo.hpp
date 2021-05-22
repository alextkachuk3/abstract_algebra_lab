#pragma once
#include "Point.hpp"

void elliptic_point_demo() {
    std::cout << "Elliptic point demo:\n";
    EllipticCurve ellipticCurve(2, 3, 17);
    Point point(5, 11, ellipticCurve);
    std::cout << ellipticCurve << std::endl;
    std::cout << point << std::endl;

    std::cout << point << " + " << point << " = " << point + point << std::endl;
    std::cout << point << " + " << point << " + " << point << " = " << point + point + point << std::endl;
    std::cout << "-" << point << " = " << -point << std::endl;

    std::cout << "This is the end of elliptic point demo.\nIt's now safe to turn off your computer.\n";
}
