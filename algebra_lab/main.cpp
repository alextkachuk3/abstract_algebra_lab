#include <iostream>
#include "Sqrt.h"
#include "Large_Number.h"
#include "large_number_pow.h"

using namespace std;

int main()
{	
	cout << "Hello CMake." << endl;
	Large_Number a("1234567");
	Large_Number b("1234566");
    Large_Number res = (b-a);
	cout << res.to_string() << endl;
    cout << a.N->to_string() << endl;
	return 0;
}
