// Amelia Hampford
// agh3ft
// 01/24/18
// postfixCalculator.cpp

#include "postfixCalculator.h"
#include "stack.h"
#include <iostream>
//#include <stack>
#include <cstdlib>
using namespace std;

PostfixCalculator:: PostfixCalculator(){
  stack nums;
}

void PostfixCalculator::pushNum(int x){
  nums.push(x);
}

void PostfixCalculator::add(){
  int a,b = 0;
  a = getTopValue();
  nums.pop();
  b = getTopValue();
  nums.pop();
  nums.push(a+b);
}

void PostfixCalculator::subtract(){
  int a,b = 0;
  a = getTopValue();
  nums.pop();
  b = getTopValue();
  nums.pop();
  nums.push(b-a);
}

void PostfixCalculator::multiply(){
  int a,b = 0;
  a = getTopValue();
  nums.pop();
  b = getTopValue();
  nums.pop();
  nums.push(a*b);
}

void PostfixCalculator::divide(){
  int a,b = 0;
  a = getTopValue();
  nums.pop();
  b = getTopValue();
  nums.pop();
  nums.push(b/a);
}

void PostfixCalculator::unNeg(){
  int a;
  a = getTopValue();
  nums.pop();
  nums.push(a*(-1));
}

int PostfixCalculator::getTopValue(){
  if(!nums.empty()){
    return nums.top();
  }
  else{
    cout << "Error: stack is empty" << endl;
    exit(-1);
  }
}

