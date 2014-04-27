#include <iostream>
using namespace std;

#include "student.h"

void
test_var(void)
{
    //声明一个变量并初始化有两种形式
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
#if 0
    CStudent tmp(2);    //构造
    return tmp;         //拷贝构造，将本栈内的临时变量tmp拷贝至其调用函数栈中，然后自身析构
#endif

    return CStudent(2); //构造，直接操作调用函数栈空间，未析构，需调用函数析构
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
    cout << stu.GetName() << endl;
}

void 
copy5(const CStudent &stu)
{
    //cout << stu.GetName() << endl;  //error C2662: 'GetName' : cannot convert 'this' pointer from 'const class CStudent' to 'class CStudent &'
    //常对象仅能访问常成员函数
}

void
test_copyconstruction(void)
{
    CStudent stu1(110, "hello");    

    CStudent stu2 = stu1;       //拷贝构造函数
    cout << stu2.GetName() << endl;

    //stu2 = stu1;            // 浅拷贝, 会导致析构出错

    CStudent stu3(stu1);        //拷贝构造
    cout << stu3.GetName() << endl;

    //copy1(CStudent stu)
    copy1(stu3);                //函数参数，先拷贝构造，入栈传参，再调用函数

    copy1(0);                   //先尝试构造，入栈传参，再调用函数
    
    //CStudent copy2(void)
    copy2();                    //本函数创造临时空间，服务于copy2函数，copy2返回的值在本函数栈空间内。本行结束时，进行析构

    CStudent tmp = copy2();     //不同于上面，这里没有立即析构

    copy3(&stu1);               //传递指针，直接调用函数

    copy4(stu1);                //传递指针，直接调用

    CStudent stu5(5, "copy5");
    copy5(stu5);                //直接
}

void
test_nameless(void)
{
    CStudent();     //构造，然后立即析构
    CStudent(110);  //尝试构造，然后立即析构
    CStudent(110, "hello");    
    
    CStudent stu2 = CStudent(110, "hello");     //相当于直接对stu2进行构造，暂未析构      
    cout << stu2.GetName() << endl;
               
    
    CStudent stu3(CStudent(110, "HELLO"));  //相当于直接对stu3进行构造，暂未析构      
    cout << stu3.GetName() << endl;
    
    //copy1(CStudent stu)
    //copy1(stu3);                //函数参数，先拷贝构造，入栈传参，再调用函数
    copy1(CStudent(11, "COPY1"));  // 构造，入栈传参， 再调用函数
    
    copy1(CStudent(11));              
    
    //CStudent copy2(void)
    copy2();                //本函数创造临时空间，服务于copy2函数，copy2返回的值在本函数栈空间内。本行结束时，进行析构                  
    
    CStudent tmp = copy2(); //同上，但暂未析构    
    
    copy3(&CStudent(3, "COPY3"));            
    
    copy4(CStudent(4,"COPY4"));              
    
    copy5(CStudent(5, "COPY5"));                

}

int
main(void)
{
    test_var();

    test_copyconstruction();

    test_nameless();

    return 0;
}