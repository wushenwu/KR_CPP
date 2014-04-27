#include <iostream>
using namespace std;

#include "student.h"

void
test_var(void)
{
    //����һ����������ʼ����������ʽ
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
#if 0
    CStudent tmp(2);    //����
    return tmp;         //�������죬����ջ�ڵ���ʱ����tmp����������ú���ջ�У�Ȼ����������
#endif

    return CStudent(2); //���죬ֱ�Ӳ������ú���ջ�ռ䣬δ����������ú�������
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
    //��������ܷ��ʳ���Ա����
}

void
test_copyconstruction(void)
{
    CStudent stu1(110, "hello");    

    CStudent stu2 = stu1;       //�������캯��
    cout << stu2.GetName() << endl;

    //stu2 = stu1;            // ǳ����, �ᵼ����������

    CStudent stu3(stu1);        //��������
    cout << stu3.GetName() << endl;

    //copy1(CStudent stu)
    copy1(stu3);                //�����������ȿ������죬��ջ���Σ��ٵ��ú���

    copy1(0);                   //�ȳ��Թ��죬��ջ���Σ��ٵ��ú���
    
    //CStudent copy2(void)
    copy2();                    //������������ʱ�ռ䣬������copy2������copy2���ص�ֵ�ڱ�����ջ�ռ��ڡ����н���ʱ����������

    CStudent tmp = copy2();     //��ͬ�����棬����û����������

    copy3(&stu1);               //����ָ�룬ֱ�ӵ��ú���

    copy4(stu1);                //����ָ�룬ֱ�ӵ���

    CStudent stu5(5, "copy5");
    copy5(stu5);                //ֱ��
}

void
test_nameless(void)
{
    CStudent();     //���죬Ȼ����������
    CStudent(110);  //���Թ��죬Ȼ����������
    CStudent(110, "hello");    
    
    CStudent stu2 = CStudent(110, "hello");     //�൱��ֱ�Ӷ�stu2���й��죬��δ����      
    cout << stu2.GetName() << endl;
               
    
    CStudent stu3(CStudent(110, "HELLO"));  //�൱��ֱ�Ӷ�stu3���й��죬��δ����      
    cout << stu3.GetName() << endl;
    
    //copy1(CStudent stu)
    //copy1(stu3);                //�����������ȿ������죬��ջ���Σ��ٵ��ú���
    copy1(CStudent(11, "COPY1"));  // ���죬��ջ���Σ� �ٵ��ú���
    
    copy1(CStudent(11));              
    
    //CStudent copy2(void)
    copy2();                //������������ʱ�ռ䣬������copy2������copy2���ص�ֵ�ڱ�����ջ�ռ��ڡ����н���ʱ����������                  
    
    CStudent tmp = copy2(); //ͬ�ϣ�����δ����    
    
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