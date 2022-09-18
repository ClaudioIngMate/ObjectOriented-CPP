//
// Created by Clod on 03/11/2021.
//

#ifndef EMPLOYEE_MANAGER_H
#define EMPLOYEE_MANAGER_H

#include "Developer.h" // the manager class inherits from the Developer class

class Manager: public Developer { // we rely on public inheritance

private:
    unsigned int m_hours=0;
    const double m_rate =8.5;

public:
    // constructor --> implemented with delegating constructor mechanism
    Manager(string n, string s, unsigned int id): Developer(n,s,id) {}

    // setter for the mission hours
    void set_m_hours(unsigned int hours){
        m_hours=hours;
    }

    // override the public method to compute the salary

    double compute_salary() const override{
        double ret;
        ret=(work_hours-m_hours-wsh_hours)*pay_rate+ m_hours*m_rate+ wsh_hours*wsh_rate;
        return ret;
    }

};

#endif //EMPLOYEE_MANAGER_H
