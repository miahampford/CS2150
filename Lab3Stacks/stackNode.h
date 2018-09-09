// Amelia Hampford
// agh3ft
// 02/07/18
// stackNode.h

#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>
#include "stack.h"
using namespace std;

class stackNode  {
public:
    stackNode();                

private:
    int value;
    stackNode  *next;
    friend class stack;
};

#endif
