#include <iostream>
using namespace std;

void
ref_basic(void)
{
    int i1;
    int &ri1 = i1;       //�����ʼ����ri1��Ϊi1�ı���
    
    i1 = 5;
    cout << i1 << endl;
    cout << ri1 << endl;
    
    ri1 = 7;            //�����õĲ������Ƕ�ԭʼĿ��Ĳ���
    cout << i1 << endl;
    cout << ri1 << endl;
    
    cout << &i1 << endl;
    cout << &ri1 << endl;   //���õĵ�ַ��Ŀ��ĵ�ַ

    //int& ri2 = 2;   //���ò����ó������г�ʼ����

    const int &ri3 = 2; //this is ok. just like const i3 = 2;
    //ri3 = 3;            //error.  just like cannot change i3 = 3;

    const int i3 = 3;
}

void
ref_type(void)
{
    /*
    Type var;
    Type &rvar = var;
    */
    int *a;
    int *&rpa = a; //��int *������rpa��ʼ��Ϊa

    int b = 8;
    rpa = &b;

    //void &v = 3;

    //int arry[10];
    //int &rarry[10] = arry;   
}

void
ref_param_example(int n , int &rsquared, int &rcubed)
{
    rsquared = n * n;
    rcubed = n * n * n;
}

void
ref_param(void)
{
    //�������ڴ��ݲ��������ӣ��ɼ�exchange_by_ref

    //�������ڷ��ض��ֵ��ָͬ��
    int n = 3;
    int nsquared = 0;
    int ncubed = 0;

    ref_param_example(n, nsquared, ncubed);
    cout << nsquared << endl;
    cout << ncubed << endl;
}

float tmp;

float &
fn3(float r)
{
    float ftest;

    ftest = r * r * 3.14;
    return ftest;
}

float &
fn2(float r)
{
    tmp = r * r * 3.14;
    return tmp;
}

float 
fn1(float r)
{
    tmp = r * r * 3.14;
    return tmp;
}

void
ref_return(void)
{
    float a = fn1(3.0); //a ����tmp��һ�ݿ���

    //float &b = fn1(5.0); //error C2440: 'initializing' : cannot convert from 'float' to 'float &'
    float &b = a;   //��Ҫ�Է���ֵ��ʼ��һ�����ã�Ӧ���ȴ���һ������������������ֵ�����������
                    //Ȼ�����Ըñ�������ʼ�������á�

    b = 1.0;    //���ı�a��С������ı�ȫ�ֵ�tmp��С

    a = fn2(3.0); 

    a = 1.0;

    float &c = fn2(3.0);    //����c��ȫ�ֱ���tmp�ı���
    c = 1.0;

    float &d = fn3(3.0);    //fn3 bug exists.
}

typedef struct tag_test
{
    int i;
    char ch;
}tag_test;

tag_test &
ref_struct(tag_test &test)
{
    return test;
}

//5.���÷��������������ṹ��
void
t5(void)
{
    tag_test test = {0};

    //just for fun
    tag_test &rtest = ref_struct(test);

    rtest.ch = 'F';
    rtest.i = 1;
}

int
main(void)
{
    //ref_basic();

    //ref_type();

    //ref_param();

    //ref_return();

    t5();

    return 0;
}