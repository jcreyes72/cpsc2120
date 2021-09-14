#ifndef BLISTER_H_INCLUDED
#define BLISTER_H_INCLUDED
#include <iostream>
#include <string>
#include <cstring>

struct Bode {
    char base;
    Bode* next;         //struct pointer
  public:
    Bode(char B){
        base = B;
        next = nullptr;
    }
};



class Blister {
  private:
    Bode* head;             //struct pointer that will point to head of list
    Bode* temp = nullptr;   //struct pointer that will allow us to set our next pointer to current
    Bode* current;          //struct pointer that will be used to create new nodes
  public:
    Blister(std::string);   //simple constructor
    ~Blister( );            //destructor
    friend std::ostream & operator<< ( std::ostream & out, Blister &myBlister);
    int length();
    bool isSubstitutionOf(Blister &other);
    bool isInsertionOf(Blister &other);
};

#endif // BLISTER_H_INCLUDED
