#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
/*
	BigInt class and constructor declaration
*/
class BigInt {
private:
	string num;
	bool negative = false;
public:

#pragma region Constructors
	// Default constructor
	BigInt() {
		num = "0";
	}
	// Integer constructor
	BigInt(int n) {
		num = to_string(n);
		if (to_string(n)[0] == '-') {
			negative = true;
		}
	}
	// Double constructor
	BigInt(double n) {
		num = to_string((int)n);
		if (to_string(n)[0] == '-') {
			negative = true;
		}
	}
	// String constructor
	BigInt(string n) {
		num = n;
		for (int i = 0; i < n.length(); i++) {
			if (int(n[i]) < 48 || int(n[i]) > 57) {
				if (n[i] != '-') {
					num = "0";
				}
			}
		}
		if (n[0] == '-') {
			negative = true;
		}
	}
#pragma endregion Constructors
#pragma region Setter_Methods
	/*
		Sets the selected big into the the value of n
	*/
	void setVal(int n) {
		num = to_string(n);
		if (to_string(n)[0] == '-') {
			negative = true;
		}
	}
	/*
		Sets the selected big into the the value of n
	*/
	void setVal(double n) {
		num = to_string((int)n);
		if (to_string(n)[0] == '-') {
			negative = true;
		}
	}
	/*
		Sets the selected big into the the value of n
	*/
	void setVal(string n) {
		num = n;
		for (int i = 0; i < n.length(); i++) {
			if (int(n[i]) < 48 || int(n[i]) > 57) {
				num = "0";
			}
		}
		if (n[0] == '-') {
			negative = true;
		}
	}
#pragma endregion Setter_Methods
#pragma region Helpers
	/*
		Returns the string value of selected BigInt
		@return: string value of selected BigInt
	*/
	string toString() {
		return num;
	}

	/*
		Returns the int value of the selected BigInt's length
		@return: length of the value of selected BigInt
	*/
	int length() {
		return num.length();
	}

	/*
		Returns a digit at a specified index
		@return: int value of a digit at specified index
	*/
	int digiAt(int i) {
		return num[i] - 48;
	}
#pragma endregion Helpers

	//YOU ARE MY FRIEND WOOOOOOOAAAAAAAAAAAAH
	friend ostream& operator<< (ostream&, const BigInt&);

#pragma region Equals
	///// EQUAL /////

	/*
		Detects if the value of two BigInts are equal
		@param:
			- BigInt a: Second value to be tested
		@return: If the values are equal
	*/
	bool operator==(const BigInt& a) {
		string num1 = num;
		string num2 = a.num;
		if (num1.length() != num2.length()) {
			return false;
		}
		for (int i = 0; i < num1.length(); i++) {
			if (num1[i] != num2[i]) {
				return false;
			}
		}
		return true;
	}

	/*
		Detects if the value of a BigInt and a int are equal
		@param:
			- int a: Second value to be tested
		@return: If the values are equal
	*/
	bool operator==(const int& a) {
		return operator==(BigInt(a));
	}

	/*
		Detects if the value of a BigInt and a double are equal
		@param:
			- double a: Second value to be tested
		@return: If the values are equal
	*/
	bool operator==(const double& a) {
		string num1 = num;
		string num2 = to_string(a); // Including decimals
		string tNum2 = to_string((int)a); // Without decimals
		if (num1.length() != tNum2.length()) {
			return false;
		}
		else {
			int ind = num2.find('.', 0);
			if (stoi(num2.substr(ind + 1)) > 0) {
				return false;
			}
		}
		for (int i = 0; i < num1.length(); i++) {
			if (num1[i] != tNum2[i]) {
				return false;
			}
		}
		return true;
	}

	/*
		Detects if the value of a BigInt and a string are equal
		@param:
			- string a: Second value to be tested
		@return: If the values are equal
	*/
	bool operator==(const string& a) {
		return operator==(BigInt(a));
	}
#pragma endregion Equals
#pragma region Less_Than
	///// LESS THAN /////

