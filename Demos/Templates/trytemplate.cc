#include <iostream>
#include <string>
using namespace std;


template<typename ValueType>
ValueType max(ValueType x, ValueType y){
  return (x > y) ? x : y;
}

template<typename ValueType>
ValueType max(ValueType x, ValueType y){
  return (x > y) ? x : y;
}


int main(){


  int i = 0;
  int j = 1;
  int z = max(i, j);
  cout << z << endl;

  return 0;
}