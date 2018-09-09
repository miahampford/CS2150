// Amelia Hampford
// agh3ft
// 02/07/18
// stack.h

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include "stackNode.h"
using namespace std;

class stackNode;

class stack {
public:
  stack();
  void push(int x);
  int top();
  void pop();
  bool empty();

private:
  stackNode * head;
  int count;
    
};

#endif
