#include <iostream>
#include <string>
using namespace std;
#include "postfixCalculator.h"

int main() {
  postfixCalculator calculator;
  string input;
  while (cin >> input) {
    if (input.length() == 1 && input == "+")
      calculator.add();
    else if (input.length() == 1 && input == "-")
      calculator.subtract();
    else if (input.length() == 1 && input == "*")
      calculator.multiply();
    else if (input.length() == 1 && input == "/")
      calculator.division();
    else if (input.length() == 1 && input == "~")
      calculator.negation();
    else if (input.length() > 1 && input.at(0) == '-')
      calculator.pushNeg(stoi(input));
    else
      calculator.pushPos(stoi(input));
  }
  cout << calculator.print() << endl;;
  return 0;
}


