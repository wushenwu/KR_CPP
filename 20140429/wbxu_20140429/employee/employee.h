/************************************************************************/
/* 1.写一个员工类,其中有发薪水的方法。
写一个项目经理类，他继承自员工类。
写一个程序员类，也继承自员工类。
请实现并表现出他们发薪水的多态性                                                                     */
/************************************************************************/

#ifndef EMPLOYEE_H_7A33DBB2_1961_43b0_B125_46D718002D4B

#define EMPLOYEE_H_7A33DBB2_1961_43b0_B125_46D718002D4B

#include <iostream>
using namespace std;

class CEmployee
{
public:
    virtual ~CEmployee() {}
    virtual void PaySalary(void) { cout << "Employee paysalary" << endl; }
    
};

class CManager: public CEmployee
{
public:
    void PaySalary(void) { cout << "Manager paysalary" << endl; }
};

class CProgrammer: public CEmployee
{
public:
    void PaySalary(void) { cout << "Programmer paysalary" << endl; }
};

#endif