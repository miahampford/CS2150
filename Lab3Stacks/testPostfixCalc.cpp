// Amelia Hampford
// agh3ft
// 01/24/18
// testpostfixCalc.cpp

#include "postfixCalculator.h"
#include <iostream>
using namespace std;

int main() {
  string s;
  PostfixCalculator p;

  while (cin >> s) {
    cout << s << endl;
    const char*c = s.c_str();

    if(atoi(c) != 0){
      p.pushNum(atoi(c));}
    else if (s == "0"){
      p.pushNum(0);}
    else if (s == "+"){
      p.add();}
    else if (s == "*"){
      p.multiply();}
    else if (s == "/"){
      p.divide();}
    else if (s == "-"){
      p.subtract();}
    else if (s == "~"){
      p.unNeg();}
   
  }

  cout << "Result: " <<  p.getTopValue() << endl;
 
  return 0;
}
