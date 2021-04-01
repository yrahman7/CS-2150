//Yumna Rahman, yr6by
//referenced from fileio.cpp example

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include "heap.h"
#include "node.h"
#include "tree.h"

using namespace std;

int main (int argc, char **argv) {
  // verify the correct number of parameters
  if (argc != 2) {
    cout << "Must supply the input file name as the one and only parameter" << endl;
    exit(1);
  }

  // attempt to open the supplied file
  FILE *file = fopen(argv[1], "r");
  // File not found 
  if (file == NULL) {
    cout << "Unable to open '" << argv[1] << "' for reading" << endl;
    exit(2);
  }

  //initialize frequencies
  int freq[128];
  for(int i = 0; i < 128; i++) {
    freq[i] = 0;
  } 

  int totalSymbols = 0;
  int distinct = 0;
  int ascii;
  char g;
    
  while ((g = fgetc(file)) != EOF ) {
    ascii =(int) g; //char to int
    if(ascii < 128 && ascii > 31) {
      ++freq[ascii];
      ++totalSymbols;
    }
  }
    
  //Build heap of nodes
  heap myHeap;
  for(int i = 1;i < 128; i++){
    if(freq[i] > 0) {
      distinct++;
      node* temp = new node((char)i, freq[i]);
      myHeap.insert(temp);
     }
  }

  //Print prefix of letters
  tree* myTree = new tree();
  heap lastHeap;
  lastHeap = myTree->huffmanTree(myHeap);
  myTree->printPrefix(lastHeap.findMin(),"");
     
cout << "----------------------------------------" << endl;

    myTree->setPrefix(lastHeap.findMin(),"");
    rewind(file);

    //compressed value
    vector<node*> v1 = myHeap.getVector();
    int comp = 0; 
   
    while ((g = fgetc(file)) != EOF ) {
      for(int i = 1; i <= myHeap.size(); i++){
         if(g == v1[i]->getChar()){
	   cout << v1[i]->getPrefix() << " ";
           comp += v1[i]->getPrefix().size();
	 }
      }
    }
   
    cout << endl;

cout << "----------------------------------------" << endl;
 
//Stats
 int uncomp = 0;
 uncomp = totalSymbols*8;
 double ratio =(double) uncomp/comp;
 double cost = (double) comp/totalSymbols;
 cout<<"There are a total of " << totalSymbols << " symbols that are encoded." << endl;
 cout<<"There are " << distinct << " distinct symbols used." << endl;
 cout<<"There were " << uncomp << " bits in the original file." << endl;
 cout<<"There were " << comp << " bits in the compressed file." << endl;
 cout<<"This gives a compression ratio of "<< ratio <<"." << endl;
 cout<<"The cost of the Huffman Tree is "<< cost <<" bits per character." << endl;
    
 fclose(file);
 return 0;
    
}
