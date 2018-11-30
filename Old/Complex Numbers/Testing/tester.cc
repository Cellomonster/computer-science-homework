#define RED "\033[1;31m"
#define RST "\033[0m"

#include "1/Complex.h"
#include "2/Complex.h"
#include <iostream>
#include <sstream>
using namespace std;

void assert(bool b){
	if(!b) cout << RED << "failed!" << RST << endl;
}

// Helper method for float math.
// Returns true if the two numbers are "close", AKA within 0.001.
bool isClose(float a, float b) {
	return -0.001 < a-b && a-b < 0.001;
}

void test_Complex() {
	cout << "test_Complex:" << endl;
	Complex c1_1;

	assert(c1_1.getReal() == 0);
	assert(c1_1.getImag() == 0);
}
void test_ComplexCopy() {
	cout << "test_ComplexCopy:" << endl;
	Complex c2_1;
	c2_1.setReal(1);
	c2_1.setImag(2);

	Complex c2_2(c2_1);
	assert(c2_2.getReal() == 1);
	assert(c2_2.getImag() == 2);
}
void test_ComplexFloats() {
	cout << "test_ComplexFloats:" << endl;
	Complex c3_1(1, 2);

	assert(c3_1.getReal() == 1);
	assert(c3_1.getImag() == 2);
}
void test_Addition() {
	cout << "test_Addition:" << endl;
	Complex c4_1(1, 2);
	Complex c4_2(10, 20);

	// Test Complex-Complex addition
	Complex c4_3 = c4_1 + c4_2;
	assert(c4_3.getReal() == 11);
	assert(c4_3.getImag() == 22);

	// Test Complex-float addition
	Complex c4_4 = c4_1 + 5.5;
	assert(c4_4.getReal() == 6.5);
	assert(c4_4.getImag() == 2.0);

	// Test Complex-int addition
	Complex c4_5 = c4_2 + 5;
	assert(c4_5.getReal() == 15);
	assert(c4_5.getImag() == 20);
}
void test_Subtraction() {
	cout << "test_Subtraction:" << endl;
	Complex c5_1(1, 2);
	Complex c5_2(10, 20);

	// Test Complex-Complex subtraction
	Complex c5_3 = c5_1 - c5_2;
	assert(c5_3.getReal() == -9);
	assert(c5_3.getImag() == -18);

	// Test Complex-float subtraction
	Complex c5_4 = c5_1 - 5.5;
	assert(c5_4.getReal() == -4.5);
	assert(c5_4.getImag() == 2.0);

	// Test Complex-int subtraction
	Complex c5_5 = c5_2 - 5;
	assert(c5_5.getReal() == 5);
	assert(c5_5.getImag() == 20);
}

void test_Multiplication() {
	cout << "test_Multiplication:" << endl;
	Complex c6_1(0, 0);
	Complex c6_2(1, 6);
	Complex c6_3(-0.9, 10.2);

	// Test Complex-Complex multiplication
	Complex c6_4 = c6_1 * c6_2;
	assert(c6_4.getReal() == 0.0);
	assert(c6_4.getImag() == 0.0);
	Complex c6_5 = c6_3 * c6_1;
	assert(c6_5.getReal() == 0.0);
	assert(c6_5.getImag() == 0.0);
	Complex c6_6 = c6_3 * c6_2;
	assert(isClose(c6_6.getReal(), -62.1));
	assert(isClose(c6_6.getImag(), 4.8));

	// Test Complex-float multiplication
	Complex c6_7 = c6_1 * 4.0;
	assert(c6_7.getReal() == 0.0);
	assert(c6_7.getImag() == 0.0);
	Complex c6_8 = c6_2 * -4.0;;
	assert(isClose(c6_8.getReal(), -4.0));
	assert(isClose(c6_8.getImag(), -24.0));
	Complex c6_9 = c6_3 * 3.5;
	assert(isClose(c6_9.getReal(), -3.15));
	assert(isClose(c6_9.getImag(), 35.7));

	// Test Complex-int multiplication
	Complex c6_10 = c6_1 * 4;
	assert(c6_10.getReal() == 0.0);
	assert(c6_10.getImag() == 0.0);
	Complex c6_11 = c6_2 * -4;
	assert(isClose(c6_11.getReal(), -4.0));
	assert(isClose(c6_11.getImag(), -24.0));
}