	/*
		Detects if a value of a BigInt is less than the selected
		@param:
			- BigInt a: Second value to be tested
		@return: if the selected is less than a
	*/
	bool operator<(const BigInt& a) {
		string num1 = num;
		string num2 = a.num;
		if (num1 == num2) {
			return false;
		}
		if (!negative && a.negative) {
			return false;
		}
		else if (negative && !a.negative) {
			return true;
		}
		else if (!negative && !a.negative) {
			if (num1.length() < num2.length()) {
				return true;
			}
			else if (num2.length() < num1.length()) {
				return false;
			}
			else {
				for (int i = 0; i < num1.length(); i++) {
					if (num1[i] > num2[i]) {
						return false;
					}
				}
			}
		}
		else if (negative && a.negative) {
			if (num1.length() > num2.length()) {
				return true;
			}
			else if (num2.length() < num1.length()) {
				return false;
			}
			else {
				for (int i = 1; i < num1.length(); i++) {
					if (num1[i] < num2[i]) {
						return false;
					}
				}
			}
		}
		return true;
	}

	/*
		Detects if a value of an int is less than the selected
		@param:
			- int a: Second value to be tested
		@return: if the selected is less than a
	*/
	bool operator<(const int& a) {
		return operator<(BigInt(a));
	}

	/*
		Detects if a value of a double is less than the selected
		@param:
			- double doubA: Second value to be tested
		@return: if the selected is less than a
	*/
	bool operator<(const double& doubA) {
		string num1 = num;
		string num2 = to_string(doubA);
		string tNum2 = to_string((int)doubA);
		BigInt a = BigInt(tNum2);
		if (negative && !a.negative) {
			return true;
		}
		else if (!negative && a.negative) {
			return false;
		}
		else if (!negative && !a.negative) {
			if (num1.length() < tNum2.length()) {
				return true;
			}
			else if (tNum2.length() < num1.length()) {
				return false;
			}
			else {
				for (int i = 0; i < num1.length(); i++) {
					if (num1[i] > tNum2[i]) {
						return false;
					}
				}
				int ind = num2.find('.', 0);
				if (stoi(num2.substr(ind + 1)) > 0) {
					return true;
				}
			}
		}
		else if (negative && a.negative) {
			if (num1.length() < tNum2.length()) {
				return false;
			}
			else if (tNum2.length() < num1.length()) {
				return true;
			}
			else {
				for (int i = 1; i < num1.length(); i++) {
					if (num1[i] < num2[i]) {
						return false;
					}
				}
				int ind = num2.find('.', 0);
				if (stoi(num2.substr(ind + 1)) > 0) {
					return false;
				}
			}
		}
		return true;
	}
	/*
		Detects if a value of a string is less than the selected
		@param:
			- string a: Second value to be tested
		@return: if the selected is less than a
	*/
	bool operator<(const string& a) {
		return operator<(BigInt(a));
	}
#pragma endregion Less_Than
#pragma region Greater_Than
	///// GREATER THAN /////

	/*
		Detects if a value of a BigInt is greater than the selected
		@param:
			-BigInt a: Second value to be tested
		@return: if the selected is greater than a
	*/
	bool operator>(const BigInt& a) {
		return !operator==(a) && !operator<(a);
	}

	/*
		Detects if a value of an int is greater than the selected
		@param:
			-int a: Second value to be tested
		@return: if the selected is greater than a
	*/
	bool operator>(const int& a) {
		return !operator==(a) && !operator<(a);
	}

	/*
		Detects if a value of a double is greater than the selected
		@param:
			-double a: Second value to be tested
		@return: if the selected is greater than a
	*/
	bool operator>(const double& a) {
		return !operator==(a) && !operator<(a);
	}

	/*
		Detects if a value of a string is greater than the selected
		@param:
			-string a: Second value to be tested
		@return: if the selected is greater than a
	*/
	bool operator>(const string& a) {
		return !operator==(a) && !operator<(a);
	}
#pragma endregion Greater_Than
#pragma region Less_Than_or_Equal_to
	///// LESS THAN OR EQUAL /////

	/*
		Detects if a value of a BigInt is less than or equal to the selected
		@param:
			- BigInt a: Second value to be tested
		@return : if the selected value is less than or equal to a
	*/
	bool operator<=(const BigInt& a) {
		return operator==(a) || operator<(a);
	}

	/*
		Detects if a value of an int is less than or equal to the selected
		@param:
			- int a: Second value to be tested
		@return : if the selected value is less than or equal to a
	*/
	bool operator<=(const int& a) {
		return operator==(a) || operator<(a);
	}

