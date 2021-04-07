#include "large_number_pow.h"

namespace ln
{
	Large_Number pow(const Large_Number& number, const Large_Number& exp)
	{

	}
	unsigned pow(const unsigned& number, const unsigned& exp)
	{
		if (exp == 0) return 1;
		if (exp == 1) return number;
		unsigned base = 10;
		unsigned modulus = 101;
		unsigned numberR = std::pow(base, length(modulus, base));
		numberR %= modulus;

		return number;
	}
	unsigned length(unsigned number, unsigned base)
	{
		unsigned res = 0;
		while (number > 0)
		{
			number /= base;
			res++;
		}
		return res;
	}
}