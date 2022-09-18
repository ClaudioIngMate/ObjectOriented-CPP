// Implement a program to manage the procedure of salary payment

#include "Employee.h" // father class (for Secretary and Developer)

#include "Secretary.h" // child class (--> inherits from Employee)
#include "Developer.h" // child class (--> inherits from Employee) and father class for Manager
#include "Manager.h" // child class --> inherits from Developer

int main ()
{
    Secretary S("Anna","Rossi",1);
    Developer D("Mauro","Neri",2);
    Manager M("Gaia","Bruni",3);
    
    std::cout << "Secretary:" << std::endl;
    S.print();
    S.set_work_hours(10);
    double Ssalary = S.compute_salary();
    std::cout << Ssalary << std::endl;
    
    std::cout << "Developer:" << std::endl;
    D.print();
    D.set_work_hours(10);
    D.set_wsh_hours(5);
    double Dsalary = D.compute_salary();
    std::cout << Dsalary << std::endl;
    
    std::cout << "Manager:" << std::endl;
    M.print();
    M.set_work_hours(10);
    M.set_wsh_hours(2);
    M.set_m_hours(3);
    double Msalary = M.compute_salary();
    std::cout << Msalary << std::endl;
    
    return 0;
}