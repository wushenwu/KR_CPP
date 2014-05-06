/************************************************************************/
/* 对单继承，有虚函数的内存布局测试                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

class A
{
public:
    A() { m_nDataA = 1; }
    
    virtual ~A() {}

    virtual void fun1(void) {}
    
protected:
    int m_nDataA;
    
};

class B: public A
{
public:
    B() { m_nDataB = 2; }
    virtual ~B() {}

    virtual void fun1(void) {}
    virtual void fun2(void) {}
    
protected:
    int m_nDataB;
};

int main(void)
{
    B theB;
    
    cout << sizeof(theB) << endl;
    
    return 0;
}