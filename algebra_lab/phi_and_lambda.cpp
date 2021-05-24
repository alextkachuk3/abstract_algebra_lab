#include "phi_and_lambda.h"

long long gcd(long long a, long long b)
{
	while (a && b) {
		if (a > b)
			a %= b;
		else
			b %= a;
	}
	return a + b;
}

long long phi(long long n)
{
	long long result = n;

	for (long long p = 2; p * p <= n; ++p)
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

vector<long long> coprime_integers(long long n)
{
	vector<long long> result;
	for (long long i = 2; i < n; i++)
	{
		if (gcd(i, n) == 1)
		{
			result.push_back(i);
		}
	}
	return result;
}

long long lambda(long long n)
{
	vector<long long> coprime = coprime_integers(n);
	for (long long i = 1; ; i++)
	{
		long long counter = 0;
		for (const auto& a : coprime)
		{
			long long step = a;
			for (int j = 1; j < i; j++)
			{
				step = (step * a) % n;
			}
			if (step == 1) counter++;
			else break;
		}
		if (counter == coprime.size()) return i;
	}
}

string p_h_tests()
{
	if (phi(5252) != 2400)
		return "1 fail!";
	else if(lambda(5252) != 300)
		return "2 fail!";
	else if (phi(4) != 2)
		return "3 fail";
	else if (lambda(4) != 2)
		return "4 fail!";
	else if (phi(42126) != 11136)
		return "5 fail";
	else if (lambda(42126) != 1392)
		return "6 fail!";
	else if (phi(100) != 40)
		return "7 fail";
	else if (lambda(100) != 20)
		return "8 fail!";
	else if (phi(9777) != 6516)
		return "9 fail";
	else if (lambda(9777) != 3258)
		return "10 fail!";
	else if (phi(1483) != 1482)
		return "11 fail";
	else if (lambda(100000) != 5000)
		return "12 fail!";
	else if (phi(5252) != 2400)
		return "13 fail";
	else if (lambda(5252) != 300)
		return "14 fail!";
	
	return "SUCCESS";
}
