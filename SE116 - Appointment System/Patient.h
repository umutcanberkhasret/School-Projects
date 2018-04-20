#ifndef PATIENT_H
#define PATIENT_H

#include<iostream>
#include"Person.h"

using namespace std;

class Patient: public Person
{
    private:
            int age;
            string illness;
            string ID;
    public:
            Patient(void);
            Patient(int age,string illness,string ID);
            ~Patient(void);
            void setAge(int age);
            int getAge(void) const;
            void setIllness(string illness);
            string getIllness(void) const;
            void setID(string ID);
            string getID(void) const;
            void Infos(void);










};
#endif
