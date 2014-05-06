/************************************************************************/
/* 5.дһ��person�����������ԣ������������ڶ�������ġ�
����һ�����������࣬����������������⻹��һ������,Ҳ���ڶ�������ġ�
����sayName��������ʵ����������Ķ�̬�ԡ�(��ʾ��ע����������)                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include "writer.h"

/*
�Ը��๹��Ĳ���
*/
void
test_basic(void)
{
    CPerson personobj("Hello");
    personobj.SayName();

    CPerson personobjnew(personobj);
    personobjnew.SayName();

    CWriter writerobj("world");
    writerobj.SayName();

    CWriter writerobjnew("world", "Just4Fun");
    writerobjnew.SayName();

    CWriter obj(writerobjnew);
    obj.SayName();
}

void
test_sayname(CPerson *pobj)
{
    pobj->SayName();
}

void
test_poly(void)
{
    CPerson *pobj = NULL;

    pobj = new CPerson("Hello");
    test_sayname(pobj);

    pobj = new CWriter("World", "Just4Fun");
    test_sayname(pobj);

    if (pobj != NULL)
    {
        delete pobj;
        pobj = NULL;
    }
}

int
main(void)
{
    test_basic();

    test_poly();

    return 0;
}

