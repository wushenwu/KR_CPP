#include <iostream>
using namespace std;

/*
�����һ������λ�� �����if����switch����н����������Եı��ʽ��������ʶ����
                    ��ñ�ʶ�����������ڸ�����ڡ�
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
    if (int i = getvalue())              //i���������if��ʼ����else����
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

    cout << i * 2 << endl;  //works here. ���⡣����

    if (0)              //�����ῴ���Դ˵ĺ괦��
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