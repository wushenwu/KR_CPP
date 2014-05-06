#ifndef FLOAT_H_C5D14E4A_C80A_4249_9382_9CB1166EB21F

#define FLOAT_H_C5D14E4A_C80A_4249_9382_9CB1166EB21F

/************************************************************************/
/* 2.дһ���ͻ���Integer��ֻ��һ�������ݣ���һ�ӷ���Ա����Integer* Add(Integer *num)��
Ȼ��д������Floatʹ���һ��Ա������ʾС���������ݡ�
дmain����ʵ��Float�ļӷ����㣬���������(��������Ҫ�ṩ�Լ����������)                                                                     */
/************************************************************************/
#include <iostream>
using namespace std;

class CInterger
{
public:
    CInterger() {}
    CInterger(int ndata) { m_nint = ndata; }

    void SetData(int ndata)
    {
        m_nint = ndata;
    }

    int GetData(void)
    {
        return m_nint;
    }

    CInterger *Add(CInterger *num)
    {
        m_nint += num->m_nint;
        return this;
    }

protected:
    int m_nint;
};

class CFloat: public CInterger
{
public:
    void SetFloat(float fdata);
    void SetFloat(int nint, int ndecimal);

    CInterger GetInt(void) { return CInterger(m_nint); }
    CInterger GetDecimal(void) { return CInterger(m_ndecimal); }

    void PrintData(void (*pfnprint)(int, int));
    static void SetPrecision(int nprecision);   //����С�����ľ���

private:
    int m_ndecimal;
    static int m_nprecision;
};

#endif
