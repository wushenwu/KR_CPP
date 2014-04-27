/************************************************************************/
/* 1.设计一个类，只能产生一个对象(提示：静态成员函数)     

1)  首先应该将构造函数设置为私有，禁用对象的产生
2)  在公开一个创建对象的接口，通过该接口，可以创建对象
3)  该接口是不依赖于对象的，先于对象存在而存在，所以可以用static成员函数
3)  可创建对象，但应该是同一个对象，就相当于仅创建一次，这就相当于static变量仅初始化一次
4)  对象需要人工显式的进行析构， 或者可以利用全局对象来进行自动化处理
5)  利用全局对象自动化处理时，可以考虑借助友元成员函数 */
/************************************************************************/

#include <iostream>
using namespace std;

#include "OneObject.h"

//用于自动化的创建和销毁对象
COther g_controlobject;

void
test_oneobject(void)
{
    //上面的全局对象g_controlobject已经进行创建了对象，后续所试图的创建所获得的都是同一个对象。
    CStudent *stu1 = CStudent::CreateObject();
    stu1->SetName("stu1");
    cout << "Name of stu1: " << stu1->GetName() << endl;
    cout << "addr(stu1): " << hex << stu1 << endl;

    CStudent *stu2 = CStudent::CreateObject();
    cout << "Name of stu2: " << stu2->GetName() << endl;
    cout << "addr(stu2): " << hex << stu2 << endl;

    //即使忘记了显式进行析构，也没问题，全局的对象已经进行了接管。
    //stu1->~CStudent();
    //stu2->~CStudent();
}

int
main(void)
{
    test_oneobject();

    return 0;
}