	/*
		Detects if a value of a double is less than or equal to the selected
		@param:
			- double a: Second value to be tested
		@return : if the selected value is less than or equal to a
	*/
	bool operator<=(const double& a) {
		return operator==(a) || operator<(a);
	}

	/*
		Detects if a value of a string is less than or equal to the selected
		@param:
			- string a: Second value to be tested
		@return : if the selected value is less than or equal to a
	*/
	bool operator<=(const string& a) {
		return operator==(a) || operator<(a);
	}
#pragma endregion Less_Than_or_Equal_to
#pragma region Greater_Than_or_Equal_to
	///// GREATER THAN OR EQUAL /////

	/*
		Detects if a value of a BigInt is greater than or equal to the selected
		@param:
			- BigInt a: Second value to be tested
		@return : if the selected value is greater than or equal to a
	*/
	bool operator>=(const BigInt& a) {
		return operator==(a) || operator>(a);
	}

	/*
		Detects if a value of an int is greater than or equal to the selected
		@param:
			- int a: Second value to be tested
		@return : if the selected value is greater than or equal to a
	*/
	bool operator>=(const int& a) {
		return operator==(a) || operator>(a);
	}

	/*
		Detects if a value of a double is greater than or equal to the selected
		@param:
			- double a: Second value to be tested
		@return : if the selected value is greater than or equal to a
	*/
	bool operator>=(const double& a) {
		return operator==(a) || operator>(a);
	}

	/*
		Detects if a value of a string is greater than or equal to the selected
		@param:
			- string a: Second value to be tested
		@return : if the selected value is greater than or equal to a
	*/
	bool operator>=(const string& a) {
		return operator==(a) || operator>(a);
	}
#pragma endregion Greater_Than_or_Equal_to
#pragma region Not_Equal
	///// Not EQUAL /////

	/*
		Detects if a value of a BigInt is not equal to the selected
		@param:
			- BigInt a: Seconds value to be tested
		@return: if the selected's value doesn't equal a's value
	*/
	bool operator!=(const BigInt& a) {
		return !operator==(a);
	}
	/*
		Detects if a value of a int is not equal to the selected
		@param:
			- int a: Seconds value to be tested
		@return: if the selected's value doesn't equal a's value
	*/
	bool operator!=(const int& a) {
		return !operator==(a);
	}

	/*
		Detects if a value of a double is not equal to the selected
		@param:
			- double a: Seconds value to be tested
		@return: if the selected's value doesn't equal a's value
	*/
	bool operator!=(const double& a) {
		return !operator==(a);
	}

	/*
		Detects if a value of a string is not equal to the selected
		@param:
			- string a: Seconds value to be tested
		@return: if the selected's value doesn't equal a's value
	*/
	bool operator!=(const string& a) {
		return !operator==(a);
	}
#pragma endregion Not_Equal
#pragma region Adding
	///// ADDING /////

	/*
		Adds the value of two BigInts
		@param:
			- BigInt a: Second value to be added
		@return: the sum of two BigInts
	*/
	BigInt operator+(const BigInt& a) {

		return BigInt(0);
	}

	/*
		Adds the value of a BigInts and an Integer
		@param:
			- int a: second value to be added
		@return: the sum of the passed integer and the selected BigInt
	*/
	BigInt operator+(const int& a) {
		return operator+(BigInt(a));
	}

	/*
		Adds the value of a BigInts and an double
		@param:
			- double a: second value to be added
		@return: the sum of the passed double and the selected BigInt
	*/
	BigInt operator+(const double& a) {
		return operator+(BigInt(a));
	}

	/*
		Adds the value of a BigInts and an string
		@param:
			- string a: second value to be added
		@return: the sum of the passed string and the selected BigInt
	*/
	BigInt operator+(const string& a) {
		return operator+(BigInt(a));
	}
#pragma endregion Adding
#pragma region Subtracting
	///// Subtracting /////

	/*
		Subtracts the value of two BigInts
		@param:
			- BigInt a: Second value to be subtracted
		@return: the difference of two BigInts
	*/
	BigInt operator-(const BigInt& a) {
		return BigInt(0);
	}

	/*
		Subtracts the value of a BigInts and an Integer
		@param:
			- int a: second value to be subtracted
		@return: the difference of the passed integer and the selected BigInt
	*/
	BigInt operator-(const int& a) {
		return operator-(BigInt(a));
	}

