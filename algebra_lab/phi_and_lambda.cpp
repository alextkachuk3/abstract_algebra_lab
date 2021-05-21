#include "phi_and_lambda.h"

Large_Number gcd(Large_Number a, Large_Number b)
{
	while (a > 0 && b > 0) {
		if (a > b)
			a = a % b;
		else
			b = b % a;
	}
	return a + b;
}

Large_Number phi(Large_Number& n)
{
	Large_Number result = n;

	for (Large_Number p = 2; p * p < n; ++p)
	{

		if (n % p == 0)
		{

			while (n % p == 0)
				n = n / p;

			result -= result / p;
		}
	}

	if (n > 1)
		result -= result / n;

	return result;
}

vector<Large_Number> coprime_integers(Large_Number n)
{
	vector<Large_Number> result;
	for (Large_Number i = 2; i < n; i++)
	{
		if (gcd(i, n) == 1)
		{
			result.push_back(i);
		}
	}
	return result;
}

Large_Number lambda(Large_Number n)
{
	vector<Large_Number> coprime = coprime_integers(n);
	for (Large_Number i = 1; ; i++)
	{
		Large_Number counter = 0;
		for (const auto& a : coprime)
		{
			if ((ln::powNumber(a, i) % n) == 1) counter++;
			else break;
		}
		if (counter == coprime.size()) return i;
	}
}