/************************************************************************/
/* 1.���һ���ֻ࣬�ܲ���һ������(��ʾ����̬��Ա����)     

1)  ����Ӧ�ý����캯������Ϊ˽�У����ö���Ĳ���
2)  �ڹ���һ����������Ľӿڣ�ͨ���ýӿڣ����Դ�������
3)  �ýӿ��ǲ������ڶ���ģ����ڶ�����ڶ����ڣ����Կ�����static��Ա����
3)  �ɴ������󣬵�Ӧ����ͬһ�����󣬾��൱�ڽ�����һ�Σ�����൱��static��������ʼ��һ��
4)  ������Ҫ�˹���ʽ�Ľ��������� ���߿�������ȫ�ֶ����������Զ�������
5)  ����ȫ�ֶ����Զ�������ʱ�����Կ��ǽ�����Ԫ��Ա���� */
/************************************************************************/

#include <iostream>
using namespace std;

#include "OneObject.h"

//�����Զ����Ĵ��������ٶ���
COther g_controlobject;

void
test_oneobject(void)
{
    //�����ȫ�ֶ���g_controlobject�Ѿ����д����˶��󣬺�������ͼ�Ĵ�������õĶ���ͬһ������
    CStudent *stu1 = CStudent::CreateObject();
    stu1->SetName("stu1");
    cout << "Name of stu1: " << stu1->GetName() << endl;
    cout << "addr(stu1): " << hex << stu1 << endl;

    CStudent *stu2 = CStudent::CreateObject();
    cout << "Name of stu2: " << stu2->GetName() << endl;
    cout << "addr(stu2): " << hex << stu2 << endl;

    //��ʹ��������ʽ����������Ҳû���⣬ȫ�ֵĶ����Ѿ������˽ӹܡ�
    //stu1->~CStudent();
    //stu2->~CStudent();
}

int
main(void)
{
    test_oneobject();

    return 0;
}