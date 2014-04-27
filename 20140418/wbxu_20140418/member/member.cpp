/************************************************************************/
/* 4.ͨ��д����֤����C++�еĳ�Ա�����Ƕ����ģ���Ա�����ǹ���ġ�                                                                     */
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
    //��ͨ��ָ�룬ͻ�����ƣ���˽�����ݳ�Ա���з���
    //�˽����ڴ�ṹ
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

    //ͬһ��Ĳ�ͬ��������ݳ�Ա���໥����
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

    //�����Ա����ָ��
    typedef void (CTest::*pfnSetData)(int);

    pfnSetData pfn1 = test1.SetData;
    pfnSetData pfn2 = test2.SetData;

    //ͬһ��Ĳ�ͬ����乲���Ա���������ǵĵ�ַ��ͬ
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