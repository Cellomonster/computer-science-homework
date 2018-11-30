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

//Class: Complex
//Represents a complex number
class Complex{
private:
	float r;
	float i;

public:

	//Constructors
	Complex();
	Complex(float r, float i);
	Complex(const Complex &c);

	//Getters
	float getReal() const;
	float getImag() const;

	//Setters
	void setReal(float);
	void setImag(float);

	//Comparison operators
	bool operator==(const Complex&);
	bool operator!=(const Complex&);

	//Stream operator
	friend std::ostream& operator<<(std::ostream&, const Complex&);

	//Math operators: complex on complex
	friend Complex operator+(const Complex&, const Complex&);
	friend Complex operator-(const Complex&, const Complex&);
	friend Complex operator*(const Complex&, const Complex&);
	friend Complex operator/(const Complex&, const Complex&);

	//Math operators: float on complex
	friend Complex operator+(const Complex&, const float&);
	friend Complex operator-(const Complex&, const float&);
	friend Complex operator*(const Complex&, const float&);
	friend Complex operator/(const Complex&, const float&);

	//Math operators: etc
	friend Complex operator-(const Complex&);
	friend Complex operator~(const Complex&);
	friend Complex operator^(const Complex&, const int&);

};

// //Stream operator
// std::ostream& operator<<(std::ostream& os, const Complex&);

// //Math operators: complex on complex
// Complex operator+(const Complex&, const Complex&);
// Complex operator-(const Complex&, const Complex&);
// Complex operator*(const Complex&, const Complex&);
// Complex operator/(const Complex&, const Complex&);

// //Math operators: float on complex
// Complex operator+(const Complex&, const float&);
// Complex operator-(const Complex&, const float&);
// Complex operator*(const Complex&, const float&);
// Complex operator/(const Complex&, const float&);

// //Math operators: etc
// Complex operator-(const Complex&);
// Complex operator~(const Complex&);
// Complex operator^(const Complex&, const int&);

#endif