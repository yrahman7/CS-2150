//Yumna Rahman, yr6by
//file: huffmandec.cpp referenced from inlab-skeleton.cpp example

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include "node.h"
using namespace std;

//2. Re-create the Huffman tree from the code structure read in from the file.
void huffmanTree(node* n, string prefix, char v) {
  //base case
  if (prefix.length() == 0)
    n->value = v;

  //left child
  if (prefix[0] == '0') {
    if (n->left == NULL) {
      n->left = new node('0', 0);
    }
    huffmanTree(n->left, prefix.substr(1, prefix.length()-1), v);
  }
  //right child
  else if (prefix[0] == '1') {
    if (n->right == NULL) {
      n->right = new node('0', 0);
    }
    huffmanTree(n->right, prefix.substr(1, prefix.length()-1), v);
  }
}

// main(): we want to use parameters
int main (int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    // must be opened in binary mode as otherwise trailing whitespace is discarded
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    //read in the first section of the file: the prefix codes
    char ascii[256];
    node *n1 = new node('0', 0);
    while (true) {
      string character, prefix;
      //read in the first token on the line
      file >> character;
      //deal with new line
      if (character[0] == '\n' || character[0] == '\r') {
	continue;
      }

      //did we hit the separator?
      if (character[0] == '-' && character.length() > 1) {
	file.getline(ascii, 255, '\n');
	break;
      }

      //check for space
      if (character == "space") {
	character = " ";
      }

      //create tree with the prefix code
      prefix = string(ascii);
      file >> prefix;
      huffmanTree(n1, prefix, character[0]);
    }

    // read in the second section of the file: the encoded message
    // Read in one bit at a time from the encoded file and move through the prefix code tree until a leaf node is reached
    char bits;
    node* n2 = n1;
    
    while ((bits = file.get()) != '-') {
      //read in the next set of 1's and 0's
      if(bits != '0' && bits != '1') {
	continue;
      }

      if(n2->left != NULL && bits == '0') {
	n2 = n2->left;
      }
      else if (n2->right != NULL && bits == '1') {
	n2 = n2->right;
      }
      if (n2->left == NULL && n2->right == NULL) {
	cout << n2->getChar();
	n2 = n1;
      }
    }

    cout << endl;
    //close the file before exiting
    file.close();
    return 0;
}
