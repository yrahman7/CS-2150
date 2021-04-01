//Yumna Rahman, yr6by

#include <iostream>
#include "tree.h"
#include "node.h"
using namespace std;

tree::tree() {
  root = NULL;
}

tree::~tree() {
  delete root;
}

heap tree::huffmanTree(heap h) {
  while (h.size() >= 2) {
    node* n1 = h.findMin();
    h.deleteMin();
    node* n2 = h.findMin();
    h.deleteMin();
    node* mergedNode = merge(n1, n2);
    h.insert(mergedNode);
  }
  return h;
}

node* tree:: merge(node* n1, node* n2) {
  int totalFreq = 0;
  totalFreq += n1->getFreq() + n2->getFreq();

  node* newNode = new node('1', totalFreq);
  newNode->left = n1;
  newNode->right = n2;
  return newNode;
}

void tree::setPrefix(node* root, string s) {
  if (root->left==NULL && root->right==NULL)
    root->prefix = s;

  if (root->left)
    setPrefix(root->left, s+"0");

  if (root->right)
    setPrefix(root->right, s+"1");
}

void tree::printPrefix(node* root, string s) {
  if (root->value == ' ')
    cout << "space" << " " << s << endl;
  
  if (root->left == NULL && root->right == NULL && root->value != ' ')
    cout << root->value << " " << s << endl;
  
  if (root->left)
    printPrefix(root->left, s+"0");
  
  if (root->right) 
    printPrefix(root->right, s+"1");
}
   
