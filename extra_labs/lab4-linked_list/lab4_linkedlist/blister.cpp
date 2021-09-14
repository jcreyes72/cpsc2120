#include "blister.h"

//Blister Constructor Definition
//-----------------------------------------------------------------------------------
//This constructor will take in a string and create a linked list from the characters
//in order. The linked list will be created from the Bode struct in blister.h
//-----------------------------------------------------------------------------------

Blister::Blister(std::string currentBode){

    int n = currentBode.length();           // setting an integer n equal to the length
                                            // of the string

        for (int i = 0; i < n; i++){

            current = new Bode(currentBode[i]);         // creating new Bode pointer

                if ((temp != nullptr)){      // if temp has already been set,
                    temp->next = current;    // it will be used to link old node to
                }                            // the new one

                if (i == 0){
                    head = current;        // sets the link list head if its the first
                }                          // character

            temp = current;                // setting temp pointer equal to current
        }
}
//-----------------------------------------------------------------------------------




//Blister Destructor Definition
//-----------------------------------------------------------------------------------
//This destructor will clear any memory created from the Blister object
//-----------------------------------------------------------------------------------

Blister::~Blister(){

    delete head;
    delete temp;
    delete current;

}
//-----------------------------------------------------------------------------------




//Stream Operator Definition
//-----------------------------------------------------------------------------------
//This stream operator will output to the user the linked list of bases from the
//string that has been entered
//-----------------------------------------------------------------------------------

std::ostream &operator<<(std::ostream &out, Blister &myBlister){


    Blister *newPoint = &myBlister;                 // Creating a new object pointer and making it
                                                    // point to myBlister

    Bode* oldHead = newPoint->head;                 // Saving where head is currently pointing to
                                                    // by setting oldHead equal to it. This will
                                                    // allow us to change head, then set it back
                                                    // to its previous state after while loop


        while (newPoint->head != NULL) {            // This will print out the users entered string
            out << newPoint->head->base;            // by going through the link list
            newPoint->head = newPoint->head->next;
        }


    newPoint->head = oldHead;                       // Putting head back to its original state

return out;
}
//-----------------------------------------------------------------------------------



//Length Function Definition
//-----------------------------------------------------------------------------------
//This length function will give the number of bases contained in the linked list
//being called upon
//-----------------------------------------------------------------------------------

int Blister::length(){

    int numBase = 0;                                // Our count, which will keep track of the length

    Blister *newPoint = this;                       // Creating a new object pointer and making it
                                                    // point to this

    Bode* oldHead = newPoint->head;                 // Saving where head is currently pointing to
                                                    // by setting oldHead equal to it. This will
                                                    // allow us to change head, then set it back
                                                    // to its previous state after while loop


        while (newPoint->head != NULL) {            // This will increase numBase by 1 through
            numBase++;                              // each base in the list
            newPoint->head = newPoint->head->next;
        }

    newPoint->head = oldHead;                       // Putting head back to its original state


return numBase;
}
//-----------------------------------------------------------------------------------



//isInsertionOf Function Definition
//-----------------------------------------------------------------------------------
//The isInsertionOf function will compare two base-sequences and return true if the
//one it is called on can be obtained by adding exactly one base to the other base
//sequence
//-----------------------------------------------------------------------------------

bool Blister::isInsertionOf(Blister &other) {


    Blister *leftPoint = this;                       // Creating a new object pointer and making it
                                                     // point to this

    Blister *rightPoint = &other;                    // Creating another object pointer and making
                                                     // it point to &other

    int numWrong = 0;                                // This will be used as a count for how many
                                                     // times the bases in the respective objects
                                                     // fail to match. If numWrong exceeds the
                                                     // number 1, the function will return false


    //------CHECKPOINTS--------------------------------

    Bode* leftHead = leftPoint->head;                // Saving where our leftpoint and rightpoint
                                                     // head is currently pointing to by setting
                                                     // leftHead and rightHead equal to them. This will
    Bode* rightHead = rightPoint->head;              // allow us to change the heads, then set them back
                                                     // to their previous states after while loop.
                                                     // Like checkpoints in a way.

    //-------------------------------------------------




        while (leftPoint->head != NULL){                                // This while loop will iterate
                                                                        // through both lists. If the
            if ((leftPoint->head->base) == (rightPoint->head->base)){   // bases match up, both lists
                leftPoint->head = leftPoint->head->next;                // will move forward. If the
                rightPoint->head = rightPoint->head->next;              // bases do not match, the left
            }                                                           // list will move forward but
            else {                                                      // the right list will not.
                leftPoint->head = leftPoint->head->next;                // numWrong will increase by 1
                numWrong++;
            }
        }


    leftPoint->head = leftHead;                         // Putting heads back to their original state
    rightPoint->head = rightHead;


        if (numWrong != 1){                             // if the number of bases that do not match exceeds
            return false;                               // 1, the function will return false
        }


return true;
}
//-----------------------------------------------------------------------------------
