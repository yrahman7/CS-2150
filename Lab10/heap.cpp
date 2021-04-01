//Yumna Rahman, yr6by
//Nov 8, 2020
//referenced from binary_heap.cpp example

#include <iostream>
#include "heap.h"

using namespace std;

heap::heap() : heap_size(0), huffmanHeap(101) {
}

heap::~heap() {
  makeEmpty();
}

void heap::insert(node* x) {
  while (heap_size == huffmanHeap.size() - 1) {
    huffmanHeap.resize(huffmanHeap.size() * 2);
  }
  percolateUp(++heap_size, x);
}

node* heap::findMin() const {
  return huffmanHeap[1];
}

void heap::deleteMin() {
  if (!isEmpty()) {
    huffmanHeap[1] = huffmanHeap[heap_size--];
    int temp = 1;
    percolateDown(temp);
  }
}

unsigned int heap::size() {
  return heap_size;
}

void heap::makeEmpty() {
  if (!isEmpty()) {
    huffmanHeap.clear();
    heap_size = 0;
  }
}

bool heap::isEmpty() {
  if (heap_size == 0)
    return true;
  else
    return false;
}

void heap::percolateUp(int hole, node* n) {
  while ((hole > 1) && (*n < *huffmanHeap[hole/2])) {
    huffmanHeap[hole] = huffmanHeap[hole/2];
    hole /= 2;
  }
  huffmanHeap[hole] = n;
}

void heap::percolateDown(int hole) {
  node* temp = huffmanHeap[hole];
  int child;

  while (hole * 2 <= heap_size) {
    child = (2 * hole); //left child

    //right child
    if((*(huffmanHeap[child+1])) < (*(huffmanHeap[child])) && (child != heap_size)) {
      child++;
     }
    
    // child > n
    if((*huffmanHeap[child]) < (*temp)) {
      huffmanHeap[hole] = huffmanHeap[child]; 
      hole = child;		        
    }
    else 
      break;   
  }
  //insert at right place
  huffmanHeap[hole] = temp;
}

vector<node*> heap::getVector(){
  return huffmanHeap;
}
