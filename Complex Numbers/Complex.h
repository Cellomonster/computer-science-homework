/*
File: Complex.h
--------------------
Represents complex number

Author: Julian Triveri
10/30/18
*/

#ifndef complexNum_h
#define complexNum_h

#include <string>
#include <iostream>

/*
 * Class: Complex
 *------------------------------
 * Represents a complex number
 */
class Complex{
private:
	float r;
	float i;

public:

	Complex();
	Complex(float r, float i);
	Complex(const Complex &c);

	float getReal() const;
	float getImag() const;

	void setReal(float);
	void setImag(float);

	void operator=(const Complex&);

	bool operator==(const Complex&);
	bool operator!=(const Complex&);

	friend std::ostream& operator<<(std::ostream&, const Complex&);

	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

	friend Complex operator+(const Complex&, const float&);
	friend Complex operator-(const Complex&, const float&);
	friend Complex operator*(const Complex&, const float&);
	friend Complex operator/(const Complex&, const float&);

	friend Complex operator-(const Complex&);
	friend Complex operator~(const Complex&);
	friend Complex operator^(const Complex&, const int&);

};

std::ostream& operator<<(std::ostream& os, const Complex&);

Complex operator+(const Complex&, const Complex&);
Complex operator-(const Complex&, const Complex&);
Complex operator*(const Complex&, const Complex&);
Complex operator/(const Complex&, const Complex&);

Complex operator+(const Complex&, const float&);
Complex operator-(const Complex&, const float&);
Complex operator*(const Complex&, const float&);
Complex operator/(const Complex&, const float&);

Complex operator-(const Complex&);
Complex operator~(const Complex&);
Complex operator^(const Complex&, const int&);

#endif