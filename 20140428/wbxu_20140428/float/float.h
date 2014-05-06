#ifndef FLOAT_H_C5D14E4A_C80A_4249_9382_9CB1166EB21F

#define FLOAT_H_C5D14E4A_C80A_4249_9382_9CB1166EB21F

/************************************************************************/
/* 2.写一整型基类Integer里只含一整型数据，和一加法成员方法Integer* Add(Integer *num)，
然后写其子类Float使其多一成员即来表示小数点后的数据。
写main函数实现Float的加法运算，并举例输出(其中类里要提供自己的输出方法)                                                                     */
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
    static void SetPrecision(int nprecision);   //设置小数点后的精度

private:
    int m_ndecimal;
    static int m_nprecision;
};

#endif
