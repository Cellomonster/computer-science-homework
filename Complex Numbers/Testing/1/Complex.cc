//==============================================================
// 4
// project7.cc
// Oct 11, 2018
// This is a program which constructs a Complex class to ease complex num. computations
//==============================================================


#include "Complex.h"


//==============================================================
//Default constructor
//Initialize complex to 0
//==============================================================
Complex::Complex(){
	real = 0.0;
	i = 0.0;
}
//==============================================================
//Copy constructor
//Copy existing complex object into a new complex object.
//==============================================================
Complex::Complex(const Complex &pair){
	real = pair.real;
	i = pair.i;
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><>><><>><><>
//Constructors

//==============================================================
//Complex pair Constructor
//Initialize complex to a + ib
//==============================================================
Complex::Complex(float a,float b){
	real = a;
	i = b;
}
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><>><><>><><>


//==============================================================
//operator '+'
//Adds two complex objects
//==============================================================
Complex	Complex::operator+(const Complex pair){
	Complex add;
	add.real = real + pair.real;
	add.i = i + pair.i;
	return add;
}

//==============================================================
//operator '-'
//Subtract two complex objects
//==============================================================
Complex Complex::operator-(const Complex pair){
	Complex subtract;
	subtract.real = real - pair.real;
	subtract.i = i - pair.i;
	return subtract;
}

//==============================================================
//operator '*'
//Multiplies two complex objects
//==============================================================
Complex Complex::operator*(const Complex pair){
	Complex mult;
	mult.real = real*pair.real - i*pair.i;
	mult.i = real*pair.i + i*pair.real;
	return mult;
}

//==============================================================
//operator '~'
//Provides the conjugate of given complex
//==============================================================
Complex	Complex::operator~(){
	Complex conjugate;
	conjugate.real = real;
	conjugate.i = -i;
	return conjugate;
}

//==============================================================
//operator '/'
//Divides two complex objects
//==============================================================
Complex	Complex::operator/(const Complex pair){
	Complex divide;
	divide.real = (real*pair.real +i*pair.i)/(pair.real*pair.real + pair.i*pair.i);
	divide.i = (i *pair.real -real*pair.i)/(pair.real*pair.real + pair.i*pair.i);
	return divide;
}


//==============================================================
//operator '+'
//Adds a complex and a float
//==============================================================
Complex	Complex::operator+(const float num){
	Complex add;
	add.real = real+num;
	add.i = i;
	return add;
}

//==============================================================
//operator '-'
//Subtracts a complex and a float
//==============================================================
Complex	Complex::operator-(const float num){
	Complex subtract;
	subtract.real = real-num;
	subtract.i = i;
	return subtract;
}

//==============================================================
//operator '*'
//Multiplies a complex and a float
//==============================================================
Complex	Complex::operator*(const float num){
	Complex multiply;
	multiply.real = real*num;
	multiply.i = i*num;
	return multiply;
}

//==============================================================
//operator '/'
//Divides a complex by a float
//==============================================================
Complex	Complex::operator/(const float num){
	Complex divide;
	divide.real = real/num;
	divide.i = i/num;
	return divide;
}

//==============================================================
//operator-
//Negate a complex
//==============================================================
Complex	Complex::operator-(){
	Complex neg;
	neg.real = -real;
	neg.i = -i;
	return neg;
}

//==============================================================
//operator^
//Raise a complex to an exponent
//==============================================================
Complex Complex::operator^(const int num){
	Complex expo(real, i);

	if ( num == 0 )
	{
		expo.i = 0;
		expo.real = 1;
		return expo;
	}
	else
	{
		return (expo * (expo ^ (num-1)));
	}
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><>><><>><><>
//MODIFIERS AND ACCESSORS

//==============================================================
//setReal
//sets the real part of the complex number
//==============================================================
Complex Complex::setReal(float num){
	real = num;
	return *this;
}

//==============================================================
//setImag
//sets the imaginary part of the complex number
//==============================================================
Complex Complex::setImag(float num){
	i = num;
	return *this;
}

//==============================================================
//getReal
//returns the real part of the complex number
//==============================================================
float Complex::getReal(){
	return real;
}

//==============================================================
//getImag
//returns the imaginary part of the complex number
//==============================================================
float Complex::getImag(){
	return i;
}
//<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><>><><>><><>


//==============================================================
//operator '='
//Assigns a complex pair object a value using another complex object pair
//==============================================================
Complex	Complex::operator=(const Complex pair){
	real = pair.real;
	i = pair.i;
	return pair;
}

//==============================================================
//Destructor
//"Unuses" memory
//==============================================================

Complex::~Complex(){
}

//==============================================================
//operator==
//returns whether two complex objects are equal
//==============================================================

bool	Complex::operator==	(const Complex pair){
	return ((real == pair.real) && (i == pair.i));
}

//==============================================================
//operator!=
//returns whether two complex objects are not equal
//==============================================================
bool	Complex::operator!=	(const Complex pair){
	return ((real != pair.real) || (i != pair.i));
}

//==============================================================
//cout <<
//Overloads the cout ostream << operator to allow
//cout << c << endl;
//in the format ai+b
//==============================================================
ostream & operator<< (ostream &print,Complex &pair){
	if (pair.i >= 0)
		print << pair.real << "+" << pair.i << "i";
	else
		print << pair.real << pair.i << "i";
	return print;
}
