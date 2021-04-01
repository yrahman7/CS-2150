//Yumna Rahman, yr6by
//Sept 25, 2020
//file Stack.cpp

#include "Stack.h"
#include <iostream>

Stack::Stack() {
  head = new stackNode();
  tail = new stackNode();
  head->previous = tail;
  tail->previous = NULL;
  count = 0;
}

Stack::~Stack() {
  makeEmpty();
  delete head;
  delete tail;
}

void Stack::push(int e) {
  stackNode* newNode = new stackNode();
  newNode->value = e;
  newNode->previous = head->previous;
  head->previous = newNode;
  count++;
}

void Stack::pop() {
  stackNode* temp = head->previous;
  head->previous = temp->previous;
  delete temp;
  count--;
}

int Stack::top() {
  if (empty() == true)
    throw "top() attempted on empty stack";
  else
    return head->previous->value;
}

void Stack::makeEmpty() {
  while (head->previous != tail) {
    stackNode* temp = head->previous;
    stackNode* oldPrevious = temp->previous;
    delete temp;
    head->previous = oldPrevious;
    count--;
  }
}

bool Stack::empty() {
  if (count == 0)
    return true;
  else
    return false;
}
