/************************************************************************/
/* 1.写一个员工类,其中有发薪水的方法。
写一个项目经理类，他继承自员工类。
写一个程序员类，也继承自员工类。
请实现并表现出他们发薪水的多态性                                                                     */
/************************************************************************/

#include "employee.h"

int
main(void)
{
    CEmployee *pobj = NULL;
    int nselect = 0;

    cin >> nselect;

    switch (nselect)
    {
    case 0:
        {
            pobj = new CEmployee;
            break;
        }

    case 1:
        {
            pobj = new CManager;
            break;
        }

    case 2:
        {
            pobj = new CProgrammer;
            break;
        }
    }

    if (pobj != NULL)
    {
        pobj->PaySalary();
        delete pobj;
    }

    return 0;
}