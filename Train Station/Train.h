//
// Created by Clod on 09/12/2021.
//

#ifndef TRAINS_TRAIN_H
#define TRAINS_TRAIN_H

#include <string>
#include <limits>

class Train {

private:
    static unsigned count; // static attribute, number of trains
    unsigned train_id;
    std::string name;
    unsigned year_production;
    unsigned num_wagons;
    unsigned actual_platform=std::numeric_limits<unsigned>::quiet_NaN();

public:
    // Constructor
    Train(const std::string& n, unsigned yp, unsigned nw);

    // Copy constructor
    Train(const Train& t);

    // Assignment operator
    Train& operator=(const Train& rhs);

    // Static method to get the static counter (Remember : static member functions cannot have a const-qualifier)
    static unsigned get_count(){ return count;}

    // Getters
    unsigned getId() const{ return train_id;}
    std::string getName() const{ return name;}
    unsigned get_platform() const { return actual_platform;}

    // Setters
    void setActualPlatform(unsigned p){ actual_platform=p;}
    void setId(unsigned id){ train_id=id;}

    // print method
    void print() const;

    // Destructor
    //~Train() { count--;}

};

bool operator==(const Train& lhs, const Train& rhs);

#endif //TRAINS_TRAIN_H