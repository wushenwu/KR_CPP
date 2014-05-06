/************************************************************************/
/* �����μ̳�, ���麯��, Ϊ��̳е��ڴ�ռ䲼�ֵĲ���                                                                     */
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

class B: virtual public A
{
public:
    B() { m_nDataB = 0xB; }
    ~B() {}
    
protected:
    int m_nDataB;
};

class C: virtual public A
{
public:
    C() { m_nDataC = 0xC; }
    ~C() {}
    
protected:
    int m_nDataC;
};

class D: public B, public C
{
public:
    D() { m_nDataD = 0xD; }
    ~D() {}
    
protected:
    int m_nDataD;
};

int main(void)
{
    D theD;
    
    cout << sizeof(theD) << endl;
    
    return 0;
}