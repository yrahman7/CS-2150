#include<iostream>
//#include <climits>
//#include "inlab4helper.h"
using namespace std;

int main() {
  //Representation in memory 
  /* bool myBool = true;
  char myChar = 'A';
  int myInt = 3;
  double myDouble = 5.5;
  int* myIntPointer = &myInt;

  cout << myBool << endl;
  cout << myChar << endl;
  cout << myInt << endl;
  cout << myDouble << endl;
  cout << myIntPointer << endl;*/

  //Primitive Arrays in C++
  int IntArray[10] = {0,1,2,3,4,5,6,7,8,9};
  char CharArray[10] = {'a','b','c','d','e','f','g','h','i','j'};

  int IntArray2D[6][5] = {
    {1,2,3,4,5,6},
    {1,2,3,4,5,6},
    {1,2,3,4,5,6},
    {1,2,3,4,5,6},
    {1,2,3,4,5,6}
  };
  //expression for an element in IntArray2D
  //&(IntArray2D[i][j]) = &IntArray2D[0][0] + 4[5(i-1) + (j-1)]
  
  int CharArray2D[6][5] = {
    {'a','b','c','d','e','f'},
    {'a','b','c','d','e','f'},
    {'a','b','c','d','e','f'},
    {'a','b','c','d','e','f'},
    {'a','b','c','d','e','f'},
  };
  
  return 0;
}
  


