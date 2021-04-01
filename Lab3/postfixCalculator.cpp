//Yumna Rahman, yr6by
//Sept 25, 2020
//file postfixCalculator.cpp

#include "postfixCalculator.h"
#include <iostream>
#include <string>
using namespace std;

postfixCalculator::postfixCalculator() {
  rightOperand = 0;
  leftOperand = 0;
  result = 0;
}

void postfixCalculator::add() {
  rightOperand = s.top();
  s.pop();
  leftOperand = s.top();
  s.pop();
  result = leftOperand + rightOperand;
  s.push(result);
}

void postfixCalculator::subtract() {
  rightOperand = s.top();
  s.pop();
  leftOperand = s.top();
  s.pop();
  result = leftOperand - rightOperand;
  s.push(result);
}

void postfixCalculator::multiply() {
  rightOperand = s.top();
  s.pop();
  leftOperand = s.top();
  s.pop();
  result = leftOperand * rightOperand;
  s.push(result);
}

void postfixCalculator::division() {
  rightOperand = s.top();
  s.pop();
  leftOperand = s.top();
  s.pop();
  result = leftOperand / rightOperand;
  s.push(result);
}

void postfixCalculator::negation() {
   rightOperand = s.top();
   s.pop();
   result = (-1 ) * rightOperand;
   s.push(result);
}

void postfixCalculator::pushNeg(int x) {
  result = x;
  s.push(result);
}

void postfixCalculator::pushPos(int x) {
  result = x;
  s.push(result);
}

int postfixCalculator::print() {
  return result;
}

