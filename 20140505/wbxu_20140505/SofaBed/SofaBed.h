#ifndef SOFABED_H_04AFDB4A_7509_4a53_9C97_2FA3CA19C04D

#define SOFABED_H_04AFDB4A_7509_4a53_9C97_2FA3CA19C04D

/************************************************************************/
/* 
1.����bed,ɳ����sofa�ṩ��sit()����,ɳ����sofabed�ṩ��lie()������sofabed�Ƕ��ؼ̳�bed��sofa�ġ�
(1)ʵ���������ؼ̳е����
(2)д��һ�����Ա���ʹ�ö��ؼ̳е���ơ�                                                                     */
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

//����ʹ�ö��ؼ̳�
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
