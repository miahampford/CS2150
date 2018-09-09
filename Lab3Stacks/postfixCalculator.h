// Amelia Hampford
// agh3ft
// 01/24/18
// postfixCalculator.h

#ifndef POSTFIXCALCULATOR_H
#define POSTFIXCALCULATOR_H

#include <iostream>
//#include <stack>
#include "stack.h"
using namespace std;

class PostfixCalculator {
public:
  PostfixCalculator();
  void pushNum(int x);
  void add();   //addition
  void subtract();  //subtraction
  void multiply();  //multiplication
  void divide();  //division
  void unNeg();  //unary negation
  int getTopValue();

 private:
  stack nums;
};

#endif
