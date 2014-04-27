#include <iostream>
using namespace std;

#include "const.h"

/*
修改为常成员函数之前的测试。
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
修改为常成员函数之后的测试
*/
void
test_const(void)
{
    //普通对象，不受任何对象
    CConst t1;
    t1.SetNum1(1);
    t1.GetNum1();

    const CConst t2;
    t2.GetNum1();       //const对象，访问const成员函数ok
    //t2.SetNum1(2);      //const对象，无法访问非const成员函数

    const CConst t3(3, "hello");
#ifndef CONST
    (t3.GetName())[0] = 'x';     //虽然GetName被处理为常成员函数了，它限制的仅是类内部的对数据成员的修改
                                 //但仍不能阻止外界的更改  

#else
    //(t3.GetName())[0] = 'x';     //用const对返回类型进行限制，可防止对象对数据成员的修改
    

#endif
}

int
main(void)
{
    test_b4();
    
    test_const();

    return 0;
}