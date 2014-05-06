/************************************************************************/
/* 对多重继承，无虚函数的内存布局的测试                                                                     */
/************************************************************************/
#include <iostream>
using namespace std;

class A
{
public:
    A() { m_nDataA = 0xA; }
    
    ~A() {}
    
protected:
    int m_nDataA;
    
};

class B
{
public:
    B() { m_nDataB = 0xB; }
    ~B() {}
    
protected:
    int m_nDataB;
};

class C: public A, public B
{
public:
    C() { m_nDataC = 0xC; }
    ~C() {}

protected:
    int m_nDataC;
};

int main(void)
{
    C theC;
    
    cout << sizeof(theC) << endl;
    
    return 0;
}