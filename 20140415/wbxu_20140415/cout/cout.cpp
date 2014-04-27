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
    //会影响后面的输出格式，除非进行显示的设置
    cout << dec << 33 << endl
         << hex << 33 << endl
         << oct << 33 << endl;
    
    //输出格式受上面最后设置的影响
    cout << 32 << endl;
}

void
test_setf(void)
{
#if 0
    //16进制大写输出
    cout.setf(ios::uppercase);
    cout.setf(ios::hex);
    cout << "------\n" << 15 << endl;
    cout.unsetf(ios::uppercase);
    cout.unsetf(ios::hex);
#else
    /* 也可以这样 */
    long ori_flg = cout.flags();            //保存原flag
    cout.setf(ios::uppercase | ios::hex);   //设置新flag
    
    cout << "------\n" << 15 << endl;

    cout.flags(ori_flg);                    //恢复

    /* 对比 */
    cout << "------\n" << 15 << endl;       
    
    /* 还可以这样, 更简洁 */
    ori_flg = cout.flags(ios::uppercase | ios::hex);   //设置新flag的同时，保存原flag 
    cout << "------\n" << 15 << endl;  
    cout.flags(ori_flg);    
#endif
}

void
test_width(void)
{
    cout.width(8);
    cout << 7 << endl;

    cout << 7 << endl;  //宽度设置仅一次有效。

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