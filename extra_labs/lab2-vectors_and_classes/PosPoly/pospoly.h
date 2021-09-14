#ifndef POSPOLY_H_INCLUDED
#define POSPOLY_H_INCLUDED

#include <iostream>
#include <stdlib.h>
#include <vector>

//Pair Class
//-------------------------------------------------------------------------------------
//Contains the power and coefficient for each number of the polynomial

class Pair {
    public:
        int power;                      //number power
        int coefficient;                //number coefficient
};

//-------------------------------------------------------------------------------------




//PosPoly Class
//-------------------------------------------------------------------------------------
//Holds the number of powers currently in polynomial, as well as the numbers themselves
//stored as a vector of class Pair

class PosPoly {
    private:
        int numPow;                     //Counts the number of powers in the polynomial

    public:
        PosPoly ();                     //Default constructor which will initializes
                                        //the polynomial to 0
        std::vector<Pair> pairVector;   //Vector which stores numbers
        friend std::ostream &operator<< (std::ostream &, const PosPoly&);  //Stream operator for output
        void incrementBy (int, int);    //increments the current polynomial
        bool operator== (const PosPoly);//Boolean test for whether two polynomials are equal

};

//-------------------------------------------------------------------------------------





#endif // POSPOLY_H_INCLUDED
