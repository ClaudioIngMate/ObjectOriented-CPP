//
// Created by Clod on 09/12/2021.
//

#include "Train.h"
#include <iostream>

unsigned Train::count=0; // initialization of the static variable

// Constructor (with incrementation of the counter)

Train::Train(const std::string& n, unsigned yp, unsigned nw):
name(n), year_production(yp), num_wagons(nw) {
    count++;
    train_id=count;
}

// Copy constructor (with the incrementation of the counter)

Train::Train(const Train& t): name(t.name), year_production(t.year_production), num_wagons(t.num_wagons) {
    //count++;
    //train_id=count; -->When I create some copies.... I do not want to create new objects... --> so
    train_id=t.train_id;
    actual_platform=t.actual_platform;
}

// Assignment operator

Train& Train::operator=(const Train& rhs){
    name=rhs.name;
    year_production=rhs.year_production;
    num_wagons=rhs.num_wagons;
    return *this;
}

// == operator

bool operator==(const Train& lhs, const Train& rhs){
    return (lhs.getName()==rhs.getName());
}

// print method
void Train::print() const{
    std::cout << "    * Train ID: " << train_id << " , Name: " << name << std::endl;
}