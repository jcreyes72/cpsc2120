// CitizenToo.cpp - wdg - 2016
#include <iostream>
#include <string>
using namespace std;
#include "citizenstoo.h"


//CONSTRUCTORS--------------------------------------------------

Citizen::Citizen() : name("UNKNOWN"), age(0){}

Citizen::Citizen(string & nam, int ag) : name(nam), age(ag){}

//--------------------------------------------------------------


//SETTERS-------------------------------------------------------

void Citizen::setName(string & nam){
    name = nam;
}

void Citizen::setAge(int ag){
    age = ag;
}

//--------------------------------------------------------------


//GETTERS-------------------------------------------------------

string Citizen::getName() const {
    return name;
}

int Citizen::getAge() const {
    return age;
}

//--------------------------------------------------------------


//OTHERS--------------------------------------------------------

bool Citizen::canDrink() const {
    return (age >= DRINKING_AGE);
}

//--------------------------------------------------------------
