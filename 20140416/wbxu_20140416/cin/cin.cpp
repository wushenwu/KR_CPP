#include <iostream>
using namespace std;

int
main(void)
{
    char szbuf[8];

    cin.read(szbuf, 7);
    szbuf[7] = '\0';

    //�������������ֱ������ָ�����ַ�
    cin.ignore(cin.rdbuf()->in_avail(),     //��������ʣ��ĸ���
                '\n');

    //
    cin.getline(szbuf,
                 8,         //����\0 ������Ŀ
                 '\n');
    
    return 0;
}