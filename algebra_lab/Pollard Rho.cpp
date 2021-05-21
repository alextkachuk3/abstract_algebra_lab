#include <iostream>
#include <math.h>
#include "Large_Number.h"
#include "sqrt.h"


template <class T>
T pollard_p_1(T n)
{

	const T b = 13;
	const T q[] = { 2, 3, 5, 7, 11, 13 };

	T a = 5 % n;
	for (int j = 0; j < 10; j++)
	{

		while (gcd(a, n) != 1)
		{
			mulmod(a, a, n);
			a += 3;
			a %= n;
		}
M
		for (size_t i = 0; i < sizeof q / sizeof q[0]; i++)
		{
			T qq = q[i];
			T e = (T)floor(log((double)b) / log((double)qq));
			T aa = powmod(a, powmod(qq, e, n), n);
			if (aa == 0)
				continue;

			T g = gcd(aa - 1, n);
			if (1 < g && g < n)
				return g;
		}

	}

	return 1;

}
