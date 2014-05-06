#include "derive.h"

void
test_derive(void)
{
    CBase baseobj;
    
    baseobj.GetPublicData();
    //baseobj.GetProtectedData();
    //baseobj.GetPrivateData();
    
    CPublic publicobj;
    publicobj.GetPublicData();
    publicobj.GetProtectedData();   //派生类对基类中的成员再声明后，可以访问了。
    //publicobj.GetPrivateData();   
    
    CProtected protectedobj;
    //protectedobj.GetPublicData();   //protected继承的成员，都被当作proteced了，类外无法访问 
    //protectedobj.GetProtectedData();
    
    CPrivate privateobj;
    //privateobj.GetPublicData();     //private继承的成员，都被当作private了，类外无法访问
    //privateobj.GetProtectedData(); 

}

void
test_hide(void)
{
    CHide hideobj;

    hideobj.SetPublicData(0x1234);  //父类中的成员被隐藏

    hideobj.CBase::SetPublicData(0x5678); //显式指定作用域，调用父类中的成员
}

void
test_convert(void)
{
    CConvert convertobj;
    CBase *pbaseobj = &convertobj;
    pbaseobj->m_npublicdata = 0x1234;

    CBase baseobj;

    //error C2440: 'initializing' : cannot convert from 'class CBase *' to 'class CConvert *'
    CConvert *pconvertobj = (CConvert *)&baseobj;   
    pconvertobj->CBase::m_npublicdata = 0x1234;
    pconvertobj->m_npublicdata = 0x5678;        

}

void
test_construct(void)
{
    CConvert convertobj;
    convertobj.CBase::m_npublicdata = 0x1234;
    CBase baseobj(convertobj);

    CBase baseobjnew;
    baseobjnew.m_npublicdata = 0x5678;
    CConvert convertobjnew((CConvert &)baseobjnew);

}

int
main(void)
{
    test_derive();

    test_hide();

    test_convert();

    test_construct();

    return 0;
}