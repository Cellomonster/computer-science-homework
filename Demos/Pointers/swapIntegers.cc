/*
 * File: swapIntegers.cc
 * ----------------------
 * This program illustrates the use of call by reference to exchange
 * the values of two integers.
 */

#include <iostream>
using namespace std;

/* Function prototypes */

void swapA(int & x, int & y);
void swapB(int *a, int *b);
void swapC(int a, int b);

/* Main program */
int main() {
        int n1, n2;

        cout << "Enter n1: " << endl;
        cin >> n1;
        cout << "Enter n2: " << endl;
        cin >> n2;

        cout << "Before swap: " << n1 << " " << n2 << endl;
        swapA( n1, n2 );
        cout << "After swapA: " << n1 << " " << n2 << endl;
        swapB( &n1, &n2);
        cout << "After swapB: " << n1 << " " << n2 << endl;
        swapC( n1, n2);
        cout << "After swapC: " << n1 << " " << n2 << endl;

        return 0;
}

void swapA(int & x, int & y){
        int temp = x;
        x = y;
        y = temp;
}

void swapB(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
}

void swapC(int c, int d){
        int temp = c;
        c = d;
        d = temp;
}

