/************************************************************************/
/* 1.дһ��Ա����,�����з�нˮ�ķ�����
дһ����Ŀ�����࣬���̳���Ա���ࡣ
дһ������Ա�࣬Ҳ�̳���Ա���ࡣ
��ʵ�ֲ����ֳ����Ƿ�нˮ�Ķ�̬��                                                                     */
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