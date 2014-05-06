#include "Uninheritable.h"

void 
test_method1(void)
{
    CBase *pbase = CBase::CreateObject();
    pbase->Destory();
}

void
test_method2(void)
{
    C theC;     //error C2248: 'A::A' : cannot access private member declared in class 'A'
}

int
main(void)
{
    test_method1();

    test_method2();

    return 0;
} 