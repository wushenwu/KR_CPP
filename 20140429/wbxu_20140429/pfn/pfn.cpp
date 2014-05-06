#include <iostream>
using namespace std;

class CBase
{
public:
    void SetData(int ndata) { m_ndata = ndata; }
    void __stdcall test(int ndata) { m_ndata = ndata; }

protected:
    int m_ndata;
};

class CDerive: public CBase
{
public:
    void SetData(int ndata) { m_ndatanew = ndata; }

private:
    int m_ndatanew;
};

void
fun(void)
{
    cout << "fun called" << endl;
}

typedef void (*PFNFUN)(void);

void
test_normal(void)
{
    PFNFUN pfnfun = fun;

    pfnfun();
    (*pfnfun)();    //���ͳһ��ʹ��������ʽ
    fun();
}


typedef void (CBase::*PFNSETDATA)(int ndata);   //�ض���

//��ʽ�Ĵ������ָ�룬ģ�����Ա����ָ��
typedef void (__stdcall *PFNTEST)(CBase *pobj, int ndata); 

void
test_pfn(void)
{   
    CBase testobj;
    testobj.test(0x1234);   //���ڴ˴��۲�test��Ա�����ĵ�ַ
                            //��ʱ��_stdcall, thisָ��Ҳ��ͨ��ջ���д��ݵ�

    //PFNTEST pfntest = (PFNTEST)0x00401120;  //0x00401120��test��Ա�����ĵ�ַ
    PFNTEST pfntest = (PFNTEST)0x00401340;
    pfntest(&testobj, 0x5678);


    PFNSETDATA pfnSetData = CBase::SetData;     //�ض���

    //pfnSetData(0x1234); //��Ա����ָ��ĵ�����Ҫ���ض�������
    CBase baseobj;
    (baseobj.*pfnSetData)(0x1234);

}

typedef void (CBase::*PFNSETDATAA)(int ndata);
typedef void (CDerive::*PFNSETDATAB)(int ndata);

void
test_convert(void)
{
    //��CDerive�ĳ�Ա����ָ��ȥ����CBase�ĳ�Ա������������ɶ����
    //
    PFNSETDATAB pfnsetdataB = CBase::SetData;
    CDerive deriveobj;
    (deriveobj.*pfnsetdataB)(0x1234);

    //��CBase�ĳ�Ա����ָ��ȥ����CDerive�ĳ�Ա�������п���Խ�����
    //cannot convert from 'void (__thiscall CDerive::*)(int)' to 'void (__thiscall CBase::*)(int)'
    PFNSETDATAA pfnsetdataA = (PFNSETDATAA)CDerive::SetData;
    CBase baseobj;
    (baseobj.*pfnsetdataA)(0x5678);

}

int
main(void)
{
    test_normal();

    test_pfn();

    test_convert();

    return 0;
}




















