#include "test_pow.h"

using namespace std;
using namespace ln;

void TestDecomposExp() {
	vector<Number> v;
	{ // 3
		v.push_back(Number(2));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(3), Number(151)), v);
		v.clear();
	}
	{ // 9
		v.push_back(Number(8));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(9), Number(37)), v);
		v.clear();
	}
	{ // 13
		v.push_back(Number(8));
		v.push_back(Number(4));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(13), Number(67)), v);
		v.clear();
	}
	{ // 47
		v.push_back(Number(32));
		v.push_back(Number(8));
		v.push_back(Number(4));
		v.push_back(Number(2));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(47), Number(151)), v);
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
		ASSERT_EQUAL(decomposeExp(Number(255), Number(7)), v);
		v.clear();
	}
	{ // 259
		v.push_back(Number(256));
		v.push_back(Number(2));
		v.push_back(Number(1));
		ASSERT_EQUAL(decomposeExp(Number(259), Number(151)), v);
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
		ASSERT_EQUAL(decomposeExp(Number(4586),Number(151)), v);
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
		ASSERT_EQUAL(decomposeExp(Number(12379), Number(151)), v);
		v.clear();
	}
	{ // 134 217 728
		v.push_back(Number(134217728));
		ASSERT_EQUAL(decomposeExp(Number(134217728), Number(151)), v);
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
		ASSERT_EQUAL(decomposeExp(Number(45678940), Number(151)), v);
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
		ASSERT_EQUAL(decomposeExp(Number(1145324615), Number(151)), v);
		v.clear();
	}
}

