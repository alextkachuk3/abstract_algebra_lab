#include "test_pow.h"

using namespace std;
using namespace ln;

void TestPowNumber() {
	// mod 3571
	ASSERT_EQUAL(powNumber(Number(12),Number(5)),Number(2433));// 12^(5) = 2 433
	ASSERT_EQUAL(powNumber(Number(15), Number(0)), Number(1));// 15^(0) = 1
	ASSERT_EQUAL(powNumber(Number(1), Number(155)), Number(1));// 1^(155) = 1
	ASSERT_EQUAL(powNumber(Number(2), Number(52)), Number(3255));// 2^(52) = 3 255
	ASSERT_EQUAL(powNumber(Number(3), Number(65)), Number(627));// 3^(65) = 627
	ASSERT_EQUAL(powNumber(Number(256), Number(44)), Number(1344));// 256^(44) = 1 344
	ASSERT_EQUAL(powNumber(Number(18901), Number(101)), Number(2352));// 18 901^(101) = 2 352
	ASSERT_EQUAL(powNumber(Number(99999), Number(999)), Number(1347));// 99 999^(999) = 1 347
	ASSERT_EQUAL(powNumber(Number(352), Number(765)), Number(879));// 352^(765) = 879
	ASSERT_EQUAL(powNumber(Number(12345), Number(865)), Number(2255));// 12 345^(865) = 2 255
	ASSERT_EQUAL(powNumber(Number(31222133), Number(1232186)), Number(2180));// 31 222 133^(1 232 186) = 2 180
}


void TestDecomposExp() {
	vector<Number> v;
	{ // 3
		v.push_back(Number(2));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(3)), v);
		v.clear();
	}
	{ // 9
		v.push_back(Number(8));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(9)), v);
		v.clear();
	}
	{ // 13
		v.push_back(Number(8));
		v.push_back(Number(4));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(13)), v);
		v.clear();
	}
	{ // 47
		v.push_back(Number(32));
		v.push_back(Number(8));
		v.push_back(Number(4));
		v.push_back(Number(2));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(47)), v);
		v.clear();
	}
	{ // 255
		v.push_back(Number(128));
		v.push_back(Number(64));
		v.push_back(Number(32));
		v.push_back(Number(16));
		v.push_back(Number(8));
		v.push_back(Number(4));
		v.push_back(Number(2));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(255)), v);
		v.clear();
	}
	{ // 259
		v.push_back(Number(256));
		v.push_back(Number(2));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(259)), v);
		v.clear();
	}
	{ // 4 586
		v.push_back(Number(4096));
		v.push_back(Number(256));
		v.push_back(Number(128));
		v.push_back(Number(64));
		v.push_back(Number(32));
		v.push_back(Number(8));
		v.push_back(Number(2));
		ASSERT_EQUAL(decomposeExp(Number(4586)), v);
		v.clear();
	}
	{ // 12 379
		v.push_back(Number(8192));
		v.push_back(Number(4096));
		v.push_back(Number(64));
		v.push_back(Number(16));
		v.push_back(Number(8));
		v.push_back(Number(2));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(12379)), v);
		v.clear();
	}
	{ // 134 217 728
		v.push_back(Number(134217728));
		ASSERT_EQUAL(decomposeExp(Number(134217728)), v);
		v.clear();
	}
	{ // 45 678 940
		v.push_back(Number(33554432));
		v.push_back(Number(8388608));
		v.push_back(Number(2097152));
		v.push_back(Number(1048576));
		v.push_back(Number(524288));
		v.push_back(Number(65536));
		v.push_back(Number(256));
		v.push_back(Number(64));
		v.push_back(Number(16));
		v.push_back(Number(8));
		v.push_back(Number(4));
		ASSERT_EQUAL(decomposeExp(Number(45678940)), v);
		v.clear();
	}
	{ // 1 145 324 615
		v.push_back(Number(1073741824));
		v.push_back(Number(67108864));
		v.push_back(Number(4194304));
		v.push_back(Number(262144));
		v.push_back(Number(16384));
		v.push_back(Number(1024));
		v.push_back(Number(64));
		v.push_back(Number(4));
		v.push_back(Number(2));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(1145324615)), v);
		v.clear();
	}
}

