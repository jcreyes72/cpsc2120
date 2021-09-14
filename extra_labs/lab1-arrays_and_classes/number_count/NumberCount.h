#include <iostream>
#include <stdlib.h>
#include <string>


#ifndef NUMBERCOUNT_H_INCLUDED
#define NUMBERCOUNT_H_INCLUDED


//This h file involves the class "NumberCount" which will be the
//primary class used to receive our set of numbers, remove/add numbers
//and print the final result of said set

class NumberCount {
private:
    int min;                                                        //the smallest integer allowed in set
    int max;                                                        //the largest integer allowed in set
    std::string *numSet = new std::string [max-min+1];              //the set of integers we will be using

public:
    //Constructor
    NumberCount();
    NumberCount(int, int);     //constructor receives 2 ints, sets them equal to min and max
    ~NumberCount ();            //destructor which clears space from numSet
    void addElement (int);      //increments the count of number
    void removeElement (int);   //decrements the count of number
    void display();             //draws the results as a histogram

};



#endif // NUMBERCOUNT_H_INCLUDED