	/*
		Subtracts the value of a BigInts and an double
		@param:
			- double a: second value to be subtracted
		@return: the difference of the passed double and the selected BigInt
	*/
	BigInt operator-(const double& a) {
		return operator-(BigInt(a));
	}

	/*
		Subtracts the value of a BigInts and an string
		@param:
			- string a: second value to be subtracted
		@return: the difference of the passed string and the selected BigInt
	*/
	BigInt operator-(const string& a) {
		return operator-(BigInt(a));
	}
#pragma endregion Subtracting
#pragma region Multiplying
	///// MULTIPLYING /////

	/*
		Multiplies the value of two BigInts
		@param:
			- BigInt a: Second value to be multiplied
		@return: the product of two BigInts
	*/
	BigInt operator*(const BigInt& a) {

		return BigInt(0);
	}

	/*
		Multiplies the value of a BigInts and an Integer
		@param:
			- int a: second value to be multiplied
		@return: the product of the passed integer and the selected BigInt
	*/
	BigInt operator*(const int& a) {
		return operator*(BigInt(a));
	}

	/*
		Multiplies the value of a BigInts and an double
		@param:
			- double a: second value to be multiplied
		@return: the product of the passed double and the selected BigInt
	*/
	BigInt operator*(const double& a) {
		return operator*(BigInt(a));
	}

	/*
		Multiplies the value of a BigInts and an string
		@param:
			- string a: second value to be multiplied
		@return: the product of the passed string and the selected BigInt
	*/
	BigInt operator*(const string& a) {
		return operator*(BigInt(a));
	}
#pragma endregion Multiplying
#pragma region Dividing
	///// DIVIDING /////

	/*
		Divides the value of two BigInts
		@param:
			- BigInt a: divisor
		@return: the quotient of two BigInts
	*/
	BigInt operator/(const BigInt& a) {

		return BigInt(0);
	}

	/*
		Divides the value of a BigInts and an Integer
		@param:
			- int a: divisor
		@return: the quotient of the passed integer and the selected BigInt
	*/
	BigInt operator/(const int& a) {
		return operator/(BigInt(a));
	}

	/*
		Divides the value of a BigInts and an double
		@param:
			- double a: divisor
		@return: the quotient of the passed double and the selected BigInt
	*/
	BigInt operator/(const double& a) {
		return operator/(BigInt(a));
	}

	/*
		Divides the value of a BigInts and an string
		@param:
			- string a: divisor
		@return: the quotient of the passed string and the selected BigInt
	*/
	BigInt operator/(const string& a) {
		return operator/(BigInt(a));
	}
#pragma endregion Dividing
#pragma region Modulus
	///// MODULUS /////

	/*
		Finds the modulus of two BigInts
		@param:
			- BigInt a: divisor
		@return: the mod of two BigInts
	*/
	BigInt operator%(const BigInt& a) {

		return BigInt(0);
	}

	/*
		Finds the modulus of a BigInts and an Integer
		@param:
			- int a: divisor
		@return: the mod of the passed integer and the selected BigInt
	*/
	BigInt operator%(const int& a) {
		return operator%(BigInt(a));
	}

	/*
		Finds the modulus of a BigInts and an double
		@param:
			- double a: divisor
		@return: the mod of the passed double and the selected BigInt
	*/
	BigInt operator%(const double& a) {
		return operator%(BigInt(a));
	}

	/*
		Finds the modulus of a BigInts and an string
		@param:
			- string a: divisor
		@return: the mod of the passed string and the selected BigInt
	*/
	BigInt operator%(const string& a) {
		return operator%(BigInt(a));
	}
#pragma endregion Modulus
#pragma region Plus_Equals
	///// ADDING AND SETTING /////

	/*
		Finds and sets the sum of two BigInts to the first
		@param:
			- BigInt a: number to be added
	*/
	void operator+=(const BigInt& a) {
		cout << "Test";
	}

	/*
		Finds and sets the sum of Bigint and an int to the first
		@param:
			- int a: number to be added
	*/
	void operator+=(const int& a) {
		operator+=(BigInt(a));
	}

	/*
		Finds and sets the sum of Bigint and a double to the first
		@param:
			- double a: number to be added
	*/
	void operator+=(const double& a) {
		operator+=(BigInt(a));
	}

	/*
		Finds and sets the sum of Bigint and a string to the first
		@param:
			- string a: number to be added
	*/
	void operator+=(const string& a) {
		operator+=(BigInt(a));
	}
#pragma endregion Plus_Equals
#pragma region Minus_Equals
	///// SUBTRACTING AND SETTING /////

