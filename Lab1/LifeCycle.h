//LifeCycle.h
//Yumna Rahman, yr6by
//Sept. 8 2020

#ifndef LIFECYCLE_H
#define LIFECYCLE_H
#include <string>
using namespace std;

class MyObject {
 public:
  static int numObjs;

  MyObject();                    //default constructor
  MyObject(string n);            //constructor with name parameter
  MyObject(const MyObject& rhs); //copy constructor
  ~MyObject();                   //destructor

  string getName() const;
  void setName(const string& newName);

  friend ostream& operator<<(ostream& output, const MyObject& obj);
  
 private:
  string name;
  int id;
};

// Prototypes for non-member functions we define later on
// These are *non-member* functions because we didn't declare them as part of the MyObject class
MyObject getMaxMyObj(const MyObject o1, const MyObject o2);
int cmpMyObj(const MyObject o1, const MyObject o2);
void swapMyObj(MyObject& o1, MyObject& o2);

#endif
