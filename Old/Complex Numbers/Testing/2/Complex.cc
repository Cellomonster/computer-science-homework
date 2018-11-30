/*
File: Complex.cc
--------------------
Implements the Complex class

Author: Julian Triveri
10/30/18
*/

#include "Complex.h"
#include <string>
#include <iostream>

// Constructor: Complex();
// Creates a complex number with a value of 0

Complex::Complex(){
	r = 0;
	i = 0;
}

// Constructor: Complex(<real number>, <imaginary number>);
// Creates a complex number of <real>+<imaginary>*i

Complex::Complex(float r, float i){
	this->r = r;
	this->i = i;
}

// Constructor: Complex(<complex>);
// Creates a copy of a complex number

Complex::Complex(const Complex &c){
	this->r = c.getReal();
	this->i = c.getImag();
}

//Getters for real and rational parts of a complex number
float Complex::getReal() const{return r;};
float Complex::getImag() const{return i;};

//Setters for real and rational parts of a complex number
void Complex::setReal(float f){this->r = f;};
void Complex::setImag(float f){this->i = f;};

//Operator: c == <complex>
//Compares the complex number to another for equal values
bool Complex::operator==(const Complex &c){
	return (r == c.getReal() && i == c.getImag());
}

//Operator: c != <complex>
//Compares the complex number to another for unequal values
bool Complex::operator!=(const Complex &c){
	return !(*this == c);
}

//Operator: <stream> << <complex>
//Adds a pretty-printed complex number to a stream
std::ostream& operator<<(std::ostream &os, const Complex &c){

	const float r = c.getReal();
	const float i = c.getImag();

	//Just '0' if both numbers are 0
	if(!r && !i)
		return os << "0";

	//Add real number if not zero
	if(r){
		os << r;

		//Show '+' if imaginary number isn't negative
		if(i > 0)
			os << "+";
	}

	//If imaginary number isn't 0
	if(i){

		//Add imaginary number if isn't 1
		if(i * i != 1)
				os << i;

		//If -1, add '-i'
		os << ((i == -1)? "-i" : "i");
	}

	//Debug - not pretty print
	// os << c.getReal() << "+" << c.getImag();

	return os;
}

//Operator: <complex> + <complex>
//Returns the sum of two complex numbers
Complex operator+(const Complex &c1, const Complex &c2){
	return Complex(c1.getReal() + c2.getReal(), c1.getImag() + c2.getImag());
}

//Operator: <complex> - <complex>
//Returns the value of one complex number subtracted from another
Complex operator-(const Complex &c1, const Complex &c2){
	return Complex(c1.getReal() - c2.getReal(), c1.getImag() - c2.getImag());
}

//Operator: <complex> * <complex>
//Returns the product of two complex numbers
Complex operator*(const Complex &c1, const Complex &c2){
	const float a = c1.getReal();
	const float b = c1.getImag();
	const float c = c2.getReal();
	const float d = c2.getImag();

	return Complex(a*c - b*d, a*d + b*c);
}

//Operator: <complex> / <complex>
//Returns the value of one complex number divided by another
Complex operator/(const Complex &c1, const Complex &c2){
	const float a = c1.getReal();
	const float b = c1.getImag();
	const float c = c2.getReal();
	const float d = c2.getImag();

	return Complex ((a*c+b*d)/(c*c+d*d), (b*c-a*d)/(c*c+d*d));
}

//Operator: <complex> / <float>
//Returns the sum of a complex number and a real number
Complex operator+(const Complex &c, const float &f){
	return Complex(c.getReal() + f, c.getImag());
}

//Operator: <complex> - <float>
//Returns the value of a float subtracted from a complex number
Complex operator-(const Complex &c, const float &f){
	return Complex(c.getReal() - f, c.getImag());
}

//Operator: <complex> * <float>
//Returns the product of a complex number and a real number
Complex operator*(const Complex &c, const float &f){
	return Complex(c.getReal() * f, c.getImag() * f);
}

//Operator: <complex> / <float>
//Returns the value of a complex number divided by a float
Complex operator/(const Complex &c, const float &f){
	return Complex(c.getReal() / f, c.getImag() / f);
}

//Operator: -<complex>
//Returns the negative value of a complex number
Complex operator-(const Complex &c){
	return Complex(-c.getReal(), -c.getImag());
}

//Operator: ~<complex>
//Returns the complex conjugate of a complex number
Complex operator~(const Complex &c){
	return Complex(c.getReal(), -c.getImag());
}

//Operator: <complex>^<int>
//Returns the value of a complex number to a given power
Complex operator^(const Complex &c, const int&p){
	Complex toReturn = Complex(c);

	for(int i = 0; i < p - 1; i++) toReturn = toReturn * c;

	return toReturn;
}

