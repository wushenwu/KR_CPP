#include <iostream.h>
#include <iomanip.h>

/*
inline _CRTIMP ostream& __cdecl flush(ostream& _outs) { return _outs.flush(); }
inline _CRTIMP ostream& __cdecl endl(ostream& _outs) { return _outs << '\n' << flush; }
*/
void
test_flush(void)
{
    cout << "Just 4 Fun";

    cout << "Just 4 Fun"
         << flush;

    cout << "Just 4 Fun"
         << endl;

}

void
test_hex(void)
{    
    //��Ӱ�����������ʽ�����ǽ�����ʾ������
    cout << dec << 33 << endl
         << hex << 33 << endl
         << oct << 33 << endl;
    
    //�����ʽ������������õ�Ӱ��
    cout << 32 << endl;
}

void
test_setf(void)
{
#if 0
    //16���ƴ�д���
    cout.setf(ios::uppercase);
    cout.setf(ios::hex);
    cout << "------\n" << 15 << endl;
    cout.unsetf(ios::uppercase);
    cout.unsetf(ios::hex);
#else
    /* Ҳ�������� */
    long ori_flg = cout.flags();            //����ԭflag
    cout.setf(ios::uppercase | ios::hex);   //������flag
    
    cout << "------\n" << 15 << endl;

    cout.flags(ori_flg);                    //�ָ�

    /* �Ա� */
    cout << "------\n" << 15 << endl;       
    
    /* ����������, ����� */
    ori_flg = cout.flags(ios::uppercase | ios::hex);   //������flag��ͬʱ������ԭflag 
    cout << "------\n" << 15 << endl;  
    cout.flags(ori_flg);    
#endif
}

void
test_width(void)
{
    cout.width(8);
    cout << 7 << endl;

    cout << 7 << endl;  //������ý�һ����Ч��

    long nflag = cout.flags(ios::right);
    cout.width(8);
    cout.fill('0');
    cout << 7 << endl;
}

void
test_precision(void)
{
    cout.precision(5);
    cout << 3.1415926 << endl;

    long nflag = cout.flags(ios::fixed);
    cout << 3.1415926 << endl;
    cout.flags(nflag);

    nflag = cout.flags(ios::scientific);
    cout << 3.1415926 << endl;
    cout.flags(nflag);    
}

int
main(void)
{
    //test_flush();

    //test_hex();

    //test_setf();

    //test_width();

    test_precision();

    return 0;
}