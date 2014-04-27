#include <iostream>
using namespace std;

/*
���C�޲κ�
*/
void
test_macro(void)
{
    const int NUM = 3;
    
    *(int *)&NUM = 2;         //try to change NUM by pointer, ok, success.
    
    //����޲κ�
    cout << NUM + 2 << endl;  // when compiling, will replace into " cout << 3 + 2 << endl;
    // so 5, not 4.
    
    int ntest = *(int *)&NUM; //ntest will be the already changed NUM, that is 2.
    cout << ntest << endl;
}

void
test_change(void)
{
    char *p1 = "hello";     //hello��ȫ��������
    p1[0] = 'w';            //��ͼ����ȫ�����������ݣ�������ʱ����

    const char *p2 = "hello";
    //p2[0] = 'w';            //p2��ָ������ݲ��ܸ��ģ��ڱ���ʱ�ͱ���
}

void
test_convert(void)
{
    char *p1 = "hello";
    const char *p2 = "hello";

    p2 = p1;    //ok. ��ͼ�����ϸ����p1ת��Ϊ�ϸ����͵�p2.
    
    p1 = p2;    //error, ��ͼ���ϸ����͵�p2ת��Ϊ���ϸ����͵�p1, ����ܵ��¶�p2���޸ġ�����
}

int
main(void)
{
    //test_macro();

    //test_change();

    test_convert();

    return 0;
}