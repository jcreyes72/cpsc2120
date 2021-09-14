#include <iostream>
using namespace std;
#include "fraction.h"

int main( ) {

  Fraction F(1/4), G(3,-5), H(7,28), I(H);

  F = F+G;
  G = I*H;

  cout << F << " " << G << " " << H << " " << I << endl;
  cout << "Comparing first and last: " << boolalpha << (F == I) << endl;
  cout << "Input fraction: ";
  cin >> F;
  cout << endl << "You inputted " << F << endl;

  G = H = I = F;
  cout << endl << "And now all fractions are: " << G << endl;
  return 0;

}
