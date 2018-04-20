#ifndef DOCTOR_H
#define DOCTOR_H

#include<iostream>
#include"Person.h"

using namespace std;

class Doctor : public Person
{
private:
    string speciality;
    int specialityCode;
public:
    Doctor(void);
    Doctor(string speciality);
    ~Doctor(void);
    void setSpeciality(string speciality);
    string getSpeciality(void) const;
    void Infos(void);

};

#endif
