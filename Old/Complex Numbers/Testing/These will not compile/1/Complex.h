

#include <iostream>
using namespace std;

#ifndef COMPLEX_H
#define COMPLEX_H

//==============================================================
//Complex Class
//==============================================================

class Complex
{
private:
	float	real;
	float	i;

public:
			Complex();	//default
			Complex(const Complex &);	//copy
			Complex(float a,float b);
		  ~Complex();	//destructor
//==============================================================
//Operators for manipulating complex objects
			Complex	operator=(const Complex pair);
			Complex	operator+(const Complex pair); //adds two complex objects
			Complex	operator-(const Complex pair); //subtracts two complex objects
			Complex	operator*(const Complex pair); //multiplies two complex objects
			Complex	operator/(const Complex pair); //divides two complex objects
//==============================================================

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
// Operators for using float/integers with complex objects
			Complex	operator+(const float num); //adds float/int to complex object
			Complex	operator-(const float num); //subtracts float/int to complex object
			Complex	operator*(const float num); //multiplies float/int to complex object
			Complex	operator/(const float num); //divides float/int to complex object
			Complex operator^(const int num);	//exponentiates complex object with given float/int
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

			Complex	operator~();	//provides a conjugate of the complex object
			Complex operator-();	//provides a negation of the complex object



//getters and setters
			Complex setReal(float num);
			Complex setImag(float num);
			float	getReal();
			float getImag();
			bool operator==(const Complex pair);
			bool operator!=(const Complex pair);

		  friend ostream & operator<<(ostream &print,Complex &pair);
};

#endif
