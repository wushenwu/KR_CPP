#include <iostream>
using namespace std;

#include "student.h"

void
test_var(void)
{
    //˵��һ����������ʼ����������ʽ
    int m = 10;
    int n(20);  //<=> int n = 20;

    //��ֵʱ��ֻ��һ�ַ���
    m = 10;
    //n(20);  //���Ǹ�ֵ�����ǵ�����Ϊn�ĺ���
}

void 
copy1(CStudent stu)
{
    stu.SetNo(1);
}

CStudent 
copy2()
{
    CStudent tmp(2);    //����
    return tmp;         //�������죬����
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

    CStudent stu2 = stu1;       //�������캯��
    cout << stu2.GetName() << endl;

    CStudent stu3(stu1);        //��������
    cout << stu3.GetName() << endl;

    copy1(stu3);                //�����������ȿ�������ջ���Σ��ٵ��ú���

    copy1(0);                   //�ȳ��Թ��죬��ջ���Σ��ٵ��ú���
    
    copy2();                    //��ʱ���δ����

    CStudent tmp = copy2();     //���Ż�����

    copy3(&stu1);               //ֱ�ӵ��ú���

    copy4(stu1);                //ֱ�ӵ���

    const CStudent stu5(5, "555");
    copy5(stu5);                //ֱ��
}

int
main(void)
{
    test_var();

    test_copyconstruction();

    return 0;
}