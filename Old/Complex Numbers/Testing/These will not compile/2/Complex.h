/////////////////////////////////////////////////////////////////////////////
//File:project7.h
//this interface exports a class for representing complex numbers.
/////////////////////////////////////////////////////////////////////////////

#ifndef _complex_h
#define _complex_h
#include<iostream>
#include<string>
#include<cmath>

/*
*Class:complex
*The class is used to represent complex numbers, which are defined to be the sum of real parts and imgainary parts.
*/
class complex{


public:
/*
*Constructor: complex
*Usage: complex new;
        complex c(a,b);
        complex c1(c2);
------------------------------
create a complex object. The default constructor creates the real part is 0 and the imaginary part is 0.
Two-double one spcifies a new conplex number by giving real and imaginary components.
The one, whose parameter is a complex, create a new complex from existing one.
*/
  complex();
  complex(double re, double im);
  complex(const complex & c);
//////////////////////////////////////////////


/*methods:setReal
usage:c.setReal(re);
*/
  void setReal(double re);
  /*methods:setImag
  usage:c.setImag(im);
  */
  void setImag(double im);
  /*methods:getReal
  usage:c.getReal();
  return the real part of this complex
  */
  double getReal();
  /*methods:getImag
  usage:c.getImag();
  return the imaginary part of this complex
  */
  double getImag();
  /*methods:toString
  usage: string str = c.toString();
  return a string representation of complex in form a+bi
  */
  std::string toString();
/*methods:conj
usage: c.conj();
return the conjugate complex
*/



/////////////////////////////////////
//Declare the operator functions as firends
///////////////////////////////////////////////////////////////////////////////
  friend complex operator +(complex & c1, complex & c2);
  friend complex operator +(complex & c1, int & c2);
  friend complex operator +(complex & c1, float & c2);
  friend complex operator -(complex & c1, complex & c2);
  friend complex operator -(complex & c1, int & c2);
  friend complex operator -(complex & c1, float & c2);
  friend complex operator *(complex & c1, complex & c2);
  friend complex operator *(complex & c1, int & c2);
  friend complex operator *(complex & c1, float & c2);
  friend complex operator /(complex & c1, complex & c2);
  friend complex operator /(complex & c1, int & c2);
  friend complex operator /(complex & c1, float & c2);
  friend bool operator==(complex c1,complex c2);
  friend bool operator!=(complex c1,complex c2);
  complex operator~();
  complex operator-();
  complex operator^(complex & c, int x);



/////////////////////////////////////////////////////////////////////////////////*
//private section
////////////////////////////////////////////////////////////////////////////////
private:
//instance variables
  double real;
  double imag;
};
/*
operator: <<
-----------------
overloads the << operator so that it is able to display complex number.
*/
std::ostream & operator<<(std::ostream & oc, complex c);

/*
operator: +
usage c1+c2; c1 + f2; c1 + i2
overloads the + operator so that it can add rational numbers.
*/
complex operator +(complex & c1, complex & c2);
complex operator +(complex & c1, int & c2);
complex operator +(complex & c1, float & c2);
/*
operator: -
usage c1-c2; c1 - f2; c1 - i2
overloads the - operator so that it can add rational numbers.
*/
complex operator -(complex & c1, complex & c2);
complex operator -(complex & c1, int & c2);
complex operator -(complex & c1, float & c2);
/*
operator: *
usage c1*c2; c1*f2; c1*i2
overloads the * operator so that it can add rational numbers.
*/
complex operator *(complex & c1, complex & c2);
complex operator *(complex & c1, int & c2);
complex operator *(complex & c1, float & c2);
/*
operator: /
usage c1/c2; c1/f2; c1/i2
overloads the / operator so that it can add rational numbers.
*/
complex operator /(complex & c1, complex & c2);
complex operator /(complex & c1, int & c2);
complex operator /(complex & c1, float & c2);
/*
operator: ~
usage ~c1
calculate the conjugate of complex number.
*/
complex complex::operator~();
/*
operator: -
usage -c1
calculate the negative of complex number.
*/
complex complex::operator-();
/*
operator: ^
usage: c^x
calculate the x power of the complex number.
*/
complex complex::operator^(complex & c, int x);


/*
operator: ==
usage c1==c2;
overloads the == operator so that allows comparison for equality between complex numbers.
*/
bool operator==(complex c1,complex c2);
/*
operator: !=
usage c1!=c2;
overloads the == operator so that allows comparison for inequality between complex numbers.
*/
bool operator!=(complex c1,complex c2);


#endif
