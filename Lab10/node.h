//Yumna Rahman, yr6by

#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <string>

using namespace std;

class node {
  friend class heap;
  friend class tree;
  
 public:
  node(char v, int f); //constructor
  ~node(); //destructor

  unsigned int getFreq() const;
  char getChar();
  string getPrefix();
  bool operator<(const node& n) const;
  
  // private:
  char value;
  int frequency;
  string prefix;
  node* left;
  node* right;
  
};

#endif
