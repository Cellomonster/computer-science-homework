//==============================================================
// Nicholas Reichert
// CS 173 - Project 7
// Complex.h
// November 5, 2018
//
// Header file for a Complex numbers class.
//
// The Complex class represents a complex number (a+bi),
// and allow basic arithmetic operations to be performed with it.
// The two components of the class (a & b) are stored as floats.
//
//==============================================================

#ifndef _Complex_h
#define _Complex_h

#include <iostream>

class Complex {

public:
	// Constructors
	
	// Default constructor.
	// Initializes to 0+0i
	Complex();
	// Constructor with values
	// a+bi
	// Parameters:
	//   float realPart - the real part (a) of the complex number
	//   float imagPart - the imaginary part (b) of the complex number
	Complex(float realPart, float imagPart);

	// Destructors
	// Destroys the complex number object.
	// This currently does nothing.
	~Complex();

	// Getters and Setters

	// Sets the real part to the specified value
	// Parameters:
	//   int newReal - the new real part
	void setReal(float newReal);
	// Outputs the real part of this complex number
	// Returns: float - the real part of the number
	float getReal();
	// Sets the imaginary part to the specified value
	// Parameters:
	//   int newImag - the new imaginary part
	void setImag(float newImag);
	// Outputs the imaginary part of this complex number
	// Returns: float - the imaginary part of the number
	float getImag();

	// Arithmetic operators

	// Adds together the two complex numbers
	// (a+bi) + (c+di) = (a+b)+(c+d)i
	// Parameters:
	//   Complex other - the other complex number to add to this one
	// Returns: Complex - the sum of the two numbers
	Complex operator+(Complex other);
	// Adds together the complex number and a float (real number).
	// (a+bi) + r = (a+r)+bi
	// Parameters:
	//   float other - the other real number to add to this one
	// Returns: Complex - the sum of the two numbers
	Complex operator+(float other);

	// Subtracts a float from this complex number
	// (a+bi) - (c+di) = (a-b)+(c-d)i
	// Parameters:
	//   Complex other - the other number to subtract from this one.
	// Returns: Complex - the output
	Complex operator-(Complex other);
	// Subtracts a float from this complex number
	// (a+bi) - r = (a-r)+bi
	// Parameters:
	//   float other - the other real number to subtract from this one
	// Returns: Complex - the output
	Complex operator-(float other);

	// Multiplies the two complex numbers
	// (a+bi) * (c+di) = (ac-bd)+(bc+ad)i
	// Parameters:
	//   Complex other - the other complex number to multiply with this one
	// Returns: Complex - the product of the two numbers
	Complex operator*(Complex other);
	// Multiplies together the complex number and a float (real number).
	// (a+bi)*r = ra + (rb)i
	// Parameters:
	//   float other - the other real number to multiply with this one
	// Returns: Complex - the product of the two numbers
	Complex operator*(float other);

	// Divides the two complex numbers
	// (a+bi) / (c+di) = ((ac+bd)/(c^2+d^2))+((bc-ad)/(c^2+d^2))i
	// Parameters:
	//   Complex other - the other complex number to divide this one by
	// Returns: Complex - the quotient of the two numbers
	Complex operator/(Complex other);
	// Divides this complex number by a real number
	// (a+bi) / r = (a/r)+(b/r)i
	// Parameters:
	//   float other - the real number to divide this complex number by
	// Returns: Complex - the quotient of the two numbers
	Complex operator/(float other);

	// Returns the compliment of this number
	// ~(a+bi) = (a-bi)
	// Returns: Complex - compliment of this number
	Complex operator~();

	// Returns the opposite of this number
	// -(a+bi) = (-a-bi)
	// Returns: Complex - opposite of this number
	Complex operator-();

	// Raises this number to a power by repeated multiplication.
	// Requirement: power >= 1
	// (a+bi)^power
	// Parameters:
	//   int power - the power to raise this number to
	// Returns: Complex - the output
	Complex operator^(int power);

	// Other operators
	
	// Assignment operator overload
	// Parameters:
	//   Complex other - the number to assign values to this one
	// Returns: Complex - the output
	Complex & operator=(Complex other);
	// Equality operator
	// Returns true if both the real and imaginary parts are equal
	// Parameters:
	//   Complex other - the number to compare to this one.
	// Returns: bool - the boolean from the comparison
	bool operator==(Complex other);
	// Inequality operator
	// Returns true if either of the real and imaginary parts are not equal
	// Parameters:
	//   Complex other - the number to compare to this one
	// Returns: bool - the boolean from the comparison
	bool operator!=(Complex other);

private:
	// Internal private variables
	float real;
	float imag;
	
};

// Operator to allow printing to strings, like cout.
// Parameters:
//   std::ostream os - The output stream to add characters to
//   Complex c - The number to output
// Returns: std::ostream - the output stream that was passed into this function
std::ostream & operator<<(std::ostream & os, Complex c);


#endif