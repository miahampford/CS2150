#include "List.h"
#include "ListNode.h"
#include "ListItr.h"
#include <iostream>
#include <string>
using namespace std;

List::List() {                      // Constructor
  head = new ListNode;
  tail = new ListNode;
  head->next = tail;
  tail->previous = head;
  count = 0;
}

List::List(const List& source) {      // Copy Constructor
    head=new ListNode;
    tail=new ListNode;
    head->next=tail;
    tail->previous=head;
    count=0;
    ListItr iter(source.head->next);
    while (!iter.isPastEnd()) {       // deep copy of the list
        insertAtTail(iter.retrieve());
        iter.moveForward();
    }
}

List :: ~List(){                    //Destructor
  makeEmpty();
  delete head;
  delete tail;
}

List& List::operator=(const List& source) { //Equals operator
    if (this == &source)
        return *this;
    else {
        makeEmpty();
        ListItr iter(source.head->next);
        while (!iter.isPastEnd()) {
            insertAtTail(iter.retrieve());
            iter.moveForward();
        }
    }
    return *this;
}


bool List :: isEmpty() const{ //Return true if empty; else false
  return (count == 0);
}

void List :: makeEmpty() { //Removes all items except blank head and tail
  ListItr iter(first());
  while (!iter.isPastEnd()){
    remove(iter.retrieve());
    iter.moveForward();
  }
  head->next = tail;
  tail->previous = head;
  count = 0;
}

ListItr List :: first(){ //Returns an iterator that points to the ListNode in the first position
  return  ListItr(head->next);
}

ListItr List :: last(){ //Returns an iterator that points to the ListNode in the last position
  return ListItr(tail->previous);
}

void List :: insertAfter(int x, ListItr position){ //Inserts x after current iterator position
  if (!position.isPastEnd() && !position.isPastBeginning()){
    ListNode *node = new ListNode;
    node->value = x;
    node->next = position.current->next;
    node->previous = position.current;
    position.current->next->previous=node;
    position.current->next = node;
    count += 1;
  }
}

void List :: insertBefore(int x, ListItr position){ //Inserts x before current iterator position
  if (!position.isPastEnd() && !position.isPastBeginning()){
    ListNode *node = new ListNode;
    node->value = x;
    node->next = position.current;
    node->previous = position.current->previous;
    position.current->previous->next = node;
    position.current->previous = node;
    count += 1;
  }
}

void List :: insertAtTail(int x){ //Inserts x at tail of list
  ListNode *node = new ListNode;
  node->value = x;
  node->next = tail;
  node->previous = tail->previous;
  tail->previous->next = node;
  tail->previous = node;
  count += 1;
}

void List :: remove(int x){ //Removes the first occurence of x
  ListItr iter = find(x);
  if(!iter.isPastEnd() && !iter.isPastBeginning()){
    iter.current->next->previous = iter.current->previous;
    iter.current->previous->next = iter.current->next;
    delete iter.current;
    count -= 1;
  }
}

ListItr List :: find(int x){ //Returns an iterator that points to the first occurence of x, else return an iterator to the dummy node
  ListItr iter(head);
  while (!iter.isPastEnd()){
    if (iter.current->value == x)
      return iter;
    iter.moveForward();
  }
  return iter;
}

int List :: size() const{ //Returns the number of elements in the list
  return count;
}

void printList(List& source, bool direction){
  string ret = "";
  if(direction){
    ListItr iter(source.first());
    while (!iter.isPastEnd()) {      
      ret = ret + to_string(iter.retrieve()) + ", ";
      iter.moveForward();
    }
  }
  else{
    ListItr iter(source.last());
    while (!iter.isPastBeginning()) {      
      ret = ret + to_string(iter.retrieve()) + ", ";
      iter.moveBackward();
    }
  }
  ret.pop_back();
  ret.pop_back();
  cout << ret << "\n" <<  endl;
}
