#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

/*
 * Name: Julio Reyes
 * Date Submitted:
 * Lab Section: 004
 * Assignment Name: Lab 1 - Linked List Based Stacks and Queues
*/

#pragma once

#include <iostream>
#include <string>
#include "Node.h"

using namespace std;

//This class represents a linked list of node objects
//Do not modify anything in the class interface
template <class T>
class List{

 private:
  Node<T> * start; //pointer to the first node in this list
  int mySize;  //size (or length) of this list

 public:
  List();
  ~List();
  int size();
  bool empty();
  void insertStart(T);
  void insertEnd(T);
  void insertAt(T, int);
  void removeStart();
  void removeEnd();
  void removeAt(int);
  T getFirst();
  T getLast();
  T getAt(int);
  int find(T);

  //Print the name and this list's size and values to stdout
  //This function is already implemented (no need to change it)
  void print(string name){
    cout << name << ": ";
    cout << "size = " << size();
    cout << ", values = ";
    Node<T> * iterator = start;
    while(iterator != nullptr){
      cout << iterator->value << ' ';
      iterator = iterator->next;
    }
    cout << endl;
  }

}; //end of class interface (you may modify the code below)






//----------------------------------------------------------------------------\\
//                        FUNCTION IMPLEMENTATION                             \\
//----------------------------------------------------------------------------\\



//------------------
// LIST CONSTRUCTOR |
//-----------------------------------------------------------------------------
// Return:  This function is a constructor and thus does not return           |
//                                                                            |
// Parameters: This function does not contain any parameters                  |
//                                                                            |
// Description: This function constructs an empty list by initializing the    |
// instance variables of the class                                            |
//-----------------------------------------------------------------------------

template <class T>

List<T>::List(){

    start = nullptr;
    mySize = 0;

}
//-----------------------------------------------------------------------------




//------------------
// LIST DESTRUCTOR |
//-----------------------------------------------------------------------------
// Return:  This function is a destructor and does not return                 |
//                                                                            |
// Parameters: This function does not contain any parameters                  |
//                                                                            |
// Description: This function destroys all nodes in the list to prevent       |
// memory leaks                                                               |
//-----------------------------------------------------------------------------
template <class T>
List<T>::~List(){

    Node<T> *temp = start;              // Setting temp node equal to start

        while (start != nullptr){
            delete temp;
            start = start->next;
            temp = start;
        }
}
//-----------------------------------------------------------------------------





//------------
// LIST SIZE |
//-----------------------------------------------------------------------------
// Return:  This function returns an int, mySize                              |
//                                                                            |
// Parameters: This function does not contain any parameters                  |
//                                                                            |
// Description: This function returns the size of the list                    |
//-----------------------------------------------------------------------------
template <class T>
int List<T>::size(){

    return mySize;

}
//-----------------------------------------------------------------------------





//------------
// LIST EMPTY |
//-----------------------------------------------------------------------------
// Return:  This function returns bool, true or false                         |
//                                                                            |
// Parameters: This function does not contain any parameters                  |
//                                                                            |
// Description: This function returns true if the list is empty and false     |
// otherwise                                                                  |
//-----------------------------------------------------------------------------
template <class T>
bool List<T>::empty(){

    if (mySize == 0){       // If list size is 0
        return true;        // return true
    }
    else {                  // Otherwise
        return false;       // return false
    }
}
//-----------------------------------------------------------------------------




//----------------------
// LIST INSERT AT START |
//-----------------------------------------------------------------------------
// Return:  This function returns void                                        |
//                                                                            |
// Parameters: This function contains a value (arbitrary type) which will be  |
// set as the value for the new node being created                            |
//                                                                            |
// Description: This function creates a new node with a value, and inserts    |
// the node into the list at the start                                        |
//-----------------------------------------------------------------------------
template <class T>
void List<T>::insertStart(T value){


    Node<T> *newHead = new Node<T>(value);      // Allocating space for the new node

    if (mySize == 0){
        start = newHead;
        newHead->next = nullptr;
    }
    else {
       newHead->next = start;                   // Making the next node point to what
                                                 // we currently have as the first node
                                                 // so as to establish that this is now
                                                 // the new head

        start = newHead;                         // Making our start pointer equal to
                                                 // our brand new head node
    }
    mySize++;
}
//-----------------------------------------------------------------------------




//----------------------
// LIST INSERT AT END  |
//-----------------------------------------------------------------------------
// Return:  This function returns void                                        |
//                                                                            |
// Parameters: This function contains a value (arbitrary type) which will be  |
// set as the value for the new node being created                            |
//                                                                            |
// Description: This function creates a new node with a value, and inserts    |
// the node into the list at the end                                          |
//-----------------------------------------------------------------------------
template <class T>
void List<T>::insertEnd(T value){

    Node<T> *newEnd = new Node<T>(value);       // Allocating space for new node

        if (mySize == 0){
            start = newEnd;
        }
        else {
            Node<T> *temp = start;              // Creating temp node to use
                while (temp->next != nullptr){
                    temp = temp->next;
                }
            temp->next = newEnd;
        }

    mySize++;

}
//-----------------------------------------------------------------------------




//--------------------------
// LIST INSERT AT POSITION  |
//-----------------------------------------------------------------------------
// Return:  This function returns void                                        |
//                                                                            |
// Parameters: This function contains a value (arbitrary type) which will be  |
// set as the value for the new node being created, and an int, j, which      |
// indicates the position our new node will be set at                         |
//                                                                            |
// Description: This function creates a new node with a value, and inserts    |
// the node at position j                                                     |
//-----------------------------------------------------------------------------
template <class T>
void List<T>::insertAt(T value, int j){

    Node<T> *newNode = new Node<T>(value);
    Node<T> *previous;
    Node<T> *current = start;

    int i = 0;

        while (current->next != nullptr){
            previous = current;
            current = current->next;
            i++;
                if (i == j){
                    previous->next = newNode;
                    newNode->next = current;
                    mySize++;
                    return;
                }
        }

}
//-----------------------------------------------------------------------------




