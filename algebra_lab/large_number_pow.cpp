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
		unsigned rInv = 0, modulusInv = 0;
		unsigned gcs = gcdExtended(numberR, modulus, rInv, modulusInv);
		modulusInv = -1 * modulusInv;
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
	unsigned gcdExtended(unsigned numberR, unsigned numberN, unsigned& rInv, unsigned& nInv)
	{
		if (numberR == 0)
		{
			rInv = 0;
			nInv = 1;
			return numberN;
		}
		unsigned rInv1, nInv1;
		unsigned gcd = gcdExtended(numberN % numberR, numberR, rInv1, nInv1);
		rInv = nInv1 - (numberN / numberR) * rInv1;
		nInv = rInv1;

		return gcd;
	}
}