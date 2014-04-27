#include <iostream>
using namespace std;

#include "student.h"

void
test_var(void)
{
    //说明一个变量并初始化有两种形式
    int m = 10;
    int n(20);  //<=> int n = 20;

    //赋值时，只有一种方法
    m = 10;
    //n(20);  //不是赋值，而是调用名为n的函数
}

void 
copy1(CStudent stu)
{
    stu.SetNo(1);
}

CStudent 
copy2()
{
    CStudent tmp(2);    //构造
    return tmp;         //拷贝构造，析构
}

void 
copy3(CStudent *pstu)
{
    pstu->SetNo(3);
}

void 
copy4(CStudent &stu)
{
    stu.SetNo(4);
}

void 
copy5(const CStudent &stu)
{
    cout << stu.GetName() << endl;
}

void
test_copyconstruction(void)
{
    CStudent stu1(110, "hello");

    CStudent stu2 = stu1;       //拷贝构造函数
    cout << stu2.GetName() << endl;

    CStudent stu3(stu1);        //拷贝构造
    cout << stu3.GetName() << endl;

    copy1(stu3);                //函数参数，先拷贝，入栈传参，再调用函数

    copy1(0);                   //先尝试构造，入栈传参，再调用函数
    
    copy2();                    //临时结果未保存

    CStudent tmp = copy2();     //有优化环节

    copy3(&stu1);               //直接调用函数

    copy4(stu1);                //直接调用

    const CStudent stu5(5, "555");
    copy5(stu5);                //直接
}

int
main(void)
{
    test_var();

    test_copyconstruction();

    return 0;
}