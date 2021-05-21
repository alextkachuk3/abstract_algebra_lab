#include <iostream>
#include <math.h>
#include "Large_Number.h"
#include "sqrt.h"


Large_Number pollardsRhoMethod(Large_Number rsa, Large_Number cVal, Large_Number xVal) {
	Large_Number primeFactor;
	int k = 0;
	vector<Large_Number> currentValue;

	for (Large_Number i = 0; i < STonelliSQRT(rsa, Large_Number (2)); i++) {

		
		Large_Number xCurrent = (((xVal * xVal) + cVal) % rsa);

		
		currentValue.push_back(xCurrent);

		
		Large_Number xNext = (((xCurrent * xCurrent) + cVal) % rsa);

	
		currentValue.push_back(xNext);

		
		Large_Number myValue = currentValue.at(k++);

	Large_Number difference = (myValue - xNext);

		xVal = xNext;

		primeFactor = gcd(difference, rsa);

		if ((primeFactor == 1) && (primeFactor == rsa))
			return primeFactor;
	}

	cout << "N could not be factored." << endl; 

	return 1; 
}
