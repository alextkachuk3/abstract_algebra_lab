#include <iostream>
#include <math.h>
//#include "Large_Number.h"
//#include "sqrt.h"


long long int gcd1(long long  a,long long  b) {
	return b ? gcd1(b, a % b) : a;
}


void mulmod(long long & a, long long  b, const long long & n)
{
	a = long long ((((long long )a) * b) % n);
}


void bisect(long long& n)
{
	// n /= 2;
	n >>= 1;
}
bool even(const long long& n)
{
	// return n % 2 == 0;
	return (n & 1) == 0;
}


long long pollard_rho (long long n, long long iterations_count = 100000)
{
	long long
		b0 = rand() % n,
		b1 = b0,
		g;
	mulmod(b1, b1, n);
	if (++b1 == n)
		b1 = 0;
	g = gcd1(abs(b1 - b0), n);
	for (long long  count = 0; count < iterations_count && (g == 1 || g == n); count++)
	{
		mulmod(b0, b0, n);
		if (++b0 == n)
			b0 = 0;
		mulmod(b1, b1, n);
		++b1;
		mulmod(b1, b1, n);
		if (++b1 == n)
			b1 = 0;
		g = gcd1(abs(b1 - b0), n);
	}
	return g;
}

long long powmod(long long a,long long k, const long long& n)
{
	long long  res = 1;
	while (k)
		if (!even(k))
		{
			mulmod(res, a, n);
			--k;
		}
		else
		{
			mulmod(a, a, n);
			bisect(k);
		}
	return res;
}














//
//#include <iostream>
//#include <math.h>
//#include "Large_Number.h"
//#include "sqrt.h"
//
//
//Large_Number pollardsRhoMethod(Large_Number rsa, Large_Number cVal, Large_Number xVal) {
//	Large_Number primeFactor;
//	int k = 0;
//	vector<Large_Number> currentValue;
//
//	for (Large_Number i = 0; i < STonelliSQRT(rsa, Large_Number(2)); i++) {
//
//
//		Large_Number xCurrent = (((xVal * xVal) + cVal) % rsa);
//
//
//		currentValue.push_back(xCurrent);
//
//
//		Large_Number xNext = (((xCurrent * xCurrent) + cVal) % rsa);
//
//
//		currentValue.push_back(xNext);
//
//
//		Large_Number myValue = currentValue.at(k++);
//
//		Large_Number difference = (myValue - xNext);
//
//		xVal = xNext;
//
//		primeFactor = gcd(difference, rsa);
//
//		if ((primeFactor == 1) && (primeFactor == rsa))
//			return primeFactor;
//	}
//
//	cout << "N could not be factored." << endl;
//
//	return 1;
//}
//
