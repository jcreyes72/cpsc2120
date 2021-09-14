#ifndef LISTQUEUE_H_INCLUDED
#define LISTQUEUE_H_INCLUDED

/*
 * Name: Julio Reyes
 * Date Submitted:
 * Lab Section: 004
 * Assignment Name: Lab 1 - Linked List Based Stacks and Queues
*/

#pragma once
#include "List.h"
#include <queue>


//This class represents a Queue implemented via Linked List
//Do not modify anything in the class interface
template <class T>
class ListQueue{

 private:
  List<T> queue;

 public:
  ListQueue();
  ~ListQueue();
  int size();
  bool empty();
  void enqueue(T);
  T dequeue();
  //Print the name and this ListQueue's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    queue.print(name);
  }

}; //end of class interface (you may modify the code below)






//----------------------------------------------------------------------------\\
//                        FUNCTION IMPLEMENTATION                             \\
//----------------------------------------------------------------------------\\



//------------------------
// LIST QUEUE CONSTRUCTOR |
//-----------------------------------------------------------------------------
// Return: This function does not have a return value                         |
//                                                                            |
// Parameters: This function does not take in any parameters                  |
//                                                                            |
// Description: This function constructs an empty ListQueue                   |
//-----------------------------------------------------------------------------
template <class T>
ListQueue<T>::ListQueue(){

    // Nothing needs to be done here...at least I don't think so

}
//-----------------------------------------------------------------------------




//------------------------
// LIST QUEUE DESTRUCTOR  |
//-----------------------------------------------------------------------------
// Return: This function does not have a return value                         |
//                                                                            |
// Parameters: This function does not take in any parameters                  |
//                                                                            |
// Description: This function destroys all nodes in the ListQueue             |
//-----------------------------------------------------------------------------
template <class T>
ListQueue<T>::~ListQueue(){

}
//-----------------------------------------------------------------------------




//------------------------
// LIST QUEUE SIZE       |
//-----------------------------------------------------------------------------
// Return: This function returns an int                                       |
//                                                                            |
// Parameters: This function does not take in any parameters                  |
//                                                                            |
// Description: This function returns the size of the queue                   |
//-----------------------------------------------------------------------------
template <class T>
int ListQueue<T>::size(){

    return this->queue.size();

}
//-----------------------------------------------------------------------------





//-------------------
// LIST QUEUE EMPTY? |
//-----------------------------------------------------------------------------
// Return: This function returns either true or false                         |
//                                                                            |
// Parameters: This function does not take any parameters                     |
//                                                                            |
// Description: This function returns true if the queue is empty and false    |
// otherwise                                                                  |
//-----------------------------------------------------------------------------
template <class T>
bool ListQueue<T>::empty(){

    if (this->queue.size() == 0){
        return true;
    }
    else {
        return false;
    }

}
//-----------------------------------------------------------------------------






//--------------------
// LIST QUEUE ENQUEUE |
//-----------------------------------------------------------------------------
// Return: This function returns void                                         |
//                                                                            |
// Parameters: This function takes in a template value, called value          |
//                                                                            |
// Description: This function creates a new node with the given value, and    |
// inserts that node into the ListQueue in its correct position               |
//-----------------------------------------------------------------------------
template <class T>
void ListQueue<T>::enqueue(T value){

    this->queue.insertStart(value);

}
//-----------------------------------------------------------------------------






//--------------------
// LIST QUEUE DEQUEUE |
//-----------------------------------------------------------------------------
// Return: This function returns an template value, called nodeValue          |
//                                                                            |
// Parameters: This function does not take in any parameters                  |
//                                                                            |
// Description: This function removes an element from the queue and returns   |
// that elements value                                                        |
//-----------------------------------------------------------------------------
template <class T>
T ListQueue<T>::dequeue(){

    int listSize = this->queue.size();

    T var = this->queue.getAt(listSize);
    this->queue.removeEnd();

return var;
}
//-----------------------------------------------------------------------------


#endif // LISTQUEUE_H_INCLUDED
