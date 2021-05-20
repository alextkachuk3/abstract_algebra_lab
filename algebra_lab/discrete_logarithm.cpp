#include <iostream>
#include <map>
#include <math.h>
#include "discrete_logarithm.h"

// a^x = b(mod m)
//returns x
template <class Large_Number>
Large_Number DiscreteLogarithmBsGs(Large_Number& a, Large_Number& b, const  Large_Number& m)
{
    long long num = std::stol(m.to_string(), nullptr, 16);
    Large_Number n(to_string(pow(num, 0.5) + 1));

    Large_Number an("1");
    for (Large_Number i("1"); i < n + Large_Number("1"); i++)
    {
        cout << a.to_string() << endl;
        cout << an.to_string() << endl;
        an = an % m;//doesnot work
    }
    //an *= a /*% m*/; /*cout << (i - Large_Number("1")).to_string()<<" ";*/
 //cout << endl;


 //map<int, int> vals;
 //Large_Number cur = (an);
 //for (Large_Number i("1"); i < n + Large_Number("1"); i++);
 //{
 ////    if (!vals.count(cur))
 ////        vals[cur] = i;
 ////    cur = (cur * an) % m;
 //}

 ////for (int i = 0, cur = b; i <= n; ++i) {
 ////    if (vals.count(cur)) {
 ////        Large_Number ans = vals[cur] * n - i;
 ////        if (ans < m)
 ////            return ans;
 ////    }
 ////    cur = (cur * a) % m;
 ////}
    return n;
}
int DiscreteLogarithmBsGs(int a, int b, int m) {
    int n = (int)sqrt(m + .0) + 1;

    int an = 1;
    for (int i = 0; i < n; ++i)
        an = (an * a) % m;

    map<int, int> vals;
    for (int i = 1, cur = an; i <= n; ++i) {
        if (!vals.count(cur))
            vals[cur] = i;
        cur = (cur * an) % m;
    }

    for (int i = 0, cur = b; i <= n; ++i) {
        if (vals.count(cur)) {
            int ans = vals[cur] * n - i;
            if (ans < m)
                return ans;
        }
        cur = (cur * a) % m;
    }
    return -1;
}
