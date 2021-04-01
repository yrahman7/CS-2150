/** @brief File: topological.cpp
 * @details Given a text file input, this class outputs a topologically sorted list.
 * @author Yumna Rahman (yr6by)
 * @date 11/15/2020
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <stdlib.h>
#include <string>
#include <vector>
#include <deque>

using namespace std;

/** @code{.cpp}
 * @brief Node class that creates a node for the graph
 */
class Node {
public:
  /** @var vector<Node*> adjacencyList
   * @brief vector for adjacent nodes
   */
  vector<Node*> adjacencyList;

  /** @var string location
   * @brief marks a node with its location on the graph
   */
  string location;

  /** @var int indegree
   * @brief the number of incoming edges of a node 
   */
  int indegree;

  /** @fn Node(string s)
   * @brief Node constructor
   * @details constructs a node with a specified location and initialized indegree 0.
   * @param string s, location of node
   */
  Node(string s) {
    location = s;
    indegree = 0;
  }

  /** @fn addNode(Node*)
   * @brief adds a node onto the list of adjacent nodes
   * @param Node* n to be added in vector
   */
  void addNode(Node* n) {
    adjacencyList.push_back(n);
  }
};
/** @endcode
 */

/** @var vector<Node*> list
 * @brief list of courses to construct sort
 */
vector<Node*> list;

/** @fn void topologicalSort()
 * @brief performs a topological sort lexicographically as referenced from class slides
 */
void topologicalSort() {
  //  stack<Node*> s;
  deque<string> q;
  Node* v;
  Node* w;

  for (int counter = 0; counter < list.size(); counter++) {
    v = list[counter];
    if (v->indegree == 0) {
      q.push_front(v->location);
    }
  }

  while (!q.empty()) {
    std::sort(q.begin(), q.end());
    string course = q.front();
    for (int i = 0; i < list.size(); i++) {
      if (list[i]->location == course)
	v = list[i];
    }
    q.pop_front();
    cout << v->location << " ";
    //for each w adjacent to v
    for (int j = 0; j < v->adjacencyList.size(); j++) {
      w = v->adjacencyList[j];
      w->indegree--;
      if (w->indegree == 0) {
	q.push_front(w->location);
      }
    }
  }
  cout << endl;
}

/** @code{.cpp}
 * @brief main function with a single command-line parameter input referenced from fileio2.cpp example file.
 */
// we want to use parameters
int main(int argc, char** argv) {
    // verify the correct number of parameters
    if (argc != 2) {
        cout << "Must supply the input file name as the one and only parameter" << endl;
        exit(1);
    }

    // attempt to open the supplied file
    ifstream file(argv[1], ifstream::binary);
    // report any problems opening the file and then exit
    if (!file.is_open()) {
        cout << "Unable to open file '" << argv[1] << "'." << endl;
        exit(2);
    }

    // read in two strings
    while (!file.eof()) {
      string s1, s2;
      file >> s1;
      file >> s2;

      //counters to reset
      int i1 = 0;
      int i2 = 0;
      bool c1 = false;
      bool c2 = false;

      if (s1 == "0" && s2 == "0") {
	break;
      }

      //First string
      for (int i = 0; i < list.size(); i++) {
	if (list[i]->location == s1) {
	  i1 = i;
	  c1 = true;
	}
      }

      if (!c1) {
	Node* n = new Node(s1);
	list.push_back(n);
	i1 = list.size() - 1;
      }

      //Second string
      for (int k = 0; k < list.size(); k++) {
	if (list[k]->location == s2) {
	  i2 = k;
	  c2 = true;
	}
      }

      if (!c2) {
	Node* m = new Node(s2);
	list.push_back(m);
	i2 = list.size() - 1;
      }
      
      //increment indegree and add
      Node* temp = list[i2];
      temp->indegree++;
      list[i1]->addNode(temp); //create adjacency list
    }

    topologicalSort();

    // close the file before exiting
    file.close();
    return 0;
}
/** @endcode
 */
