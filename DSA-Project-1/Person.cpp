//
// Created by Youssif Al-Nashif on 1/17/19.
//

#include "Person.h"

using namespace std;


const string Person::getName()  {
    return name;
}

void Person::setName(const string name) {
    Person::name = name;
}

uint32_t Person::getAge()  {
    return age;
}

void Person::setAge(uint32_t age) {
    Person::age = age;
}

Person::Person() {

}

Person::Person(string namePar, uint32_t agePar) {
    name=namePar;
    age=agePar;
}

ostream& operator<<(ostream& os, const Person &p)
{
    os << "Name: " << p.name << "\n Age: " << p.age <<endl;
    return os;
}