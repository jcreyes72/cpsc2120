// TestCitizenToo.cpp - wdg - 2016
#include <iostream>
using namespace std;
#include "citizenstoo.h"

int main( ){

  Citizen one;

  string giJoe = "GI Joe";

  one.setName( giJoe );
  one.setAge(50);

  string barbie("Barbie");
  Citizen two(barbie,13);

  cout << "The drinking age is " << Citizen::DRINKING_AGE << endl;

  cout << one.getName();
  if (one.canDrink() )
    cout << " can drink\n";
  else
    cout << " can't drink\n";

  cout << two.getName();
  if ( two.canDrink() )
    cout << " can drink\n";
  else
    cout << " can't drink\n";

  return 0;
}
