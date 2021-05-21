#pragma once
#include "Large_Number.h"
#include <math.h>
#include <vector>
namespace ln//large number
{
	using Number = unsigned long long;
	Number powNumber(const Number& number, const Number& exp);
	std::vector<Number> decomposeExp(Number exp);
	Number montgomeryMultiplication(const Number& montNumber1, const Number& montNumber2,
		const Number& numberR, const Number& modulus, const Number& modulusInv);
	unsigned length(Number number, const Number& base);
	Number gcdExtended(const Number& numberR, const Number& numberN, Number& rInv, Number& nInv);

}
