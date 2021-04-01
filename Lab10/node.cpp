//Yumna Rahman, yr6by

#include "node.h"
using namespace std;

node::node(char v, int f) {
  value = v; //char
  frequency = f; //int
  prefix = "";
  left = NULL;
  right = NULL;
}

node::~node() {
  delete left;
  delete right;
}

unsigned int node::getFreq() const {
  return frequency;
}

char node::getChar() {
  return value;
}

string node::getPrefix() {
  return prefix;
}

bool node::operator<(const node& n) const {
  return(this->getFreq() < n.getFreq());
}
