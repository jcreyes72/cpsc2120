#ifndef LISTSTACK_H_INCLUDED
#define LISTSTACK_H_INCLUDED

/*
 * Name: Julio Reyes
 * Date Submitted:
 * Lab Section: 004
 * Assignment Name: Lab 1 - Linked List Based Stacks and Queues
*/

#pragma once
#include "List.h"


//This class represents a Stack implemented via Linked List
//Do not modify anything in the class interface
template <class T>
class ListStack{

 private:
  List<T> stack;

 public:
  ListStack();
  ~ListStack();
  int size();
  bool empty();
  void push(T);
  T pop();
  //Print the name and this ListStack's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    stack.print(name);
  }

}; //end of class interface (you may modify the code below)







//----------------------------------------------------------------------------\\
//                        FUNCTION IMPLEMENTATION                             \\
//----------------------------------------------------------------------------\\


//------------------------
// LIST STACK CONSTRUCTOR |
//-----------------------------------------------------------------------------
// Return: This function does not have a return value                         |
//                                                                            |
// Parameters: This function does not take in any parameters                  |
//                                                                            |
// Description: This function constructs an empty ListStack                   |
//-----------------------------------------------------------------------------
template <class T>
ListStack<T>::ListStack(){
    // Nothing needs to be done here
}
//-----------------------------------------------------------------------------



//------------------------
// LIST STACK DESTRUCTOR  |
//-----------------------------------------------------------------------------
// Return: This function does not have a return value                         |
//                                                                            |
// Parameters: This function does not take in any parameters                  |
//                                                                            |
// Description: This function destroys all nodes in the ListStack             |
//-----------------------------------------------------------------------------
template <class T>
ListStack<T>::~ListStack(){

    this->stack.~List();

}
//-----------------------------------------------------------------------------



//------------------------
// LIST STACK SIZE       |
//-----------------------------------------------------------------------------
// Return: This function returns an int                                       |
//                                                                            |
// Parameters: This function does not take in any parameters                  |
//                                                                            |
// Description: This function returns the size of the stack                   |
//-----------------------------------------------------------------------------
template <class T>
int ListStack<T>::size(){

    return this->stack.size();

}
//-----------------------------------------------------------------------------



//-------------------
// LIST STACK EMPTY? |
//-----------------------------------------------------------------------------
// Return: This function returns either true or false                         |
//                                                                            |
// Parameters: This function does not take any parameters                     |
//                                                                            |
// Description: This function returns true if the stack is empty and false    |
// otherwise                                                                  |
//-----------------------------------------------------------------------------
template <class T>
bool ListStack<T>::empty(){

    if (this->stack.size() == 0){
        return true;
    }
    else {
        return false;
    }
}
//-----------------------------------------------------------------------------



//--------------------
// LIST STACK PUSH |
//-----------------------------------------------------------------------------
// Return: This function returns void                                         |
//                                                                            |
// Parameters: This function takes in a template value, called value          |
//                                                                            |
// Description: This function creates a new node with the given value, and    |
// inserts that node into the ListStack in its correct position               |
//-----------------------------------------------------------------------------
template <class T>
void ListStack<T>::push(T value){

    this->stack.insertStart(value);

}
//-----------------------------------------------------------------------------



//--------------------
// LIST STACK POP     |
//-----------------------------------------------------------------------------
// Return: This function returns an template value, called nodeValue          |
//                                                                            |
// Parameters: This function does not take in any parameters                  |
//                                                                            |
// Description: This function removes an element from the stack and returns   |
// that elements value                                                        |
//-----------------------------------------------------------------------------
template <class T>
T ListStack<T>::pop(){

    int listSize = this->stack.size();

    listSize = listSize - (listSize - 1);

    T var = this->stack.getAt(listSize);

    this->stack.removeStart();


}
//-----------------------------------------------------------------------------



#endif // LISTSTACK_H_INCLUDED
