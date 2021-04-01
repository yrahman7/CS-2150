//Yumna Rahman, yr6by
//Sept 25, 2020
//file Stack.h

#ifndef STACK_H
#define STACK_H
#include "stackNode.h"
using namespace std;

class Stack {
 public:
  Stack();
  ~Stack();
  void push(int e);
  void  pop();
  int top();
  void makeEmpty();
  bool empty();

 private:
  stackNode* head; //dummy node at the top of stack.
  stackNode* tail; //dummy node at the bottom of stack.
  int count;
};

#endif
