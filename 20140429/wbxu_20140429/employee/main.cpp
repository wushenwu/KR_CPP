/************************************************************************/
/* 1.дһ��Ա����,�����з�нˮ�ķ�����
дһ����Ŀ�����࣬���̳���Ա���ࡣ
дһ������Ա�࣬Ҳ�̳���Ա���ࡣ
��ʵ�ֲ����ֳ����Ƿ�нˮ�Ķ�̬��                                                                     */
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