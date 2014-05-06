/************************************************************************/
/* 5.写一个person类有名字属性，其中名字是在堆里申请的。
其有一子类是作家类，作家类里除了名字外还有一个笔名,也是在堆里申请的。
都有sayName方法。请实现这两个类的多态性。(提示：注意析构函数)                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include "writer.h"

/*
对各类构造的测试
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

