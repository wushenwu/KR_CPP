/************************************************************************/
/* 4.通过写程序证明，C++中的成员变量是独立的，成员方法是共享的。                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

class CTest
{
public:
    void SetData(int ndata);

public:
    int GetData();

private:
    int m_ndata;
};

void
CTest::SetData(int ndata)
{
    m_ndata = ndata;
}

int
CTest::GetData()
{
    return m_ndata;
}

void
test_change(void)
{
    //可通过指针，突破限制，对私有数据成员进行访问
    //了解其内存结构
/*
 private:
    int m_ndata;
*/
    CTest test;

    test.SetData(0x1234);
    cout << hex << test.GetData() << endl;

    *(int *)(&test) = 0x5678;
    cout << hex << test.GetData() << endl;
 

}

void
test_member(void)
{
    CTest test1;
    CTest test2;

    //同一类的不同对象的数据成员间相互隔离
    cout << hex << "test1 addr: 0x" << &test1 << endl;
    cout << hex << "test2 addr: 0x" << &test2 << endl;

    test1.SetData(0x1234);
    cout << hex << "test1 data: 0x" << test1.GetData() << endl;

    test2.SetData(0x5678);
    cout << hex << "test2 data: 0x" << test2.GetData() << endl;
    cout << hex << "test1 data: 0x" << test1.GetData() << endl;
}

void
test_method(void)
{
    CTest test1;
    CTest test2;

    //定义成员函数指针
    typedef void (CTest::*pfnSetData)(int);

    pfnSetData pfn1 = test1.SetData;
    pfnSetData pfn2 = test2.SetData;

    //同一类的不同对象间共享成员函数，它们的地址相同
    cout << hex << "test1 function addr: 0x" << (int &)pfn1 << endl;
    cout << hex << "test2 function addr: 0x" << (int &)pfn2 << endl;
    cout << hex << "test2 function addr: 0x" << *(int *)&pfn2 << endl;
}

int
main(void)
{
    test_change();

    test_member();

    test_method();
    
    return 0;
}