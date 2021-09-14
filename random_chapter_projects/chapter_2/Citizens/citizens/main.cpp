// Citizen.cpp - wdg - 2016
#include <iostream>
#include <string>
using namespace std;

class Citizen {
public:
    //constructors
    Citizen( ){
      name = "UNKNOWN";
      age = 0;
    }

    Citizen(string nam, int ag){
      name = nam;
      age = ag;
    }

    //setters
    void setName(string nam){
      name = nam;
    }

    void setAge(int ag){
      age = ag;
    }

    //getters
    string getName( ){
      return name;
    }

    int getAge( ){
      return age;
    }

    bool canDrink( ){
      return (age >= 21);
    }

  private:
    string name;
    int age;
};


int main( ) {

  Citizen one;

  one.setName("GI Joe");
  one.setAge(50);

  Citizen two("Barbie",13);

    cout << one.getName();

        if ( one.canDrink() )
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