	/*
		Finds and sets the difference of two BigInts to the first
		@param:
			- BigInt a: number to be subtracted
	*/
	void operator-=(const BigInt& a) {
		cout << "Test";
	}

	/*
		Finds and sets the difference of Bigint and an int to the first
		@param:
			- int a: number to be subtracted
	*/
	void operator-=(const int& a) {
		operator-=(BigInt(a));
	}

	/*
		Finds and sets the difference of Bigint and a double to the first
		@param:
			- double a: number to be subtracted
	*/
	void operator-=(const double& a) {
		operator-=(BigInt(a));
	}

	/*
		Finds and sets the difference of Bigint and a string to the first
		@param:
			- string a: number to be subtracted
	*/
	void operator-=(const string& a) {
		operator-=(BigInt(a));
	}
#pragma endregion Minus_Equals
#pragma region Times_Equals
	///// MULTIPLYING AND SETTING /////

	/*
		Finds and sets the product of two BigInts to the first
		@param:
			- BigInt a: number to be multiplied
	*/
	void operator*=(const BigInt& a) {
		cout << "Test";
	}

	/*
		Finds and sets the product of Bigint and an int to the first
		@param:
			- int a: number to be multiplied
	*/
	void operator*=(const int& a) {
		operator*=(BigInt(a));
	}

	/*
		Finds and sets the product of Bigint and a double to the first
		@param:
			- double a: number to be multiplied
	*/
	void operator*=(const double& a) {
		operator*=(BigInt(a));
	}

	/*
		Finds and sets the product of Bigint and a string to the first
		@param:
			- string a: number to be multiplied
	*/
	void operator*=(const string& a) {
		operator*=(BigInt(a));
	}
#pragma endregion Times_Equals
#pragma region Div_Equals
	///// DIVIDING AND SETTING /////

	/*
		Finds and sets the quotient of two BigInts to the first
		@param:
			- BigInt a: divisor
	*/
	void operator/=(const BigInt& a) {
		cout << "Test";
	}

	/*
		Finds and sets the quotient of Bigint and an int to the first
		@param:
			- int a: divisor
	*/
	void operator/=(const int& a) {
		operator/=(BigInt(a));
	}

	/*
		Finds and sets the quotient of Bigint and a double to the first
		@param:
			- double a: divisor
	*/
	void operator/=(const double& a) {
		operator/=(BigInt(a));
	}

	/*
		Finds and sets the quotient of Bigint and a string to the first
		@param:
			- string a: divisor
	*/
	void operator/=(const string& a) {
		operator/=(BigInt(a));
	}
#pragma endregion Div_Equals
#pragma region Incrementors
	/*
		Increments the selected BigInt
	*/
	void operator++() {

	}

	/*
		Decrements the selected BigInt
	*/
	void operator--() {

	}
#pragma endregion Incrementors
};
#pragma region Extras
/*
	Returns the absolute value of a selected BigInt
	@param:
		- BigInt a: value to be abs'd
	@return: the absolute value of a
*/
BigInt abs(BigInt a) {
	if (a.toString()[0] == '-') {
		return BigInt(a.toString().substr(1));
	}
	return BigInt(a.toString());
}

/*
	Returns the reverse of the selected BigInt
	@param:
		- BigInt a: value to be reversed
	@return: the reversed value of a
*/
BigInt rev(BigInt a) {
	string num = a.toString();
	bool flag = false;
	if (num[0] == '-') {
		num = num.substr(1);
		flag = true;
	}
	reverse(num.begin(), num.end());
	if (flag == true) {
		num = "-" + num;
	}
	return BigInt(num);
}
#pragma endregion Extras
#pragma region Extra_Math
/*
	Calculates the power of passed statement
	@param:
		- BigInt a: base
		- int b: exponent
	@return: The resulting BigInt
*/
BigInt pow(BigInt a, int b) {
	return BigInt(0);
}

/*
	Calculates the square root of the passed BigInt
	@param:
		- BigInt a: base
	@return: The resulting square root in BigInt form
*/
BigInt sqrt(BigInt a) {
	return BigInt(0);
}
#pragma endregion Extra_Math
ostream& operator<<(ostream& os, const BigInt& obj) {
	os << obj.num;
	return os;
}