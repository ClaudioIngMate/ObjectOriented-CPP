//
// Created by Clod on 03/11/2021.
//

#ifndef EMPLOYEE_SECRETARY_H
#define EMPLOYEE_SECRETARY_H

#include "Employee.h" // since we want that the class 'Secretary' inherits from the class 'Employee'


class Secretary: public Employee { // we rely on public inheritance

// no other attributes needed for this class

public:
    // CONSTRUCTOR --> I define it relying on delegating constructor
    Secretary(string n, string s, unsigned int id): Employee(n,s,id ) {};

    // override the public method compute_salary --> I can implement it also here in the Header file!!!
    double compute_salary() const override{
        double ret;
        ret=work_hours*pay_rate;
        return ret;
    }

};


#endif //EMPLOYEE_SECRETARY_H
