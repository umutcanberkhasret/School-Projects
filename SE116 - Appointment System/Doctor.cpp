#include<iostream>
#include"Doctor.h"
#include"Person.h"

Doctor::Doctor() : Person()
{
    speciality="Unknown";
    specialityCode=0;
}

Doctor::Doctor(string speciality) : Person(getName(),getSurname(),getTelephone(),getDate())
{
    setSpeciality(speciality);
}

Doctor::~Doctor()
{

}

void Doctor::setSpeciality(string speciality)
{
    this->speciality=speciality;
}

string Doctor::getSpeciality(void) const
{
    return speciality;
}

void Doctor::Infos(void)
 {
    cout<<endl<<endl;
    cout<<"--DOCTOR'S INFORMATIONS--"<<endl;
    cout<<"Doctor's Name            : "<<getName()<<endl;
    cout<<"Doctor's Surname         : "<<getSurname()<<endl;
    cout<<"Doctor's Speciality      : "<<getSpeciality()<<endl;
    cout<<"The Appointment Hour     : "<<getDate()<<endl;
 }
