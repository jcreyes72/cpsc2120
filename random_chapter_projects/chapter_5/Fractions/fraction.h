#ifndef FRACTION_H_INCLUDED
#define FRACTION_H_INCLUDED

#include <iostream>
using namespace std;

class Fraction {
public:
//CONSTRUCTORS
    Fraction(int whole);
    Fraction(int n,int d);
    Fraction(const Fraction & other);

//ASG OPERATORS
  Fraction & operator=(const Fraction & other );
  Fraction operator+(const Fraction & other) const;
  Fraction operator*(const Fraction & other) const;
  bool operator==(const Fraction & other ) const; // equality test

//FRIEND STREAM OPERATORS
  friend ostream & operator<< (ostream & out, const Fraction & fraction);
  friend istream & operator>> (istream & in, Fraction & fraction);

//OTHERS
  static const char SLASH = '/';

private:
  int numer;
  int denom;

  void simplify( );
  static int gcd(int a, int b);
};

#endif // FRACTION_H_INCLUDED
