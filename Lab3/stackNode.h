//Yumna Rahman, yr6by
//Sept. 25, 2020
//file stackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H
#include <iostream>

class stackNode {
 public:
  stackNode();
  
 private:
  int value;
  stackNode* previous;

  friend class Stack; 
};

#endif
