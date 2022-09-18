//
// Created by Clod on 08/12/2021.
//

#ifndef WEDDINGAGENCY_PERSON_H
#define WEDDINGAGENCY_PERSON_H

#include <string>

class Person {

private:
    std::string name;
    unsigned age;
    bool isMale;
public:
    //constructor
    Person(const std::string& n, unsigned a, bool male): name(n), age(a), isMale(male){}
    // Getters
    std::string getName() const { return name;}
    unsigned getAge() const { return age;}
    bool getIsMale() const { return isMale;}

    // print method (always useful for debug...)
    void print() const;
};
// binary operator as helper function
bool operator==(const Person& lhs,const Person& rhs );
bool operator<(const Person& lhs,const Person& rhs);

#endif //WEDDINGAGENCY_PERSON_H
