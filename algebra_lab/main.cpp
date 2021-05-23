#include <iostream>
#include "Sqrt.h"
#include "Large_Number.h"
#include "large_number_pow.h"

using namespace std;




int main()
{	
//	cout << "Hello CMake." << endl;
////	Large_Number a("57970cd7e29336813b0");
//	Large_Number a("9164e20e921b");
//	Large_Number b("2B29F31C536004");
//    Large_Number res = (b/a);
////    Large_Number res = a.modInverse();
//    Large_Number exp_res("2D45DFB4A91644D3C4029D64CD1860D");
//    exp_res.modN();
//
//	cout << res.to_string() << endl;
//    cout << exp_res.to_string() << endl;
//    cout << (*exp_res.N).to_string()  << endl;
    Large_Number a;
    a = a.generate_random_number();
    cout << a.to_string()  << endl;
	return 0;
}
