#include "NumberCount.h"

//Constructor Definition
//---------------------------------------------------------------
//Constructor receives 2 ints, sets them equal to min and max
//Parameters: mi is min, ma is max

NumberCount::NumberCount(int mi, int ma){

    min = mi;
    max = ma;

}

//---------------------------------------------------------------


//Destructor Definition
//---------------------------------------------------------------
//Destructor clears space allocated for pointer numSet
//Parameters: No parameters

NumberCount::~NumberCount(){

    delete []numSet;

}

//---------------------------------------------------------------



//addElement Definition
//---------------------------------------------------------------
//addElement increments the amount of number, takes in an integer
//which will be added to the set of numbers
//Parameters: numToAdd is the int which will be added

void NumberCount::addElement(int numToAdd){

    if ((numToAdd < min) || (numToAdd > max)){
        std::cout << numToAdd << " out of range; ";
    }
    else {
        numSet[numToAdd].push_back('*');
    }

}

//---------------------------------------------------------------


//removeElement Definition
//---------------------------------------------------------------
//removeElement decrements the amount of number, takes in an int
//which will be removed from the set of numbers
//Parameters: numToRem is the int which will be removed

void NumberCount::removeElement(int numToRem){

    //If number is out of bounds
    if ((numToRem < min) || (numToRem > max)){
        std::cout << numToRem << " out of range; ";
    }
    //If number is not present in set
    else if ((numSet[numToRem].empty())){
        std::cout << numToRem << " not present; ";
    }
    //Remove last '*' from string
    else {
        numSet[numToRem].pop_back();
    }
}

//---------------------------------------------------------------


//display Definition
//---------------------------------------------------------------
//display prints out the histogram containing set of numbers
//entered
//Parameters: No parameters

void NumberCount::display(){

    //print newline for display purposes
    std::cout << std::endl;

    //from min num to max
    for (int i = min; i <= max; i++){
        std::cout << i << ":" << numSet[i] << std::endl;
    }

}

//---------------------------------------------------------------
