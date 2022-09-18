//
// Created by Clod on 03/11/2021.
//

#ifndef EMPLOYEE_DEVELOPER_H
#define EMPLOYEE_DEVELOPER_H

#include "Employee.h" // since I want that Developer class inherits from Employee class

class Developer: public Employee{ // I rely on public inheritance

protected: // I define as protected since we will have another class (Manager) that inherits from Developer
    const double wsh_rate=8.0;
    unsigned int wsh_hours=0;

public:

    // constructor --> using delegating constructor mechanism
    Developer(string n, string s, unsigned int id): Employee(n,s,id) {}

    // setter per le workshop hours

    void set_wsh_hours(unsigned int hours){
        wsh_hours=hours;
    }

    //override the compute_salary method
    double compute_salary() const{
        double ret;
        ret=((work_hours-wsh_hours)*pay_rate) +(wsh_hours*wsh_rate);
        return ret;
    }

};

#endif //EMPLOYEE_DEVELOPER_H