//--------------------------
// REMOVE NODE AT START     |
//-----------------------------------------------------------------------------
// Return:  This function returns void                                        |
//                                                                            |
// Parameters: This function does not have any parameters                     |
//                                                                            |
// Description: This function removes the "start" node from the top of the    |
// list                                                                       |
//-----------------------------------------------------------------------------
template <class T>
void List<T>::removeStart(){

    if(mySize > 0) {
        Node<T> *temp = start->next; // New node temp to store start
        delete start; // Remove start
        start = temp;
        mySize--;
    }
}
//-----------------------------------------------------------------------------





//--------------------------
// REMOVE NODE AT END       |
//-----------------------------------------------------------------------------
// Return:  This function returns void                                        |
//                                                                            |
// Parameters: This function does not have any parameters                     |
//                                                                            |
// Description: This function removes the last node from the list             |
//                                                                            |
//-----------------------------------------------------------------------------
template <class T>
void List<T>::removeEnd(){


    Node<T> *temp = start;                 // Creating temp node to use

        while(temp->next != nullptr){      // Going through list...
            temp = temp->next;
        }

    mySize--;
    delete temp;                           // Remove last node
}
//-----------------------------------------------------------------------------




//----------------------------
// REMOVE NODE AT POSITION    |
//-----------------------------------------------------------------------------
// Return:  This function returns void                                        |
//                                                                            |
// Parameters: This function contains one parameter, j, which is the position |
// of the node that will be deleted                                           |
//                                                                            |
// Description: This function removes the node at a specified position        |
//-----------------------------------------------------------------------------
template <class T>
void List<T>::removeAt(int j){


    Node<T> *current = start;                       // "Current" node which serves as a type
                                                    // of temp
    Node<T> *previous = current;                    // "Previous" node which serves as a type
                                                    // of temp

    int i = 0;                                      // i variable for while loop

        while ((i < j) && (current != nullptr)){
            previous = current;                     // set previous to current
            current = current->next;                // change current location
            i++;                                    // iterate i till jth position
        }

    previous->next = current->next;                 // bypass current, link nodes
    mySize--;

}
//-----------------------------------------------------------------------------





//----------------------------
// RETURN FIRST NODE          |
//-----------------------------------------------------------------------------
// Return:  This function returns either the start pointer value or the       |
// default constructed value                                                  |
//                                                                            |
// Parameters: This function does not contain any parameters                  |
//                                                                            |
// Description: This function returns the value of the first node in the      |
// Linked List, if there is no first node, it returns the default constructed |
// value: T()                                                                 |
//-----------------------------------------------------------------------------
template <class T>
T List<T>::getFirst(){

    if (mySize == 0){
        return T();
    }
    else {
        return start->value;
    }

}
//-----------------------------------------------------------------------------




//----------------------------
// RETURN LAST NODE          |
//-----------------------------------------------------------------------------
// Return:  This function returns either the last node's value or the         |
// default constructed value                                                  |
//                                                                            |
// Parameters: This function does not contain any parameters                  |
//                                                                            |
// Description: This function returns the value of the last  node in the      |
// Linked List, if there is no first node, it returns the default constructed |
// value: T()                                                                 |
//-----------------------------------------------------------------------------
template <class T>
T List<T>::getLast(){

    Node<T> *temp = start;                          // Creating temp node to use


        if (start = nullptr){
            return T();
        }
        else {
            while(temp->next != nullptr){   // Going through list...
                temp = temp->next;
            }
            return temp->value;
        }

}
//-----------------------------------------------------------------------------






//----------------------------
// RETURN SPECIFIC NODE       |
//-----------------------------------------------------------------------------
// Return:  This function returns either the jth node's value or the          |
// default constructed value                                                  |
//                                                                            |
// Parameters: This function does not contain any parameters                  |
//                                                                            |
// Description: This function returns the value of the jth node in the        |
// Linked List, if there is no first node, it returns the default constructed |
// value: T()                                                                 |
//-----------------------------------------------------------------------------
template <class T>
T List<T>::getAt(int j){

    if (start = nullptr){
        return T();
    }

    Node<T> *temp = start;

        for (int i = 0; i < j; i++){
            temp = temp->next;
        }

    return temp->value;

}
//-----------------------------------------------------------------------------




//----------------------------
// RETURN KEY POSITION       |
//-----------------------------------------------------------------------------
// Return:  This function returns an int                                      |
//                                                                            |
// Parameters: This function takes in a template "key" parameter              |
//                                                                            |
// Description: This function returns the position of the (first) node whose  |
// value is equal to the key. Otherwise, it will return -1                    |                                                                |
//-----------------------------------------------------------------------------
template <class T>
int List<T>::find(T key){

    Node<T> *temp = start;              // Creating a temp node to use

    int position = 1;                   // This will keep track of our
                                        // list position

    while (temp->next != nullptr){      // Iterate through list
        if (temp->value == key){
            return position;
        }
        else {
            temp = temp->next;          // Going forward in list
            position++;                 // Increasing position
        }
    }

return -1;                              // If function exits, return -1
}
//-----------------------------------------------------------------------------



#endif // LIST_H_INCLUDED
