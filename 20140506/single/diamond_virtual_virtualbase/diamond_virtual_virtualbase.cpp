/************************************************************************/
/* 对菱形继承, 有虚函数, 为虚继承的内存空间布局的测试                                                                     */
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

class B: virtual public A
{
public:
    B() { m_nDataB = 0xB; }
    virtual ~B() {}

    virtual void fun1(void) {}
    virtual void fun3(void) {}
    
protected:
    int m_nDataB;
};

class C: virtual public A
{
public:
    C() { m_nDataC = 0xC; }
    virtual ~C() {}

    virtual void fun1(void) {}
    virtual void fun4(void) {}
    
protected:
    int m_nDataC;
};

class D: public B, public C
{
public:
    D() { m_nDataD = 0xD; }
    virtual ~D() {}
    
    virtual void fun1(void) {}
    virtual void fun5(void) {}
protected:
    int m_nDataD;
};

int main(void)
{
    D theD;
    
    cout << sizeof(theD) << endl;
    
    return 0;
}