void TestLength() {
	// base 2
	ASSERT_EQUAL(length(Number(31), Number(2)), 5);
	ASSERT_EQUAL(length(Number(32),Number(2)), 6);
	ASSERT_EQUAL(length(Number(33), Number(2)), 6);
	ASSERT_EQUAL(length(Number(1023), Number(2)), 10);
	ASSERT_EQUAL(length(Number(1024), Number(2)), 11);
	ASSERT_EQUAL(length(Number(1025), Number(2)), 11);
	ASSERT_EQUAL(length(Number(1028476), Number(2)), 20);
	ASSERT_EQUAL(length(Number(1048576), Number(2)), 21);
	ASSERT_EQUAL(length(Number(1048576), Number(2)), 21);
    ASSERT_EQUAL(length(Number(17176219484), Number(2)), 34);
	ASSERT_EQUAL(length(Number(17179869184), Number(2)), 35);
	ASSERT_EQUAL(length(Number(17676821184), Number(2)), 35);
	// base 33
	ASSERT_EQUAL(length(Number(41), Number(33)), 2);
	ASSERT_EQUAL(length(Number(42), Number(33)), 2);
	ASSERT_EQUAL(length(Number(43), Number(33)), 2);
	ASSERT_EQUAL(length(Number(1088), Number(33)), 2);
	ASSERT_EQUAL(length(Number(1089), Number(33)), 3);
	ASSERT_EQUAL(length(Number(22139), Number(33)), 3); 
	ASSERT_EQUAL(length(Number(35936), Number(33)), 3);
	ASSERT_EQUAL(length(Number(333245), Number(33)), 4);
	ASSERT_EQUAL(length(Number(39135392), Number(33)), 5);
	ASSERT_EQUAL(length(Number(39535382), Number(33)), 6);
	ASSERT_EQUAL(length(Number(1406408618240), Number(33)), 8);
	ASSERT_EQUAL(length(Number(1406408618242), Number(33)), 9);
	// base 142
	ASSERT_EQUAL(length(Number(3), Number(142)), 1);
	ASSERT_EQUAL(length(Number(52), Number(142)), 1);
	ASSERT_EQUAL(length(Number(141), Number(142)), 1);
	ASSERT_EQUAL(length(Number(543), Number(142)), 2);
	ASSERT_EQUAL(length(Number(7412), Number(142)), 2);
	ASSERT_EQUAL(length(Number(20163), Number(142)), 2);
	ASSERT_EQUAL(length(Number(91001), Number(142)), 3);
	ASSERT_EQUAL(length(Number(52841867194), Number(142)), 5);
	ASSERT_EQUAL(length(Number(92841867194), Number(142)), 6);
	ASSERT_EQUAL(length(Number(323841888194), Number(142)), 6);
	ASSERT_EQUAL(length(Number(8198418170944), Number(142)), 7);
	ASSERT_EQUAL(length(Number(234744323678459038), Number(142)), 9);
	ASSERT_EQUAL(length(Number(534944623678459038), Number(142)), 9);
}

void TestGcd() {
	// gcd(Number(*1*),Number(*2*))
	Number a(2956);
	Number b(2833);
	ASSERT_EQUAL(gcdExtended(Number(180), Number(150), a, b), 30);
	a = Number(1337);
	b = Number(279);
	ASSERT_EQUAL(gcdExtended(Number(1680), Number(64), a, b), 16);
	a = Number(1515);
	b = Number(1257);
	ASSERT_EQUAL(gcdExtended(Number(96450), Number(125), a, b), 25);
	a = Number(3445);
	b = Number(1829);
	ASSERT_EQUAL(gcdExtended(Number(1248688), Number(462424), a, b), 8);
	a = Number(3231);
	b = Number(91);
	ASSERT_EQUAL(gcdExtended(Number(187488), Number(255103960), a, b), 248);
	a = Number(676);
	b = Number(713);
	ASSERT_EQUAL(gcdExtended(Number(3142510475), Number(298335019905), a, b), 3055);
}