/*
File: project7.cpp
6
This file implement the complex class.
*/

#include<string>
#include<iostream>
#include<cmath>
#include "Complex.h"
using namespace std;

/*
implementation notes: constructors
Threr are three constructors for this class. The default constructor
creates a complex with 0 value. Two-double one spcifies a new conplex number by giving real and imaginary components.
The one, whose parameter is a complex, create a new complex from existing one.
*/
complex::complex(){
  real = 0;
  imag = 0;
}
complex::complex(double re, double im){
  real = re;
  imag = im;
}
complex::complex(const complex & c){
  real = c.real;
  imag = c.imag;
}

/*setters and getters*/
void complex::setReal(double re){
  real = re;
}
void complex::setImag(double im){
  imag = im;
}
double complex::getReal(){
  return real;
}
double complex::getImag(){
  return imag;
}


/* overloeads operators*/
complex complex::operator~(){
  return complex(real,-imag);
}

complex complex::operator-(){
  return complex(-real,-imag);
}

complex power(complex c, int x){
  return pow(c,x);
}

complex operator +(complex & c1, complex & c2){
  return complex(c1.real+c2.real,c1.imag+c2.imag);
}
complex operator +(complex & c1, int & c2){
  return complex(c1.real+c2,c1.imag+0);
}
complex operator +(complex & c1, float & c2){
  return complex(c1.real+c2,c1.imag+0);
}
complex operator -(complex & c1, complex & c2){
  return complex(c1.real-c2.real, c1.imag-c2.imag);
}
complex operator -(complex & c1, int & c2){
  return complex(c1.real-c2, c1.imag-0);
}
complex operator -(complex & c1, float & c2){
  return complex(c1.real-c2, c1.imag-0);
}
complex operator *(complex & c1, complex & c2){
  return complex(c1.real*c2.real-c1.imag*c2.imag,c1.real*c2.imag+c1.imag*c2.real);
}
complex operator *(complex & c1, int & c2){
  return complex(c1.real*c2,c1.imag*c2);
}
complex operator *(complex & c1, float & c2){
  return complex(c1.real*c2,c1.imag*c2);
}
complex operator /(complex & c1, complex & c2){
  return complex(c1.real*c2.real+c1.imag*c2.imag)/(pow(c2.real,2)+pow(c2.imag,2)),(c1.imag*c2.real-c1.real*c2.imag)/(pow(c2.real,2)+pow(c2.imag,2)));
}
complex operator /(complex & c1, int & c2){
  return complex(c1.real/c2,c1.imag/c2);
}
complex operator /(complex & c1, float & c2){
  return complex(c1.real/c2,c1.imag/c2);
}

bool operator==(complex c1,complex c2){
  if(c1.real==c2.real && c1.imag==c2.imag) return true;
  else return false;
}

bool operator!=(complex c1,complex c2){
  if(c1.real!=c2.real && c1.imag!=c2.imag) return true;
  else return false;
}

/*implementation of toString and the << operator */
string complex::toString(){
  return std::to_string(real) + "+" + std::to_string(imag)+ "i";
}

ostream & operator<<(std::ostream & oc, complex c){
  return oc << c.toString();
}
