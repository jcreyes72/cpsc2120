// Fraction.cpp - wdg 2016
#include <sstream>
using namespace std;
#include "fraction.h"

//CONSTRUCTORS---------------------------------------------------

        //WHOLE NUM
Fraction::Fraction(int whole) : numer(whole), denom(1){}


        //FRACTION
Fraction::Fraction(int n,int d) : numer(n), denom(d) {
  simplify( );
}

        //COPY
Fraction::Fraction(const Fraction & other) : numer(other.numer), denom(other.denom){}


//---------------------------------------------------------------





//STREAM OPERATORS-----------------------------------------------


ostream & operator<< (ostream & out, const Fraction & fraction) {

   if(fraction.denom == 1){
      out << fraction.numer;
   }
   else{
      out << fraction.numer << Fraction::SLASH << fraction.denom;
   }

return out;
}



istream & operator>> (istream & in, Fraction & fraction) {

    // NOT ROBUST!!!
    string input;
    in >> input;

    // size_t is an unsigned integer type
    size_t slashPos = input.find( Fraction::SLASH );

        if( slashPos == string::npos ) {
            fraction.denom = 1;
            fraction.numer = stoi(input);
        }
        else{
            string N = input.substr(0, slashPos);
            fraction.numer = stoi(N);
            string D = input.substr(slashPos+1);
            fraction.denom = stoi(D);
        }


fraction.simplify( );

return in;
}
//---------------------------------------------------------------





//ASG OPERATORS--------------------------------------------------

Fraction & Fraction::operator=(const Fraction & other) {

   if((this != &other)){
      numer=other.numer;
      denom=other.denom;
   }

return *this;
}


Fraction Fraction::operator+(const Fraction & other) const {

   int newNumer = (numer * other.denom) + (denom * other.numer);
   int newDenom = denom * other.denom;


   return Fraction(newNumer, newDenom);
}


Fraction Fraction::operator*(const Fraction & other) const {

   int newNumer = numer*other.numer;
   int newDenom = denom * other.denom;

return Fraction(newNumer,newDenom);
}


bool Fraction::operator==(const Fraction & other) const {
   return ((numer == other.numer) && (denom == other.denom));
}

//--------------------------------------------------------------





//OTHERS--------------------------------------------------------

void Fraction::simplify( ) {

   if(denom < 0) {
      denom = -denom;
      numer = -numer;
   }

   int h = Fraction::gcd((numer<0 ? -numer : numer), denom);

   numer /= h;
   denom /= h;
}


int Fraction::gcd(int a,int b){

   if(b == 0)
      return a;
   else
      return gcd (b, a%b);

}


//--------------------------------------------------------------



