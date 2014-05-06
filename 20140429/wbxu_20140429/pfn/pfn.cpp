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
    (*pfnfun)();    //最好统一的使用这种形式
    fun();
}


typedef void (CBase::*PFNSETDATA)(int ndata);   //特定类

//显式的传入对象指针，模拟类成员函数指针
typedef void (__stdcall *PFNTEST)(CBase *pobj, int ndata); 

void
test_pfn(void)
{   
    CBase testobj;
    testobj.test(0x1234);   //可在此处观察test成员函数的地址
                            //此时因_stdcall, this指针也是通过栈进行传递的

    //PFNTEST pfntest = (PFNTEST)0x00401120;  //0x00401120是test成员函数的地址
    PFNTEST pfntest = (PFNTEST)0x00401340;
    pfntest(&testobj, 0x5678);


    PFNSETDATA pfnSetData = CBase::SetData;     //特定类

    //pfnSetData(0x1234); //成员函数指针的调用需要与特定对象结合
    CBase baseobj;
    (baseobj.*pfnSetData)(0x1234);

}

typedef void (CBase::*PFNSETDATAA)(int ndata);
typedef void (CDerive::*PFNSETDATAB)(int ndata);

void
test_convert(void)
{
    //用CDerive的成员函数指针去调用CBase的成员函数，不会有啥问题
    //
    PFNSETDATAB pfnsetdataB = CBase::SetData;
    CDerive deriveobj;
    (deriveobj.*pfnsetdataB)(0x1234);

    //用CBase的成员函数指针去调用CDerive的成员函数，有可能越界访问
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




















