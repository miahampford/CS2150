// Amelia Hampford
// agh3ft
// 02/25/18
// TreeCalc.cpp:  CS 2150 Tree Calculator method implementations

//TO DO
//terminate with new line character
//destructor
//clean tree
//calculate

#include "TreeCalc.h"
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//Constructor
TreeCalc::TreeCalc() {
  stack<TreeNode*> mystack;
}

//Destructor- frees memory
TreeCalc::~TreeCalc() {
  while(mystack.size()!=0 && mystack.top()!= NULL) {
    cleanTree(mystack.top());
    mystack.pop();}
}

//Deletes tree/frees memory
void TreeCalc::cleanTree(TreeNode* ptr) {
  if(ptr->left != NULL){
    cleanTree(ptr->left);}
  if(ptr->right != NULL){
    cleanTree(ptr->right);}
  delete ptr;
  ptr->left = NULL;
  ptr->right = NULL;
}

//Gets data from user
void TreeCalc::readInput() {
  string response;
  cout << "Enter elements one by one in postfix notation" << endl
       << "Any non-numeric or non-operator character,"
       << " e.g. #, will terminate input" << endl;
  cout << "Enter first element: ";
  cin >> response;
  //while input is legal
  while (isdigit(response[0]) || response[0]=='/' || response[0]=='*'
	 || response[0]=='-' || response[0]=='+' ) {
    insert(response);
    cout << "Enter next element: ";
    cin >> response;
  }
}

//Puts value in tree stack
void TreeCalc::insert(const string& val) {  
  TreeNode *node = new TreeNode(val);
  const char* cval= val.c_str();
  if(atoi(cval) != 0){
    mystack.push(node);}
  else if (val == "0"){
    mystack.push(node);}
  else if (val == "+" || val == "-" || val == "*" || val == "/"){
    node->right = mystack.top();
    mystack.pop();
    node->left = mystack.top();
    mystack.pop();
    mystack.push(node);}
}

//Prints data in prefix form
void TreeCalc::printPrefix(TreeNode* ptr) const {
  if (mystack.size()!=0 && mystack.top()!= NULL) {
    cout <<  ptr->value << " ";
    if (ptr->left != NULL){
      printPrefix(ptr->left);}
    if (ptr->right != NULL){
      printPrefix(ptr->right);}
  }
  else{
    cout << "\n";}
}

//Prints data in infix form
void TreeCalc::printInfix(TreeNode* ptr) const {
  if (mystack.size()!=0 && mystack.top()!= NULL) {
    if(ptr->value == "+" ||ptr->value == "-" ||ptr->value == "*" ||ptr->value == "/"){
      cout << "(";
    }
    if(ptr->left != NULL){
      printInfix(ptr->left);}
    if(ptr->value == "+" ||ptr->value == "-" ||ptr->value == "*" ||ptr->value == "/"){
      cout << " " << ptr->value << " ";}
    else{
      cout << ptr->value;}
    if(ptr->right != NULL){
      printInfix(ptr->right);}
    if(ptr->value == "+" ||ptr->value == "-" ||ptr->value == "*" ||ptr->value == "/"){
      cout << ")";
    }
  }
  else{
    cout << "\n";}
}

//Prints data in postfix form
void TreeCalc::printPostfix(TreeNode* ptr) const {
  if (mystack.size()!=0 && mystack.top()!= NULL) {
    if(ptr->left == NULL && ptr->right ==NULL){
      cout << ptr->value << " ";}
    else{
      if(ptr->left != NULL){
	printPostfix(ptr->left);}
      if(ptr->right != NULL){
	printPostfix(ptr->right);}
      cout << ptr->value << " ";}
  }
  else{
    cout << "\n";}
}

// Prints tree in all 3 (pre,in,post) forms
void TreeCalc::printOutput() const {
  if (mystack.size()!=0 && mystack.top()!= NULL) {
    cout << "Expression tree in postfix expression: ";
    printPostfix(mystack.top());
    cout << endl;
    cout << "Expression tree in infix expression: ";
    printInfix(mystack.top());
    cout << endl;
    cout << "Expression tree in prefix expression: ";
    printPrefix(mystack.top());
    cout << endl;
  }
  else{
    cout<< "Size is 0." << endl;}
}

//Evaluates tree, returns value
// private calculate() method
int TreeCalc::calculate(TreeNode* ptr) const {
  if(atoi(ptr->value.c_str()) != 0){
    return atoi(ptr->value.c_str());}
  else if(ptr->value == "0") {
    return 0;}
  else if(ptr->value == "+"){
    return calculate(ptr->left) + calculate(ptr->right);}
  else if(ptr->value == "-"){
    return calculate(ptr->left) - calculate(ptr->right);}
  else if(ptr->value == "*"){
    return calculate(ptr->left) * calculate(ptr->right);}
  else if(ptr->value == "/"){
    return calculate(ptr->left) / calculate(ptr->right);}
  else{
    return 0;}
  
}

//Calls calculate, sets the stack back to a blank stack
// public calculate() method. Hides private data from user
int TreeCalc::calculate() {
  int i = 0;
  if(mystack.size()!=0 && mystack.top()!= NULL){
    i = calculate(mystack.top());}
  while(mystack.size()!=0 && mystack.top()!= NULL){
    cleanTree(mystack.top());
    mystack.pop();}
  return i;
}
