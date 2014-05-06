/************************************************************************/
/* 2.��Ϊ�������ƶ��ýӿڣ�
ʹ�������Լ��ݷ��ϴ˱�׼�ӿڵ��������������Կ���
(������ʵ�֣���Ӧ�Ľӿڼ�Ϊ����ͳһ��׼��Ϊͳһ����)��                                                                     */
/************************************************************************/
#ifndef INTERFACE_H_7A307CD5_EB12_4e75_B6E8_957A581DA6F3

#define INTERFACE_H_7A307CD5_EB12_4e75_B6E8_957A581DA6F3

#include <iostream>
using namespace std;

class CUSBInterface
{
public:
    virtual void access(void)
    {
        cout << "accessing USB Interface" << endl;
    }
};

class CAudioCardInterface: public CUSBInterface
{
public:
    void access(void)
    {
        cout << "accessing AudioCard Interface" << endl;
    }
};

class CNetCardInterface: public CUSBInterface
{
public:
    void access(void)
    {
        cout << "accessing NetCard Interface" << endl;
    }
};

class CGraphCardInterface: public CUSBInterface
{
public:
    void access(void)
    {
        cout << "accessing GraphCard Interface" << endl;
    }
};

class CMainBoard
{
public:
    CMainBoard() { m_pUSBobj = new CUSBInterface; }

    ~CMainBoard() 
    {
        if (m_pUSBobj != NULL)
        {
            delete m_pUSBobj;
            m_pUSBobj = NULL;
        }
    }

    void Plug(CUSBInterface *pobj) { m_pUSBobj = pobj; }

    void Play(void)
    {
        m_pUSBobj->access();
    }

private:
    CUSBInterface *m_pUSBobj;
};

#endif
