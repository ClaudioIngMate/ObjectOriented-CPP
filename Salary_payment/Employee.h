//
// Created by Clod on 03/11/2021.
//

#ifndef EMPLOYEE_EMPLOYEE_H
#define EMPLOYEE_EMPLOYEE_H

#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::endl;

class Employee {

protected:
    string name;
    string surname;
    unsigned int employee_ID;
    unsigned int work_hours=0;
    const double pay_rate=7.5;

public:
    // constructor
    Employee(string n, string s, unsigned int id): name(n), surname(s), employee_ID(id) {}
    // I did not put default-initialized attributes in the constructor (this principally for the pay_rate, which is const)
    // moreover, the working hours are set by a specific setter (public method...)

    // print method --> I can provide the implementation also here in the header file
    // moreover, the print is a CONST method since does not modify the attributes of the class
    void print() const {
        cout << name << " " << surname << " " << employee_ID << endl;
    }

    // setter for work hours --> I can provide the implementation also here in the header file
    void set_work_hours (unsigned int hours){
        work_hours=hours;
    }

    // pure virtual function compute_salary (we want to implement Employee as an Abstract class)
    virtual double compute_salary() const =0;

};


#endif //EMPLOYEE_EMPLOYEE_H
