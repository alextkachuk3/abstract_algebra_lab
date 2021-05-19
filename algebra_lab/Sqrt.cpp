#include "Large_Number.h"
using namespace std;

Large_Number pow(Large_Number base, Large_Number exponent, Large_Number modulus)
{
    Large_Number result,zero,two;
    zero.value.push_back(0);
    result.value.push_back(1);
    two.value.push_back(2);
    base = base % modulus;
    while (exponent > zero)
    {
        if (exponent % two == 1)
            result = (result * base) % modulus;
        exponent = exponent / two;
        base = (base * base) % modulus;
    }
    return result;
}
Large_Number powOfTwo(Large_Number x) {
    Large_Number result,zero,two;
    zero.value.push_back(0);
    result.value.push_back(1);
    two.value.push_back(2);
    for (zero; zero < x; zero++)
    {
        result = result * two;
    }
    return result;
}
Large_Number gcd(Large_Number a, Large_Number b)
{
    Large_Number zero;
    zero.value.push_back(0);
    if (b == zero)
        return a;
    else
        return gcd(b, a % b);
}

Large_Number order(Large_Number p, Large_Number b)
{
    Large_Number one,zero;
    one.value.push_back(1);
    zero.value.push_back(0);
    if (!(gcd(p, b) == one))
    {
        printf("p and b are not co-prime.\n");
        return zero;
    }

    Large_Number k ;
    k.value.push_back(3);
    while (1)
    {
        if (pow(b, k, p) == one)
            return k;
        k++;
    }
}


Large_Number convertx2e(Large_Number x, Large_Number& e)
{
    Large_Number two,zero;
    two.value.push_back(2);
    zero.value.push_back(0);
    e.value.push_back(0);
    while (x %  two== zero)
    {
        x =x/ two;
        e++;
    }
    return x;
}

Large_Number STonelliSQRT(Large_Number n, Large_Number p)
{
    Large_Number one,zero,two;
    one.value.push_back(1);
    zero.value.push_back(0);
    two.value.push_back(2);
    if (!(gcd(n, p) == one))
    {
        printf("a and p are not coprime\n");

        return zero;
    }

    
    if (pow(n, (p - one) / two, p) == (p - one))
    {
        printf("no sqrt possible\n");
        return zero;
    }


    Large_Number s, e;
    s = convertx2e(p - one, e);

    Large_Number q;
    for (q = two; ; q++)
    {
        if (pow(q, (p - one) / two, p) == (p - one))
            break;
    }

    Large_Number x = pow(n, (s + one) / two, p);
    Large_Number b = pow(n, s, p);
    Large_Number g = pow(q, s, p);

    Large_Number r = e;

    while (1)
    {
        Large_Number m;
        for (m = zero; m < r; m++)
        {
            if (order(p, b) == zero)
                return zero;

            if (order(p, b) == powOfTwo( m))
                break;
        }
        if (m == zero)
            return x;

        x = (x * pow(g, powOfTwo(r - m - one), p)) % p;
        g = pow(g, powOfTwo(r - m), p);
        b = (b * g) % p;

        if (b == one)
            return x;
        r = m;
    }
}

