/************************************************************************/
/* 
1.����bed,ɳ����sofa�ṩ��sit()����,ɳ����sofabed�ṩ��lie()������sofabed�Ƕ��ؼ̳�bed��sofa�ġ�
(1)ʵ���������ؼ̳е����
(2)д��һ�����Ա���ʹ�ö��ؼ̳е���ơ�                                                                     */
/************************************************************************/

#include "SofaBed.h"

void
test_multi_inherit()
{
    CSofaBed sofabed;

    cout << sizeof(sofabed) << endl;

    sofabed.Lie();
    
    //sofabed.Sit();  //error C2385: 'CSofaBed::Sit' is ambiguous
                    //warning C4385: could be the 'Sit' in base 'CBed' of class 'CSofaBed'
                    //warning C4385: or the 'Sit' in base 'CSofa' of class 'CSofaBed'

    sofabed.CBed::Sit();

    sofabed.CSofa::Sit();

    //about convert.
    CBed *pbed = &sofabed;
    CSofa *psofa = &sofabed;
    cout << hex << &sofabed << endl;
    cout << pbed << endl;
    cout << psofa << endl;

}

void
test_inherit_NON(void)
{
    CSofaBed_NON sofabed_NON;

    cout << sizeof(sofabed_NON) << endl;

    sofabed_NON.Lie();

    sofabed_NON.m_bedobj.Sit();
    
    sofabed_NON.m_sofaobj.Sit();

    //about convert
    CBed *pbed = &sofabed_NON.m_bedobj;
    CSofa *psofa = &sofabed_NON.m_sofaobj;
    cout << hex << &sofabed_NON << endl;
    cout << pbed << endl;
    cout << psofa << endl;
}

int
main(void)
{
    test_multi_inherit();

    test_inherit_NON(); // ����ʹ�ö��ؼ̳�

    return 0;
}