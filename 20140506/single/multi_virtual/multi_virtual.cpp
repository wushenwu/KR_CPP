/************************************************************************/
/* 对多重继承, 有虚函数的内存空间布局的测试                                                                     */
/************************************************************************/
#include <iostream>
using namespace std;

class A
{
public:
    A() { m_nDataA = 0xA; }
    
    virtual ~A() {}

    virtual void fun1(void) {}
    virtual void fun2(void) {}
    
protected:
    int m_nDataA;
    
};

class B
{
public:
    B() { m_nDataB = 0xB; }
    virtual ~B() {}

    virtual void fun1(void) {}
    virtual void fun3(void) {}
    
protected:
    int m_nDataB;
};

class C: public A, public B
{
public:
    C() { m_nDataC = 0xC; }
    virtual ~C() {}

    virtual void fun1(void) {}
    virtual void fun4(void) {}
    
protected:
    int m_nDataC;
};

int main(void)
{
    C theC;
    
    cout << sizeof(theC) << endl;
    
    return 0;
}