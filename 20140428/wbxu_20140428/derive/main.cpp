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
    publicobj.GetProtectedData();   //������Ի����еĳ�Ա�������󣬿��Է����ˡ�
    //publicobj.GetPrivateData();   
    
    CProtected protectedobj;
    //protectedobj.GetPublicData();   //protected�̳еĳ�Ա����������proteced�ˣ������޷����� 
    //protectedobj.GetProtectedData();
    
    CPrivate privateobj;
    //privateobj.GetPublicData();     //private�̳еĳ�Ա����������private�ˣ������޷�����
    //privateobj.GetProtectedData(); 

}

void
test_hide(void)
{
    CHide hideobj;

    hideobj.SetPublicData(0x1234);  //�����еĳ�Ա������

    hideobj.CBase::SetPublicData(0x5678); //��ʽָ�������򣬵��ø����еĳ�Ա
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