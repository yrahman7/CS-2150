// Yumna Rahman, yr6by, Oct 6 2020
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

#include "TreeCalc.h"
#include <iostream>
#include <string>

using namespace std;

// Constructor
TreeCalc::TreeCalc() {
}

// Destructor - frees memory
TreeCalc::~TreeCalc() {
  cleanTree(expressionStack.top());
}

// Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* tree) {
  if (tree->left != NULL) 
     cleanTree(tree->left);
  if (tree->right != NULL)
    cleanTree(tree->right);
  delete tree;
}

// Gets data from user
// DO NOT MODIFY
void TreeCalc::readInput() {
    string response;
    cout << "Enter elements one by one in postfix notation" << endl
         << "Any non-numeric or non-operator character,"
         << " e.g. #, will terminate input" << endl;
    cout << "Enter first element: ";
    cin >> response;
    //while input is legal
    while (isdigit(response[0]) || response[0] == '/' || response[0] == '*'
            || response[0] == '-' || response[0] == '+') {
        insert(response);
        cout << "Enter next element: ";
        cin >> response;
    }
}

// Puts value in tree stack
void TreeCalc::insert(const string& val) {
  if (val == "+" || val == "-" || val == "/" || val == "*") {
    TreeNode* rightOperand = expressionStack.top();
    expressionStack.pop();
    TreeNode* leftOperand = expressionStack.top();
    expressionStack.pop();
    TreeNode* oper = new TreeNode(val);
    oper->right = rightOperand;
    oper->left = leftOperand;
    expressionStack.push(oper);
  }
  else {
    TreeNode* number = new TreeNode(val);
    expressionStack.push(number);
  }
}

int TreeCalc::getHeight(TreeNode* tree) const {
  int height = 0;
  if (tree->left == NULL || tree->right == NULL)
    return height;
  else {
    height++;
    getHeight(tree->left);
    getHeight(tree->right);
  }
  return height;
}

// Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* tree) const {
  if (tree->left != NULL && tree->right != NULL) {
    cout << tree->value << " ";
    printPrefix(tree->left);
    printPrefix(tree->right);
  }
  else
    cout << tree->value << " ";
}

// Prints data in infix form
void TreeCalc::printInfix(TreeNode* tree) const {
  if (tree->left != NULL && tree->right != NULL) {
    if (getHeight(tree) == 1) {
      cout << "( ";
      printInfix(tree->left);
      cout << tree->value << " ";
      printInfix(tree->right);
      cout << ") ";
    }
  }
  else
    cout << tree->value << " ";
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* tree) const {
  if (tree->left != NULL && tree->right != NULL) {
    printPostfix(tree->left);
    printPostfix(tree->right);
    cout << tree->value << " ";
  }
  else
    cout << tree->value << " ";
}

// Prints tree in all 3 (post, in, pre) forms
// DO NOT MODIFY
void TreeCalc::printOutput() const {
    if (expressionStack.size() != 0 && expressionStack.top() != NULL) {
        TreeNode* tree = expressionStack.top();
        cout << "Expression tree in postfix expression: ";
        printPostfix(tree);
        cout << endl;

        cout << "Expression tree in infix expression: ";
        printInfix(tree);
        cout << endl;

        cout << "Expression tree in prefix expression: ";
        printPrefix(tree);
        cout << endl;
    } else {
        cout << "Size is 0." << endl;
    }
}

// Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* tree) const {
  if (tree->left == NULL && tree->right == NULL) //leaf node
    return (stoi(tree->value));

  int leftRes = calculate(tree->left);
  int rightRes = calculate(tree->right);

  if (tree->value == "+")
    return leftRes + rightRes;
  else if (tree->value == "-")
    return leftRes - rightRes;
  else if (tree->value == "*")
    return leftRes * rightRes;
  else
    return leftRes / rightRes;
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
  return calculate(expressionStack.top());
}
