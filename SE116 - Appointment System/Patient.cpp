#include <iostream>
#include "Patient.h"

Patient::Patient() : Person()
{
    age=0;
    illness="Unknown";
    ID="Unknown";
}

Patient::Patient(int age,string illness,string ID) : Person(getName(),getSurname(),getTelephone(),getDate())
{
    setAge(age);
    setIllness(illness);
    setID(ID);
}

Patient::~Patient()
{

}

void Patient::setAge(int age)
{
    this->age=age;
}

int Patient::getAge(void) const
{
    return age;
}

void Patient::setIllness(string illness)
{
    this->illness=illness;
}

string Patient::getIllness(void) const
{
    return illness;
}

void Patient::setID(string ID)
{
    this->ID=ID;
}

string Patient::getID(void) const
{
    return ID;
}
void Patient::Infos(void)
 {
    cout<<endl<<endl;
    cout<<"--PATIENT'S INFORMATIONS--"<<endl;
    cout<<"Patient's ID              : "<<getID()<< endl;
    cout<<"Patient's Name            : "<<getName()<< endl;
    cout<<"Patient's Surname         : "<<getSurname()<<endl;
    cout<<"Patient's Age             : "<<getAge()<< endl;
    cout<<"Patient's Telephone Number: "<<getTelephone()<< endl;
    cout<<"Patient's Illness Type    : "<<getIllness()<< endl;
 }

