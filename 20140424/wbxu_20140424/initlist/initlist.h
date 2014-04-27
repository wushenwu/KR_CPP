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
        : m_cn2(0)      //�������ݳ�Ա�������ô��ʼ��
                        //��������ݳ�Ա�޲ι���
    { 
        m_n1 = 0; 
    }

    CB(int n1, int nA)
        : m_cn2(2)      //�Գ������ݳ�Ա�ĳ�ʼ��
        //,m_CA(nA)        //����������ݳ�Ա�Ĺ���, 
                          //��ʱ�����������޲ι���
    {
        m_n1 = n1;      //��ͨ���ݳ�Ա�ĳ�ʼ��
        
        m_CA = nA;      //�����ٴν��й���

    }

    CB(int n1, const CA &A)
        : m_cn2(2),
        m_CA(A)         //��������ݳ�Ա�Ŀ�������
    {
        m_n1 = n1;
    }



private:
    int m_n1;
    const int m_cn2;
    CA m_CA;
};

#endif