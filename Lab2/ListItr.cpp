//Yumna Rahman, yr6by
//Sept. 13 2020
//file ListItr.cpp

#include "ListItr.h"

ListItr::ListItr() {
  current = NULL;
}

ListItr::ListItr(ListNode* theNode) {
  current = theNode;
}

bool ListItr::isPastEnd() const {
  if (current->next == NULL)
    return true;
  else
    return false;
}

bool ListItr::isPastBeginning() const {
  if(current->previous == NULL)
    return true;
  else
    return false;
}

void ListItr::moveForward() {
  current = current->next;
}

void ListItr::moveBackward() {
  current = current->previous;
}

int ListItr::retrieve() const {
  return current->value;
}

void printList(List& source, bool forward) {
  if (forward == true) { //print forward seg fault
    ListItr start = source.first();
    for (int i = 0; i < source.size(); i++) {
      cout << start.retrieve();
      start.moveForward();
    }
  }
  else {
    ListItr start = source.last();
    for (int i=0; i < source.size(); i++) {
      cout << start.retrieve();
      start.moveBackward();
    } 
  }
}
