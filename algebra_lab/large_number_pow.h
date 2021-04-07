#pragma once
#include "Large_Number.h"
#include <math.h>
#include <vector>
namespace ln//large number
{
	Large_Number pow(const Large_Number& number, const Large_Number& exp);
	unsigned pow(const unsigned& number, const unsigned& exp);
	unsigned length(unsigned number, unsigned base);
	unsigned gcdExtended(unsigned numberR, unsigned numberN, unsigned& rInv, unsigned& nInv);
	std::vector<unsigned> decomposeExp(unsigned exp);
	unsigned montgomeryMultiplication(unsigned montNumber1, unsigned montNumber2,
		unsigned numberR, unsigned modulus, unsigned modulusInv);
}
