#ifndef CITIZENSTOO_H_INCLUDED
#define CITIZENSTOO_H_INCLUDED

#include <iostream>
#include <string>
using namespace std;

class Citizen {
public:
    static const int DRINKING_AGE = 21;

    //Constructors
    Citizen();
    Citizen(string & nam, int ag);

    //Setters
    void setName(string & nam);
    void setAge(int ag);

    //Getters
    string getName() const;
    int getAge() const;

    //Others
    bool canDrink() const;

private:
    string name;
    int age;
};


#endif // CITIZENSTOO_H_INCLUDED