void TestLength() {
	// base 2
	ASSERT_EQUAL(length(Number(31), 2), 5);
	ASSERT_EQUAL(length(Number(32), 2), 6);
	ASSERT_EQUAL(length(Number(33), 2), 6);
	ASSERT_EQUAL(length(Number(1023), 2), 10);
	ASSERT_EQUAL(length(Number(1024), 2), 11);
	ASSERT_EQUAL(length(Number(1025), 2), 11);
	ASSERT_EQUAL(length(Number(1028476), 2), 20);
	ASSERT_EQUAL(length(Number(1048576), 2), 21);
	ASSERT_EQUAL(length(Number(1048576), 2), 21);
	ASSERT_EQUAL(length(Number(17176219484), 2), 34);
	ASSERT_EQUAL(length(Number(17179869184), 2), 35);
	ASSERT_EQUAL(length(Number(17676821184), 2), 35);
	// base 10
	ASSERT_EQUAL(length(Number(41), 10), 2);
	ASSERT_EQUAL(length(Number(42), 10), 2);
	ASSERT_EQUAL(length(Number(43), 10), 2);
	ASSERT_EQUAL(length(Number(1088), 10), 4);
	ASSERT_EQUAL(length(Number(1089), 10), 4);
	ASSERT_EQUAL(length(Number(22139), 10), 5);
	ASSERT_EQUAL(length(Number(35936), 10), 5);
	ASSERT_EQUAL(length(Number(333245), 10), 6);
	ASSERT_EQUAL(length(Number(39135392), 10), 8);
	ASSERT_EQUAL(length(Number(39535382), 10), 8);
	ASSERT_EQUAL(length(Number(1406408618240), 10), 13);
	ASSERT_EQUAL(length(Number(1406408618242), 10), 13);
	// base 16
	ASSERT_EQUAL(length(Number(3), 16), 1);
	ASSERT_EQUAL(length(Number(52), 16), 2);
	ASSERT_EQUAL(length(Number(141), 16), 2);
	ASSERT_EQUAL(length(Number(543), 16), 3);
	ASSERT_EQUAL(length(Number(7412), 16), 4);
	ASSERT_EQUAL(length(Number(20163), 16), 4);
	ASSERT_EQUAL(length(Number(91001), 16), 5);
	ASSERT_EQUAL(length(Number(52841867194), 16), 9);
	ASSERT_EQUAL(length(Number(92841867194), 16), 10);
	ASSERT_EQUAL(length(Number(323841888194), 16), 10);
	ASSERT_EQUAL(length(Number(8198418170944), 16), 11);
	ASSERT_EQUAL(length(Number(234744323678459038), 16), 15);
	ASSERT_EQUAL(length(Number(534944623678459038), 16), 15);
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

void TestPowNumber() {

	// mod 3571
	ASSERT_EQUAL(powNumber(Number(12), Number(5), Number(3571)), Number(2433));// 12^(5) = 2 433
	ASSERT_EQUAL(powNumber(Number(15), Number(0), Number(3571)), Number(1));// 15^(0) = 1
	ASSERT_EQUAL(powNumber(Number(1), Number(155), Number(3571)), Number(1));// 1^(155) = 1
	ASSERT_EQUAL(powNumber(Number(2), Number(52), Number(3571)), Number(3255));// 2^(52) = 3 255
	ASSERT_EQUAL(powNumber(Number(3), Number(65), Number(3571)), Number(627));// 3^(65) = 627
	ASSERT_EQUAL(powNumber(Number(256), Number(44), Number(3571)), Number(1344));// 256^(44) = 1 344
	ASSERT_EQUAL(powNumber(Number(18901), Number(101), Number(3571)), Number(2352));// 18 901^(101) = 2 352
	ASSERT_EQUAL(powNumber(Number(99999), Number(999), Number(3571)), Number(1347));// 99 999^(999) = 1 347
	ASSERT_EQUAL(powNumber(Number(352), Number(765), Number(3571)), Number(879));// 352^(765) = 879
	ASSERT_EQUAL(powNumber(Number(12345), Number(865), Number(3571)), Number(2255));// 12 345^(865) = 2 255
	ASSERT_EQUAL(powNumber(Number(3122213321), Number(123218621), Number(3571)), Number(1834));// 3 122 213 321^(123 218 621) = 1 834
	ASSERT_EQUAL(powNumber(Number(31222133), Number(1232186), Number(3571)), Number(2180));// 31 222 133^(1 232 186) = 2 180
	ASSERT_EQUAL(powNumber(Number(312221332142), Number(1232186214), Number(3571)), Number(3128));// 312 221 332 142^(1 232 186 214) = 3 128
	ASSERT_EQUAL(powNumber(Number(9128211376), Number(522687621), Number(3571)), Number(1166));// 9 128 211 376^(522 687 621) = 1 166
	ASSERT_EQUAL(powNumber(Number(75902854), Number(398561700), Number(3571)), Number(2831));// 75 902 854^(398 561 700) = 2 831
	ASSERT_EQUAL(powNumber(Number(54309867421), Number(132590184), Number(3571)), Number(2706));// 54 309 867 421^(132 590 184) = 2 706

	// mod 151
	Number mod151(151);
	ASSERT_EQUAL(powNumber(Number(12), Number(5), mod151), powNaive(Number(12), Number(5), mod151));
	ASSERT_EQUAL(powNumber(Number(132178), Number(52132), mod151), powNaive(Number(132178), Number(52132), mod151));
	ASSERT_EQUAL(powNumber(Number(418908), Number(213), mod151), powNaive(Number(418908), Number(213), mod151));
	ASSERT_EQUAL(powNumber(Number(2132), Number(541244), mod151), powNaive(Number(2132), Number(541244), mod151));
	ASSERT_EQUAL(powNumber(Number(1213231), Number(478985), mod151), powNaive(Number(1213231), Number(478985), mod151));
	ASSERT_EQUAL(powNumber(Number(890123), Number(7), mod151), powNaive(Number(890123), Number(7), mod151));
	ASSERT_EQUAL(powNumber(Number(9999), Number(9999), mod151), powNaive(Number(9999), Number(9999), mod151));
	ASSERT_EQUAL(powNumber(Number(13212), Number(78909), mod151), powNaive(Number(13212), Number(78909), mod151));
	ASSERT_EQUAL(powNumber(Number(628974), Number(132321), mod151), powNaive(Number(628974), Number(132321), mod151));
	ASSERT_EQUAL(powNumber(Number(421798), Number(555), mod151), powNaive(Number(421798), Number(555), mod151));
	ASSERT_EQUAL(powNumber(Number(12345678), Number(9876), mod151), powNaive(Number(12345678), Number(9876), mod151));
	ASSERT_EQUAL(powNumber(Number(4132), Number(523213), mod151), powNaive(Number(4132), Number(523213), mod151));
	ASSERT_EQUAL(powNumber(Number(122321), Number(5757891), mod151), powNaive(Number(122321), Number(5757891), mod151));

	// mod 67
	Number mod67(67);
	ASSERT_EQUAL(powNumber(Number(12), Number(5), mod67), powNaive(Number(12), Number(5), mod67));
	ASSERT_EQUAL(powNumber(Number(345), Number(52), mod67), powNaive(Number(345), Number(52), mod67));
	ASSERT_EQUAL(powNumber(Number(875), Number(98), mod67), powNaive(Number(875), Number(98), mod67));
	ASSERT_EQUAL(powNumber(Number(6587), Number(167), mod67), powNaive(Number(6587), Number(167), mod67));
	ASSERT_EQUAL(powNumber(Number(94356), Number(53122), mod67), powNaive(Number(94356), Number(53122), mod67));
	ASSERT_EQUAL(powNumber(Number(85133), Number(23511), mod67), powNaive(Number(85133), Number(23511), mod67));
	ASSERT_EQUAL(powNumber(Number(75902854), Number(3187329), mod67), powNaive(Number(75902854), Number(3187329), mod67));
	ASSERT_EQUAL(powNumber(Number(54367767421), Number(832590184), mod67), powNaive(Number(54367767421), Number(832590184), mod67));
	ASSERT_EQUAL(powNumber(Number(48979789), Number(1), mod67), powNaive(Number(48979789), Number(1), mod67));
	ASSERT_EQUAL(powNumber(Number(457610032), Number(457610032), mod67), powNaive(Number(457610032), Number(457610032), mod67));

	// for diff mod
	vector<Number> mod = { 1657, 1801, 1951, 2269, 2437, 2791, 3169, 3571, 4219, 4447, 5167, 5419, 6211, 7057, 7351, 8269, 9241, 10267, 11719, 12097, 13267, 13669, 16651, 19441, 19927, 22447, 23497, 24571, 25117, 26227, 27361, 33391, 35317, 10093, 12289, 13873, 18253, 20173, 21169, 22189, 28813, 37633, 43201, 47629, 60493, 63949, 65713, 69313, 73009, 76801, 84673, 106033, 108301, 112909, 115249 };
	for (auto x : mod) {
		ASSERT_EQUAL(powNumber(Number(89190), Number(576275), x), powNaive(Number(89190), Number(576275), x));
		ASSERT_EQUAL(powNumber(Number(9761381), Number(4187229), x), powNaive(Number(9761381), Number(4187229), x));
		ASSERT_EQUAL(powNumber(Number(74382360021), Number(26256), x), powNaive(Number(74382360021), Number(26256), x));
		ASSERT_EQUAL(powNumber(Number(9999), Number(9999), x), powNaive(Number(9999), Number(9999), x));
		ASSERT_EQUAL(powNumber(Number(8700012), Number(8700012), x), powNaive(Number(8700012), Number(8700012), x));
	}

	// rand exp
	srand(4541);
	for (int i = 0; i < 100; i++) {
		Number random = rand();
		ASSERT_EQUAL(powNumber(Number(1789), random, Number(16127)), powNaive(Number(1789), random, Number(16127)));
		ASSERT_EQUAL(powNumber(Number(9761381), random, Number(16127)), powNaive(Number(9761381), random, Number(16127)));
		ASSERT_EQUAL(powNumber(Number(9999), random, Number(16127)), powNaive(Number(9999), random, Number(16127)));
	}

	// rand num
	srand(95698);
	for (int i = 0; i < 100; i++) {
		Number random = rand();
		ASSERT_EQUAL(powNumber(random, Number(555), Number(16769023)), powNaive(random, Number(555), Number(16769023)));
		ASSERT_EQUAL(powNumber(random, Number(86771), Number(16769023)), powNaive(random, Number(86771), Number(16769023)));
		ASSERT_EQUAL(powNumber(random, Number(976401), Number(16769023)), powNaive(random, Number(976401), Number(16769023)));
	}
}