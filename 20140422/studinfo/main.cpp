/************************************************************************/
/* 1.дһ��ѧԱ��Ϣ¼�������ѧԱ��Ϣ������������¼���ѧԱ��Ϣ�����ṩ����¼�뷽ʽ��
(1)ѧ�ź�����ΪĬ�ϣ�ѧ��Ĭ��Ϊ��1��ʼ����������Ĭ��Ϊ20
(2)ѧ�ţ��������������ΪĬ��,��ѧ�ź���������Ϊ���캯���Ĳ���(��Ҫ�ж�ѧ����Ψһ��,������������Լ�������������)
ʵ��ѧԱ��Ϣ��Ŀ�����(���ÿ������캯��)                                                                     */
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
        CStudent tmp("method1");    //���ù��캯��
        nresult = AddStudent(tmp);            //�ȵ��ÿ������캯�����ٵ��ú���
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
