//Yumna Rahman, yr6by
//referenced from binary_heap.h example

#ifndef HEAP_H
#define HEAP_H
#include <vector>
#include "node.h"

using namespace std;

class heap {
 public:
  heap();              //default constructor
  ~heap();             //destructor

  void insert(node* x);
  node* findMin() const;
  void deleteMin();
  
  unsigned int size();
  void makeEmpty();
  bool isEmpty();
  vector<node*> getVector();

 private:
  vector<node*> huffmanHeap;
  unsigned int heap_size;

  void percolateUp(int hole, node* n);
  void percolateDown(int hole);
};

#endif
