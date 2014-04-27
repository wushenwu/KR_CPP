/************************************************************************/
/* 1.写一个学员信息录入程序，以学员信息类数组来放置录入的学员信息，并提供多种录入方式：
(1)学号和年龄为默认，学号默认为从1开始递增，年龄默认为20
(2)学号，姓名，年龄均不为默认,以学号和姓名来做为构造函数的参数(但要判断学号是唯一的,如果条件不符自己调用析构函数)
实现学员信息类的拷贝，(利用拷贝构造函数)                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

#include "studinfo.h"

void
test_method1()
{
    int nresult;

    while(1)
    {
        CStudent tmp("method1");    //调用构造函数
        nresult = AddStudent(tmp);            //先调用拷贝构造函数，再调用函数
        if (NO_SPACE == nresult)
        {
            cout << "No more space" << endl;
            break;
        }
    }

    ShowStudent();
}

void
test_method2()
{
    int nresult;
    char szname[64] = {0};
    int no;
    int nage;

    while (1)
    {
        cout << "Please enter student name, no and age: " << endl;
        cin >> szname;
        cin >> no;
        cin >> nage;

        CStudent tmp(no, szname);
        tmp.SetAge(nage);
        nresult = AddStudent(tmp);

        if (NO_SPACE == nresult)
        {
            cout << "                           No more space" << endl;
            break;
        }

        if (REPEATED == nresult)
        {
            cout << "                           Student No already exist, enter again" << endl;
            continue;
        }
    }//end for while (1)  input

    ShowStudent();
}


int
main(void)
{
#ifdef USE_HEAP
    int nNumber = 0;
    cout << "Please enter number of students you want to store: " << endl;
    cin >> nNumber;

    int nresult = SetStudNumber(nNumber);
    if (NO_SPACE == nresult)
    {
        cout << "New Heap Space for these students failed " << endl;
        return -1;
    }
#endif

    test_method1();

    //test_method2();

#ifdef USE_HEAP
    FreeSpace();
#endif

    return 0;
}
