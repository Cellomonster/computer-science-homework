#define RED "\033[1;31m"
#define RST "\033[0m"

#include "Complex.h"
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(void){
	float r, i;

	scanf("%f %f", &r, &i);

	Complex c = Complex(r, i);
	cout << c.getReal() << endl;
	cout << c.getImag() << endl;

	cout << RED << c << RST << endl << endl;

	cout << "(" << c << ")" << " - (2+2i) = ";
	cout << RED << c - Complex(2,2) << RST << endl;

	cout << "(" << c << ")" << " + (2+2i) = ";
	cout << RED << c + Complex(2,2) << RST << endl;

	cout << "(" << c << ")" << " * (2+2i) = ";
	cout << RED << c * Complex(2,2) << RST << endl;

	cout << "(" << c << ")" << " / (2+2i) = ";
	cout << RED << c / Complex(2,2) << RST << endl;

	cout << endl;

	cout << "(" << c << ")" << " - (2-2.5i) = ";
	cout << RED << c - Complex(2,-2.5) << RST << endl;

	cout << "(" << c << ")" << " + (2-2.5i) = ";
	cout << RED << c + Complex(2,-2.5) << RST << endl;

	cout << "(" << c << ")" << " * (2-2.5i) = ";
	cout << RED << c * Complex(2,-2.5) << RST << endl;

	cout << "(" << c << ")" << " / (2-2.5i) = ";
	cout << RED << c / Complex(2,-2.5) << RST << endl;

	cout << endl;

	cout << "(" << c << ")" << " - (-2+2.5i) = ";
	cout << RED << c - Complex(-2,2.5) << RST << endl;

	cout << "(" << c << ")" << " + (-2+2.5i) = ";
	cout << RED << c + Complex(-2,2.5) << RST << endl;

	cout << "(" << c << ")" << " * (-2+2.5i) = ";
	cout << RED << c * Complex(-2,2.5) << RST << endl;

	cout << "(" << c << ")" << " / (-2+2.5i) = ";
	cout << RED << c / Complex(-2,2.5) << RST << endl;

	cout << endl;

	cout << "(" << c << ")" << " - (-2-2.5i) = ";
	cout << RED << c - Complex(-2,-2.5) << RST << endl;

	cout << "(" << c << ")" << " + (-2-2.5i) = ";
	cout << RED << c + Complex(-2,-2.5) << RST << endl;

	cout << "(" << c << ")" << " * (-2-2.5i) = ";
	cout << RED << c * Complex(-2,-2.5) << RST << endl;

	cout << "(" << c << ")" << " / (-2-2.5i) = ";
	cout << RED << c / Complex(-2,-2.5) << RST << endl;

	cout << endl;

	cout << "(" << c << ")" << " - 2.5 = ";
	cout << RED << c - 2.5 << RST << endl;

	cout << "(" << c << ")" << " + 2.5 = ";
	cout << RED << c + 2.5 << RST << endl;

	cout << "(" << c << ")" << " * 2.5 = ";
	cout << RED << c * 2.5 << RST << endl;

	cout << "(" << c << ")" << " / 2.5 = ";
	cout << RED << c / 2.5 << RST << endl;

	cout << endl;

	cout << "-(" << c << ")" << endl;
	cout << RED << -c << RST << endl;

	cout << "~(" << c << ")" << endl;
	cout << RED << ~c << RST << endl;

	cout << "(" << c << ") ^ 3" << endl;
	cout << RED << (c^3) << RST << endl;

	return 0;
}