#include "pospoly.h"

//Default constructor PosPoly
//--------------------------------------------------------------------------------------
//Purpose: Called after creation of new object, initializes the current object to be set
//to zero, then pushes this object into our "pairVector" vector

PosPoly::PosPoly(){

    Pair newPair;               //creating new Pair object to store values

    newPair.power = 1;
    newPair.coefficient = 0;    //setting the two values in object so num is equal to 0

    pairVector.push_back(newPair);


}

//--------------------------------------------------------------------------------------



//Overloaded output stream operator
//--------------------------------------------------------------------------------------
//Purpose: Outputs our PosPoly vector to display polynomial to user

std::ostream &operator<< (std::ostream &out, const PosPoly &myPosPoly){

    for (const auto Pair : myPosPoly.pairVector){
        out << Pair.coefficient << "^" << Pair.power << " + ";
    }

return out;
};
//--------------------------------------------------------------------------------------



//IncrementBy Function
//--------------------------------------------------------------------------------------
//Purpose: Increments our polynomial by the coefficient and power provided in our param-
//eters, "coef and pow". If power already exists in polynomial, that object is simply
//updated. If power does not exist, a new object is created with coef and pow.

void PosPoly::incrementBy(int coef, int pow){

        int currentVec = 0;     // Int we will use to keep track of what element we are in in our vector

    //Detects whether this power already exists
    for (auto Pair : this->pairVector){

        //std::cout << "Current Coef = " << Pair.coefficient << "\tCurrent Power = " << Pair.power << std::endl;



        int tempCo;             // "Temporary Coefficient" that will hold our previous coefficient value
                                // so that we can delete it and replace it if need be


            // If the power of our current value in our vector is equal to the power of the value
            // given by the user, this if statement will update that value
            if ((Pair.power == pow)){

                //std::cout << "Current Vec was: " << currentVec << std::endl;

                    if ((currentVec == 0)){
                        currentVec = currentVec - 1;
                    //    std::cout << "WWWWWW" << std::endl;
                    }

                //std::cout << "Current Vec is now: " << currentVec << std::endl;

                tempCo = Pair.coefficient;
                Pair.coefficient = NULL;    //Getting rid of our current coefficient

                //Getting rid of our current vector element so we can update it
                this->pairVector.erase(this->pairVector.begin() + (currentVec + 1));

                //Updating our current coefficient
                Pair.coefficient = tempCo + coef;

                //Pushing our updated element into our vector
                this->pairVector.push_back(Pair);

                return;
            }
        currentVec += 1;
    }

    //If power does not exist, a new object is created with user input
    Pair addObject;
    addObject.power = pow;
    addObject.coefficient = coef;
    this->pairVector.push_back(addObject);        //pushing new object into vector
}

//--------------------------------------------------------------------------------------
