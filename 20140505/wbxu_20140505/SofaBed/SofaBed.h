#ifndef SOFABED_H_04AFDB4A_7509_4a53_9C97_2FA3CA19C04D

#define SOFABED_H_04AFDB4A_7509_4a53_9C97_2FA3CA19C04D

/************************************************************************/
/* 
1.床类bed,沙发类sofa提供坐sit()方法,沙发床sofabed提供躺lie()方法，sofabed是多重继承bed和sofa的。
(1)实现上述多重继承的设计
(2)写出一个可以避免使用多重继承的设计。                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

class CSofa
{
public:
    CSofa()
    {
        cout << "CSofa::CSofa()" << endl;
    }

    virtual ~CSofa()
    {
        cout << "CSofa::~CSofa()" << endl;
    }

    void Sit(void)
    {
        cout << "CSofa::Sit" << endl;
    }

};

class CBed
{
public:
    CBed()
    {
        cout << "CBed::CBed()" << endl;
    }
    
    virtual ~CBed()
    {
        cout << "CBed::~CBed()" << endl;
    }
    
    void Sit(void)
    {
        cout << "CBed::Sit" << endl;
    }
    
};

class CSofaBed: public CBed, public CSofa
{
public:
    CSofaBed()
    {
        cout << "CSofaBed::CSofaBed()" << endl;
    }

    virtual ~CSofaBed()
    {
        cout << "CSofaBed::~CSofaBed()" << endl;
    }

    void Lie(void)
    {
        cout << "CSofaBed::Lie" << endl;
    }
};

//避免使用多重继承
class CSofaBed_NON
{
public:
    CSofaBed_NON()
    {
        cout << "CSofaBed_NON::CSofaBed_NON()" << endl;
    }

    virtual ~CSofaBed_NON()
    {
        cout << "CSofaBed_NON::~CSofaBed_NON()" << endl; 
    }

    void Lie(void)
    {
        cout << "CSofaBed::Lie" << endl;
    }

public:
    CBed m_bedobj;
    CSofa m_sofaobj;

};

#endif
