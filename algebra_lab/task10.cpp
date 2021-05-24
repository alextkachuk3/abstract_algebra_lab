#include "task10.h"
Large_Number power(Large_Number& x, Large_Number& y, Large_Number& p)
{
    Large_Number res(1);
    x = x % p;
    while (y > 0)
    {
        if (y.value[y.value.size()-1]& 1)
            res = (res*x) % p;
        y = y/2;
        x = (x*x) % p;
    }
    return res;
}
bool miillerTest(Large_Number& d, Large_Number& n)
{
    Large_Number nm=n; nm.value[nm.value.size()-1]-=1;
    if (nm.value[nm.value.size()-1]>4) nm.value[nm.value.size()-1]=nm.value[nm.value.size()-1]-3;
    Large_Number a;
    if (nm.value.size()>1)
        a=rand();
    else if (nm.value.size()==1) {
        a = rand() % nm.value[0];
        a++;
    }
    else a.value.push_back(0);
    nm.value[nm.value.size()-1]=nm.value[nm.value.size()-1]+3;
    Large_Number x=power(a,d,n);
    if ((x.value.size()==1 && x.value[0] == 1 )  || x == nm)
        return true;
    while (!(d == nm))
    {
        x = (x * x) % n;
        d = d.multiply_by_digit(2);
        if (x.value.size()==1 && x.value[0] == 1 )      return false;
        if (x == nm)    return true;
    }
    return false;
}
bool isPrime(Large_Number& n, int k)
{
    Large_Number two(2);
    Large_Number d = n; d.value[d.value.size()-1]--;
    while (d % two == 0) {
        d = d / two;
    }
    for (int i = 0; i < k; i++)
        if (!miillerTest(d,n))
            return false;

    return true;
}