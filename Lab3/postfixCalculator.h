//Yumna Rahman, yr6by
//Sept 25, 2020
//file postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H
#include "Stack.h"

class postfixCalculator {
 public:
  postfixCalculator();
  void add();
  void subtract();
  void multiply();
  void division();
  void negation();
  void pushNeg(int x);
  void pushPos(int x);
  int print();
  
 private:
  int rightOperand;
  int leftOperand;
  int result;
  Stack s;
};

#endif
