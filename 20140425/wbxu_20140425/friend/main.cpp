#include <iostream>
using namespace std;

#include "friend.h"

void normal_func(void)
{
    CStudent test(0x1234, "hello");

    //该函数已被声明为CStudent的友元函数，所以可以访问其私有成员（包括数据成员和成员函数）
    test.m_no = 0x5678;

    test.init(0);

}

/*
 对普通友元函数的测试
*/
void
test_normal(void)
{
    normal_func();
}

/*
对友元类成员函数的测试
*/
void
test_member(void)
{
    COther other;
    other.func();
}

/*
    利用友元成员函数，将对象限定只能产生在堆上。
    对其进行测试
*/
void
test_heapobject(void)
{
    //CStudent stud;  //error C2248: 'CStudent::CStudent' : 
                    //cannot access private member declared in class 'CStudent'
    CStudent *pstud = COther().CreateObject();
    pstud->SetName("hello world");

    //pstud->~CStudent();     //应该显式的进行资源的释放
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