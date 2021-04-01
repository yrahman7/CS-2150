//Yumna Rahman, yr6by

#ifndef TREE_H
#define TREE_H
#include "node.h"
#include "heap.h"

using namespace std;

class tree {
 public:
  tree(); //constructor
  ~tree(); //desctructor

  heap huffmanTree(heap h);
  node* merge(node* n1, node* n2);
  void setPrefix(node* root, string s);
  void printPrefix(node* root, string s);

 private:
  node* root;

};

#endif
