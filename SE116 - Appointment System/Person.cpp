#include <iostream>
#include "Person.h"

using namespace std;

void Person::setName(string name)
{
    this->name=name;
}

void Person::setSurname(string surname)
{
    this->surname=surname;
}

void Person::setTelephone(string telephone)
{
    this->telephone=telephone;
}

void Person::setDate(string date)
{
    this->date=date;
}

string Person::getName() const
{
    return name;
}

string Person::getSurname() const
{
    return surname;
}

string Person::getTelephone() const
{
    return telephone;
}

string Person::getDate() const
{
    return date;
}

Person::Person(void)
{
  name="NotDefined";
  surname="NotDefined";
  telephone="NotDefined";
  date="Unknown";
}

Person::Person(string name,string surname,string telephone,string date)
{
    setName(name);
    setSurname(surname);
    setTelephone(telephone);
    setDate(date);
}

Person::~Person(void)
{

}

 void Person::Infos(void)
 {

 }
