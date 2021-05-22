cmake_minimum_required (VERSION 3.8)

add_executable (algebra_lab
        "main.cpp"
        "Large_Number.cpp"
        "Large_Number.h"
        "large_number_pow.cpp" "large_number_pow.h"
        "Sqrt.cpp" "Sqrt.h"
        "task10.cpp" "task10.h"
        "Field.cpp"
        "FiniteFieldElement.h"
        "phi_and_lambda.h" "phi_and_lambda.cpp"
        "Primal_1.cpp" "Primal_1.h"
        "Pollard_Rho.cpp" "Pollard_Rho.h"
        "FiniteFieldElement/FiniteFieldElement.hpp" "FiniteFieldElement/FiniteFieldElement.cpp"
        "FiniteFieldElement/Point.hpp" "FiniteFieldElement/Point.cpp"
        "FiniteFieldElement/EllipticCurve.hpp" "FiniteFieldElement/EllipticCurve.cpp" FiniteFieldElement/elliptic_point_demo.hpp)

