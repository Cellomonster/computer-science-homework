#include <iostream>
using namespace std;

void test(int &thing){
  thing ++;
}

int main(void){
  int x = 3;

  test(x);

  cout << x << endl;

  return 0;
}
