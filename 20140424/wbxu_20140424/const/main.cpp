#include <iostream>
using namespace std;

#include "const.h"

/*
�޸�Ϊ����Ա����֮ǰ�Ĳ��ԡ�
*/
void
test_b4(void)
{
    CConst t1;
    t1.SetNum1(1);
    
    const CConst t2;
    //t2.SetNum1(2);
    cout << t2.m_n2 << endl;
    //t2.m_n2 = 1;
    //char ch = t2;
}

/*
�޸�Ϊ����Ա����֮��Ĳ���
*/
void
test_const(void)
{
    //��ͨ���󣬲����κζ���
    CConst t1;
    t1.SetNum1(1);
    t1.GetNum1();

    const CConst t2;
    t2.GetNum1();       //const���󣬷���const��Ա����ok
    //t2.SetNum1(2);      //const�����޷����ʷ�const��Ա����

    const CConst t3(3, "hello");
#ifndef CONST
    (t3.GetName())[0] = 'x';     //��ȻGetName������Ϊ����Ա�����ˣ������ƵĽ������ڲ��Ķ����ݳ�Ա���޸�
                                 //���Բ�����ֹ���ĸ���  

#else
    //(t3.GetName())[0] = 'x';     //��const�Է������ͽ������ƣ��ɷ�ֹ��������ݳ�Ա���޸�
    

#endif
}

int
main(void)
{
    test_b4();
    
    test_const();

    return 0;
}