void test_Division() {
	cout << "test_Division:" << endl;
	Complex c7_1(0, 0);
	Complex c7_2(1, 6);
	Complex c7_3(-0.9, 10.2);

	// Test Complex-Complex division
	Complex c7_4 = c7_1 / c7_2;
	assert(c7_4.getReal() == 0.0);
	assert(c7_4.getImag() == 0.0);
	Complex c7_5 = c7_3 / c7_2;
	assert(isClose(c7_5.getReal(), 1.630)); // Since floats are unstable, only check that the calculation is close to the right answer.
	assert(isClose(c7_5.getImag(), 0.4216));
	Complex c7_6 = c7_2 / c7_3;
	assert(isClose(c7_6.getReal(), 0.575));
	assert(isClose(c7_6.getImag(), -0.148784));

	// Test Complex-float division
	Complex c7_7 = c7_1 / 4.0;
	assert(c7_7.getReal() == 0.0);
	assert(c7_7.getImag() == 0.0);
	Complex c7_8 = c7_2 / -4.0;
	assert(isClose(c7_8.getReal(), -0.25));
	assert(isClose(c7_8.getImag(), -1.5));
	Complex c7_9 = c7_3 / 3.5;
	assert(isClose(c7_9.getReal(), -0.2571));
	assert(isClose(c7_9.getImag(), 2.9143));

	// Test Complex-int division
	Complex c7_10 = c7_1 / 4;
	assert(c7_10.getReal() == 0.0);
	assert(c7_10.getImag() == 0.0);
	Complex c7_11 = c7_2 / -4;
	assert(isClose(c7_11.getReal(), -0.25));
	assert(isClose(c7_11.getImag(), -1.5));
}

void test_Negation() {
	cout << "test_Negation:" << endl;
	Complex c8_1(0, 0);
	Complex c8_2(1, 6);
	Complex c8_3(-0.9, 10.2);

	assert(-c8_1.getReal() == 0.0);
	assert(-c8_1.getImag() == 0.0);

	assert(-c8_2.getReal() == -1);
	assert(-c8_2.getImag() == -6);

	assert(isClose(-c8_3.getReal(), 0.9));
	assert(isClose(-c8_3.getImag(), -10.2));
}

void test_Conjugation() {
	cout << "test_Conjugation:" << endl;
	Complex c9_1(0, 0);
	Complex c9_2(1, 6);
	Complex c9_3(-0.9, 10.2);

	assert((~c9_1).getReal() == 0.0);
	assert((~c9_1).getImag() == 0.0);

	assert((~c9_2).getReal() == 1);
	assert((~c9_2).getImag() == -6);

	assert(isClose((~c9_3).getReal(), -0.9));
	assert(isClose((~c9_3).getImag(), -10.2));
}

void test_Exponentiation() {
	cout << "test_Exponentiation:" << endl;
	Complex c10_1(0, 0);
	Complex c10_2(1, 6);
	Complex c10_3(-0.9, 10.2);

	Complex c10_4 = c10_1 ^ 3;
	assert(c10_4.getReal() == 0.0);
	assert(c10_4.getImag() == 0.0);

	Complex c10_5 = c10_2 ^ 3;
	assert(c10_5.getReal() == -107);
	assert(c10_5.getImag() == -198);

	Complex c10_6 = c10_3 ^ 3;
	assert(isClose(c10_6.getReal(), 280.179));
	assert(isClose(c10_6.getImag(), -1036.422));
}

// Uses a stringstream to convert a complex number to a string, and then checks equality with the provided string.
// Returns true if the Complex number's string representation is exactly s.
// Helper method for unit testing.
bool complexIsString(const Complex& c, string s) {
	stringstream str;
	str << c;
	return s == str.str();
}

void test_StringConversion() {
	// Test all different combinations of signs and zeros
	assert(complexIsString(Complex(-6, -9), "-6-9i"));
	assert(complexIsString(Complex(-6, 5), "-6+5i"));
	assert(complexIsString(Complex(4, -9), "4-9i"));
	assert(complexIsString(Complex(4, 5), "4+5i"));
	assert(complexIsString(Complex(0, -9), "-9i"));
	assert(complexIsString(Complex(0, 5), "5i"));
	assert(complexIsString(Complex(-6, 0), "-6"));
	assert(complexIsString(Complex(4, 0), "4"));
	assert(complexIsString(Complex(0, 0), "0"));

	// Test non-integer values.
	assert(complexIsString(Complex(6.5, 1200), "6.5+1200i"));
	assert(complexIsString(Complex(101, -0.09), "101-0.09i"));
	assert(complexIsString(Complex(-4.3, 9), "-4.3+9i"));
	assert(complexIsString(Complex(-4, -500.12), "-4-500.12i"));
}

int main() {
	test_Complex();
	test_ComplexCopy();
	test_ComplexFloats();
	test_Addition();
	test_Subtraction();
	test_Multiplication();
	test_Division();
	test_Negation();
	test_Conjugation();
	test_Exponentiation();

	test_StringConversion();
	return 0;
}

