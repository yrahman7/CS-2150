//Yumna Rahman, yr6by
//Sept. 13 2020
//file List.cpp

#include "List.h"
#include <iostream>

List::List() {
  head=new ListNode();
  tail=new ListNode();
  head->next = tail;
  head->previous = NULL;
  tail->previous = head;
  tail->next = NULL;
  count = 0;
}

List::List(const List& source) {
  head=new ListNode();
  tail=new ListNode();
  head->next=tail;
  tail->previous=head;
  count=0;

  // Make a deep copy of the list
  ListItr iter(source.head->next);
  while (!iter.isPastEnd()) {
      insertAtTail(iter.retrieve());
      iter.moveForward();
  }
}

List::~List() {
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List & source) {
   if (this == &source) {
        // The two are the same list; no need to do anything
        return *this;
    } else {
        // Clear out anything this list contained
        // before copying over the items from the other list
        makeEmpty();

        // Make a deep copy of the list
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}

bool List::isEmpty() const {
  if(head->next == tail)
    return true;
  else
    return false;
}

void List::makeEmpty() {
  ListItr iter(head->next);
  while (iter.isPastEnd() != true) {
    int temp = iter.retrieve();
    iter.moveForward();
    remove(temp);
  }
}

ListItr List::first() {
  return ListItr(head->next);
}

ListItr List::last() {
  return ListItr(tail->previous);
}

void List::insertAfter(int x, ListItr position) {
  ListNode * newNode = new ListNode();
  newNode->value = x;
  newNode->next = position.current->next;
  newNode->previous = position.current;
  position.current->next->previous = newNode;
  position.current->next = newNode;
  count++;
}

void List::insertBefore(int x, ListItr position) { 
  ListNode * newNode = new ListNode();
  newNode->value = x;
  newNode->next = position.current->previous->next;
  newNode->previous = position.current->previous;
  position.current->previous->next = newNode;
  position.current->previous = newNode;
  count++;
}

void List::insertAtTail(int x) {
  ListNode * newNode = new ListNode();
  newNode->value = x;
  newNode->next = tail;
  newNode->previous = tail->previous;
  tail->previous->next = newNode;
  tail->previous = newNode;
  count++;
}

ListItr List::find(int x) {
  ListItr iter(head);
  while (iter.current != tail) {
    if (iter.retrieve() == x)
      return iter;
    iter.moveForward();
  }
  return iter;
}

void List::remove(int x) {
  ListItr iter = find(x);
  ListNode * temp = iter.current;
  ListNode * oldPrevious = temp->previous;
  ListNode * oldNext = temp->next;
  delete temp;
  oldPrevious->next = oldNext;
  oldNext->previous = oldPrevious;
  count--;
}

int List::size() const {
  return count;
} 
