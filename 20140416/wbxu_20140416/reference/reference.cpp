#include <iostream>
using namespace std;

void
ref_basic(void)
{
    int i1;
    int &ri1 = i1;       //必须初始化。ri1成为i1的别名
    
    i1 = 5;
    cout << i1 << endl;
    cout << ri1 << endl;
    
    ri1 = 7;            //对引用的操作就是对原始目标的操作
    cout << i1 << endl;
    cout << ri1 << endl;
    
    cout << &i1 << endl;
    cout << &ri1 << endl;   //引用的地址，目标的地址

    //int& ri2 = 2;   //引用不能用常量进行初始化。

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
    int *&rpa = a; //将int *的引用rpa初始化为a

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
    //引用用于传递参数的例子，可见exchange_by_ref

    //引用用于返回多个值，同指针
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
    float a = fn1(3.0); //a 仅是tmp的一份拷贝

    //float &b = fn1(5.0); //error C2440: 'initializing' : cannot convert from 'float' to 'float &'
    float &b = a;   //若要以返回值初始化一个引用，应该先创建一个变量，将函数返回值赋给这个变量
                    //然后再以该变量来初始化该引用。

    b = 1.0;    //仅改变a大小，不会改变全局的tmp大小

    a = fn2(3.0); 

    a = 1.0;

    float &c = fn2(3.0);    //现在c是全局变量tmp的别名
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

//5.利用返回引用来操作结构体
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