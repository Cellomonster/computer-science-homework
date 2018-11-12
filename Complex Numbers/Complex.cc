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

Complex::Complex(){
	r = 0;
	i = 0;
}

Complex::Complex(float r, float i){
	this->r = r;
	this->i = i;
}

Complex::Complex(const Complex &c){
	this->r = c.getReal();
	this->i = c.getImag();
}

float Complex::getReal() const{return r;};
float Complex::getImag() const{return i;};

void Complex::setReal(float f){this->r = f;};
void Complex::setImag(float f){this->i = f;};

void Complex::operator=(const Complex &c){
	r = c.getReal();
	i = c.getImag();
}

bool Complex::operator==(const Complex &c){
	return (r == c.getReal() && i == c.getImag());
}

bool Complex::operator!=(const Complex &c){
	return !(*this == c);
}

std::ostream& operator<<(std::ostream &os, const Complex &c){
	std::string str = "";

	if(!c.getReal() && !c.getImag()){
		return os << "0";
	}

	if(c.getReal()){
		str += std::to_string(c.getReal());

		if(c.getImag() > 0)
			str += "+";
	}

	if(c.getImag()) str += std::to_string(c.getImag()) + "i";

	return os << str;
}

Complex operator+(const Complex &c1, const Complex &c2){
	return Complex(c1.getReal() + c2.getReal(), c1.getImag() + c2.getImag());
}

Complex operator-(const Complex &c1, const Complex &c2){
	return Complex(c1.getReal() - c2.getReal(), c1.getImag() - c2.getImag());
}

Complex operator*(const Complex &c1, const Complex &c2){
	float a = c1.getReal();
	float b = c1.getImag();
	float c = c2.getReal();
	float d = c2.getImag();

	return Complex(a*c - b*d, a*d + b*c);
}

Complex operator/(const Complex &c1, const Complex &c2){
	float a = c1.getReal();
	float b = c1.getImag();
	float c = c2.getReal();
	float d = c2.getImag();

	return Complex ((a+b)/(c*c+d*d), (c-d)/(c*c+d*d));
}

Complex operator+(const Complex &c, const float &f){
	return Complex(c.getReal() + f, c.getImag());
}

Complex operator-(const Complex &c, const float &f){
	return Complex(c.getReal() - f, c.getImag());
}

Complex operator*(const Complex &c, const float &f){
	return Complex(c.getReal() * f, c.getImag() * f);
}

Complex operator/(const Complex &c, const float &f){
	return Complex(c.getReal() / f, c.getImag() / f);
}

Complex operator-(const Complex &c){
	return Complex(-c.getReal(), -c.getImag());
}

Complex operator~(const Complex &c){
	return Complex(c.getReal(), -c.getImag());
}

Complex operator^(const Complex &c, const int&p){
	Complex toReturn=Complex(c);

	for(int i = 0; i < p; i++) toReturn = toReturn*toReturn;

	return toReturn;
}

