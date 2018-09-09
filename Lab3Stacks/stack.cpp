// Amelia Hampford
// agh3ft
// 02/07/18
// stack.cpp

#include "stackNode.h"
#include "stack.h"
using namespace std;

stack :: stack(){
  head = NULL;
  count = 0;
}

void stack::push(int x){
  stackNode * temp = head;
  head = new stackNode();
  head->value = x;
  head->next = temp;
  count = count +  1;
}

int stack::top(){
  return head->value;
}

void stack::pop(){
  head = head->next;
  count = count - 1;
}

bool stack::empty(){
  return (count == 0);
}
