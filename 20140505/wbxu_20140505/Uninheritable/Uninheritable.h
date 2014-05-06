/************************************************************************/
/* 2.��дһ���಻�ܱ��̳�                                                                     */
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

class B: virtual public A   //����A������࣬�������Ҫ���ȹ���ġ�
{                           //A�Ĺ��챻��Ϊprivate������һ��Ĳ��ܱ�����
                            //������B������ΪA����Ԫ������B���Է���A��B���Ա������Ĺ���
public:
    B() {}
};

class C:public B        //����C��̳�B����Ҫ�ȹ��������A��Ȼ��A�Ĺ��챻˽�У����Ի��޷��ɹ�
{

};