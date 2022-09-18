//
// Created by Clod on 08/12/2021.
//

#include "Person.h"
#include <iostream>

bool operator==(const Person& lhs,const Person& rhs ) {
    if ((lhs.getName() == rhs.getName()) && (lhs.getAge() == rhs.getAge()) && (lhs.getIsMale() == rhs.getIsMale())) {
        return true;
    }
    else {
        return false;
    }
}

bool operator<(const Person& lhs,const Person& rhs){
    return (lhs.getName()<rhs.getName());
}

void Person::print() const{
    std::string sex;
    if(isMale){
        sex="Male";
    }
    else{
        sex="Female";
    }
    std::cout << " Name: " << name << " ; " << " Age: " << age << " ; " << " Gender: " << sex << std::endl;
}