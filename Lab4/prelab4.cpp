#include <iostream>
#include <climits>
#include <cfloat>
using namespace std;

void sizeOfTest() {
  cout << "Size of int: " << sizeof(int) << endl;
  cout << "Size of unsigned int: " << sizeof(unsigned int) << endl;
  cout << "Size of float: " << sizeof(float) << endl;
  cout << "Size of double: " << sizeof(double) << endl;
  cout << "Size of char: " << sizeof(char) << endl;
  cout << "Size of bool: " << sizeof(bool) << endl;
  cout << "Size of int*: " << sizeof(int*) << endl;
  cout << "Size of char*: " << sizeof(char*) << endl;
  cout << "Size of double*: " << sizeof(double*) << endl;
}

void overflow() {
  unsigned int z;
  z = UINT_MAX;
  int result = z + 1;
  cout << z << " + " << 1 << " = " << result << endl;
}

void outputBinary(unsigned int input) {
  int binaryNum[32]; //array to store remainders
  for (int k = 0; k <= 31; k++) //initalizing array
    binaryNum[k] = 0;
  int i = 0; 
  while (input > 0) {
    binaryNum[i] = input % 2;
    input /= 2;
    i++;
  }
  int index = 0;
  for (int j = 31; j >= 0; j--) { //printing in reverse order
    cout << binaryNum[j];
    index++;
    if (index == 4) {
      cout << " ";
      index = 0;
    }
  }
  cout << endl;
}

int main () {
  /* int x;
  cin >> x;
  sizeOfTest();
  overflow();
  outputBinary(x);*/

  //one as store in hex
  int i = 1;
  unsigned int u = 1;
  float f = 1.0;
  double d = 1;
  char c = '1';
  bool b = true;
  /* int* pi = NULL;
  char* pc = NULL;
  double* pd = NULL;*/
  
  return 0;
}
