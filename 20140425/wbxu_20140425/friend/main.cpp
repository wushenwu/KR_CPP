#include <iostream>
using namespace std;

#include "friend.h"

void normal_func(void)
{
    CStudent test(0x1234, "hello");

    //�ú����ѱ�����ΪCStudent����Ԫ���������Կ��Է�����˽�г�Ա���������ݳ�Ա�ͳ�Ա������
    test.m_no = 0x5678;

    test.init(0);

}

/*
 ����ͨ��Ԫ�����Ĳ���
*/
void
test_normal(void)
{
    normal_func();
}

/*
����Ԫ���Ա�����Ĳ���
*/
void
test_member(void)
{
    COther other;
    other.func();
}

/*
    ������Ԫ��Ա�������������޶�ֻ�ܲ����ڶ��ϡ�
    ������в���
*/
void
test_heapobject(void)
{
    //CStudent stud;  //error C2248: 'CStudent::CStudent' : 
                    //cannot access private member declared in class 'CStudent'
    CStudent *pstud = COther().CreateObject();
    pstud->SetName("hello world");

    //pstud->~CStudent();     //Ӧ����ʽ�Ľ�����Դ���ͷ�
    pstud->KillMe();

}

int
main(void)
{
    test_normal();

    test_member();

    test_heapobject();

    return 0;
}