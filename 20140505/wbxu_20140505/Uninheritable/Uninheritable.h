/************************************************************************/
/* 2.编写一个类不能被继承                                                                     */
/************************************************************************/

#ifndef UNINHERITABLE_H_9E173822_35C2_4238_B3DA_EBA44892DBFE

#define UNINHERITABLE_H_9E173822_35C2_4238_B3DA_EBA44892DBFE

#include <iostream>
using namespace std;

class CBase_B4
{
public:
    CBase_B4()
    {
        cout << "CBase_B4::CBase_B4" << endl;
    }

    ~CBase_B4()
    {
        cout << "CBase_B4::~CBase_B4" << endl;
    }
};

class CBase: public CBase_B4
{
public:
    static CBase *CreateObject(void)
    {
        return new CBase;
    }

    void Destory(void)
    {
        delete this;
    }

private:
    CBase()
    {
        cout << "CBase::CBase()" << endl;
    }

    virtual ~CBase()
    {
        cout << "CBase::~CBase()" << endl;
    }

};

#if 0
class CDerive: public CBase     //error C2248: 'CBase::CBase' : cannot access private member declared in class 'CBase'
{
public:
    CDerive()
    {
        cout << "CDerive::CDerive()" << endl;
    }

    virtual ~CDerive()
    {
        cout << "CDerive::~CDerive()" << endl;
    }
};
#endif
#endif

//////////////////////////////////////////////////////////////////////////
//Method 2 by zhuyuheng
//////////////////////////////////////////////////////////////////////////
class A
{
    friend class B;
private:
    A() {}

};

class B: virtual public A   //现在A是虚基类，虚基类是要首先构造的。
{                           //A的构造被设为private，所以一般的不能被访问
                            //但现在B被声明为A的友元，所以B可以访问A，B可以被正常的构造
public:
    B() {}
};

class C:public B        //现在C想继承B，则要先构造虚基类A，然而A的构造被私有，所以会无法成功
{

};