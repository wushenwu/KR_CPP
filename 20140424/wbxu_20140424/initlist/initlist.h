#ifndef INITLIST_H_4A780EAA_7FEE_4877_A375_2187CB99F152

#define INITLIST_H_4A780EAA_7FEE_4877_A375_2187CB99F152

class CA
{
public:
    CA()    { m_n1 = 0; }
    CA(int n1) { m_n1 = n1; }

private:
    int m_n1;
};

class CB
{
public:
    CB()
        : m_cn2(0)      //常量数据成员必须得这么初始化
                        //类对象数据成员无参构造
    { 
        m_n1 = 0; 
    }

    CB(int n1, int nA)
        : m_cn2(2)      //对常量数据成员的初始化
        //,m_CA(nA)        //对类对象数据成员的构造, 
                          //此时类对象进行了无参构造
    {
        m_n1 = n1;      //普通数据成员的初始化
        
        m_CA = nA;      //这里再次进行构造

    }

    CB(int n1, const CA &A)
        : m_cn2(2),
        m_CA(A)         //类对象数据成员的拷贝构造
    {
        m_n1 = n1;
    }



private:
    int m_n1;
    const int m_cn2;
    CA m_CA;
};

#endif