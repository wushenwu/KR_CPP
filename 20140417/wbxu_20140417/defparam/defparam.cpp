/************************************************************************/
/* 1.����Ĭ�ϲ�������ɺ�����Բ�����������Ĭ��Ϊ0.0f��pi����Ϊ����                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#define  PI  3.14f

float
circle(float r = 0.0f)
{
    return r * r * (PI);
}

int
main(void)
{
    float r = 2.0f;

    cout << circle() << endl;
    cout << circle(r) << endl;

    return 0;
}