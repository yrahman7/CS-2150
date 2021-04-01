//Yumna Rahman, yr6by
//October 25, 2020
//file: mathfun.cpp

#include <iostream>
#include <cstdlib>

using namespace std;

extern "C" int _product (int, int);
extern "C" int _power (int, int);

int main() {
  int firstPar, secPar;

  cout << "Enter integer 1: ";
  cin >> firstPar;
  cout << "Enter integer 2: ";
  cin >> secPar;

  int productRes = _product(firstPar, secPar);
  int powerRes = _power(firstPar, secPar);

  cout << "Product: " << productRes << endl;
  cout << "Power: " << powerRes << endl;

  return 0;
}
