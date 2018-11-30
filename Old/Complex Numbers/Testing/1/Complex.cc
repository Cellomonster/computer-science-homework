//==============================================================
// Nicholas Reichert
// CS 173 - Project 7
// Complex.cc
// November 5, 2018
//
// Implementation of the Complex class
//
// Documentation is included in the Complex.h file for all of these functions.
//
//==============================================================

#include "Complex.h"

#include <sstream>


// Constructors
Complex::Complex() {
	real = 0.0;
	imag = 0.0;
}
// The copy constructor is implicitly defined.
Complex::Complex(float realPart, float imagPart) {
	real = realPart;
	imag = imagPart;
}

// Destructor
Complex::~Complex() {
}

// Getters and Setters
void Complex::setReal(float newReal) {
	real = newReal;
}
float Complex::getReal() {
	return real;
}
void Complex::setImag(float newImag) {
	imag = newImag;
}
float Complex::getImag() {
	return imag;
}

// Addition
Complex Complex::operator+(Complex other) {
	return Complex(real + other.real, imag + other.imag);
}
Complex Complex::operator+(float other) {
	return Complex(real + other, imag);
}
// Complex-int conversion is implicit, (Complex-float converion fulfills it.)

// Subtraction
Complex Complex::operator-(Complex other) {
	return Complex(real - other.real, imag - other.imag);
}
Complex Complex::operator-(float other) {
	return Complex(real - other, imag);
}
// Complex-int conversion is implicit, (Complex-float converion fulfills it.)

// Multiplication
Complex Complex::operator*(Complex other) {
	return Complex(real*other.real - imag*other.imag, imag*other.real + real*other.imag);
}
Complex Complex::operator*(float other) {
	return Complex(real*other, imag*other);
}
// Complex-int conversion is implicit, (Complex-float converion fulfills it.)

// Division
Complex Complex::operator/(Complex other) {
	float denom = other.real*other.real + other.imag*other.imag;
	return Complex( (real*other.real + imag*other.imag)/denom, (imag*other.real - real*other.imag)/denom );
}
Complex Complex::operator/(float other) {
	return Complex(real/other, imag/other);
}
// Complex-int conversion is implicit, (Complex-float converion fulfills it.)

// Compliment
Complex Complex::operator~() {
	return Complex(real, -imag);
}

// Negation
Complex Complex::operator-() {
	return Complex(-real, -imag);
}

// Raising to a integer power (repeated multiplication)
Complex Complex::operator^(int power) {
	Complex product(*this);
	for (int i=1; i<power; i++) {
		product = product*(*this); // *this derefrences the this (which is a pointer) to access the underlying object
	}

	return product;
}

// Assignment operator
Complex & Complex::operator=(Complex other) {
	real = other.real;
	imag = other.imag;

	return *this;
}

// Boolean operators
bool Complex::operator==(Complex other) {
	return (real==other.real) && (imag==other.imag);
}
bool Complex::operator!=(Complex other) {
	return !((*this)==other);
}

// Output operator to send to streams.
std::ostream & operator<<(std::ostream & os, Complex c) {
	std::stringstream outputStream;

	if (c.getReal() != 0.0) {
		outputStream << c.getReal();
		if (c.getImag() != 0) {
			if (c.getImag() < 0) {
				outputStream << "-" << -c.getImag() << "i";
			} else {
				outputStream << "+" << c.getImag() << "i";
			}
		}
	} else {
		if (c.getImag() != 0) {
			outputStream << c.getImag() << "i";
		} else {
			outputStream << c.getReal(); // Output "0" if both are 0.
		}
	}

	return os << outputStream.str();
}
