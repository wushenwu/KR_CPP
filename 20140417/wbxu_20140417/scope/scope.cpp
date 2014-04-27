#include <iostream>
using namespace std;

/*
语句是一个程序单位， 如果在if语句和switch语句中进行条件测试的表达式中声明标识符，
                    则该标识符的作用域在该语句内。
*/

int
getvalue()
{
    //pass
    int i = 3;
    return  i;
}

void
test_if(void)
{
    if (int i = getvalue())              //i的作用域从if开始，到else结束
    {
        cout << i * 2 << endl;
    }
    else
    {
        i = 100;
        cout << i * 2 << endl;
    }

    //cout << i * 2 << endl;      //error C2065: 'i' : undeclared identifier
}

void
test_switch(void)
{
    switch (int i = getvalue())
    {
        int j = 0;          //error C2360: initialization of 'j' is skipped by 'case' label
    case 1:
        {
            cout << i * 2 << endl;
            cout << j * 2 << endl;
            break;
        }       
    }

    //cout << i * 2 << endl;      //error C2065: 'i' : undeclared identifier
}  

void
test_for(void) 
{
    for (int i = 0; i < 2; i++)
    {
        cout << i * 2 << endl;
    }

    cout << i * 2 << endl;  //works here. 但这。。。

    if (0)              //经常会看到对此的宏处理
    {
    }
    else
        for (int j = 0; j < 2; j++)
        {
            cout << j * 2 << endl;
        }

        cout << j * 2 << endl;  //error C2065: 'j' : undeclared identifier
}

int
main(void)
{
    test_if();

    test_switch();

    test_for();

    return 0;
}