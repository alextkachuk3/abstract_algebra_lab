#pragma once
#include "Primal_1.h"
#include <iostream>
#include <math.h>
long long  gcd1(long long  a, long long  b);
void mulmod1(long long& a, long long  b, const long long& n);
void bisect1(long long& n);
bool even1(const long long& n);
void pollard_rh0(long long n);
long long pollard_rho(long long n, long long iterations_count = 10000000000);
long long powmod1(long long a, long long k, const long long& n);