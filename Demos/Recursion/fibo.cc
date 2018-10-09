#include <iostream>
using namespace std;



int fibo(int n);
long int additiveSeq(int n, int t0, int t1);

int main(){
  for(int i = 0; i < 100; i++)
    cout << "Fibonacci of " << i << " is equal to " << fibo(i) << endl;

  return 0;
}

int fibo(int n){
  additiveSeq(n, 0, 1);

  //if(n < 3) return n;

  //return fibo(n - 1) + fibo(n - 2);
}

long int additiveSeq(int n, int t0, int t1){
  if(n == 0) return t0;
  if(n == 1) return t1;

  //cout << "Call!" << endl;

  return additiveSeq(n - 1, t1, t0 + t1);
}
