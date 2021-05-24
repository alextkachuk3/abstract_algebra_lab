#include <iostream>
#include <map>
#include <math.h>
#include "Large_Number/Large_Number.h"
#include "Sqrt.h"
#include <stdio.h>
#include <stdlib.h>
//#include "discrete_logarithm.h"
//#include "large_number_pow.h"
#include "discrete_logarithm.h"

// a^x = b(mod m)
//returns x
template< typename T >
std::string int_to_hex(T i)
{
    std::stringstream stream;
    stream
        << std::hex << i;
    return stream.str();
}
//template <class Large_Number>
//Large_Number DiscreteLogarithmBsGs(Large_Number& a, Large_Number& b, const  Large_Number& m)
//{
//    long long num = std::stol(m.to_string(), nullptr, 16);
//    //cout << num;
//    Large_Number n(int_to_hex((long long)sqrt(num + .0) + 1));
//    //cout << n.to_string();
//    Large_Number an("1");
//    long long num_a = std::stol(a.to_string(), nullptr, 16);
//    long long num_m = std::stol(m.to_string(), nullptr, 16);
//    for (long long i = 0; i < std::stol(n.to_string(), nullptr, 16); ++i)//giant
//    {
//        /*       cout << a.to_string()<<endl;
//               cout << an.to_string() << endl;*/
//        long long num_an = std::stol(an.to_string(), nullptr, 16);
//        //cout << num_an << " " << num_a << " "<< num_m << endl;
//        long long res = (num_an * num_a) % num_m;
//        an = Large_Number(int_to_hex(res));
//        //cout << an.to_string();
//        //cout<<res<<" "<<int_to_hex(res)<<endl;
//    }// an = (an * a) % m;

Large_Number DiscreteLogarithm(Large_Number a, Large_Number b, Large_Number m) {
    //a %= m, b %= m;//doesent work
    //Large_Number n (STonelliSQRT(m,2) + 1);//doesnt work
    Large_Number n(sqrt (std::stol(m.to_string(), nullptr, 16) + 1));
    //cout << n.to_string();

    Large_Number an = 1;
    for (Large_Number i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    map<Large_Number, Large_Number> vals;//doesnt work
    for (Large_Number q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (Large_Number p = 1, cur = 1; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            Large_Number ans = n * p - vals[cur];
            return ans;
        }
    }
    return -1;
}
int DiscreteLogarithm(int a, int b, int m) {
    //cout << m;
    int n = (int)sqrt(m + .0) + 1;
    //cout << n;
    int an = 1;
    for (int i = 0; i < n; ++i)
    {
        an = (an * a) % m;
        //cout << an;
    }
    map<int, int> vals;
    for (int i = 1, cur = an; i <= n; ++i) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % m;
        //cout << cur;
    }

    for (int i = 0, cur = b; i <= n; ++i) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - i;
            //cout << ans;
            if (ans < m)
                return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}