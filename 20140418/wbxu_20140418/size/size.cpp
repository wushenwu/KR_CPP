/************************************************************************/
/* д�������һ������Ϳսṹ��Ĵ�С                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

struct tag_empty
{

};

class CEmpty
{

};

int
main(void)
{
    cout << "size of empty struct: " << sizeof(tag_empty) << endl;

    cout << "size of empty class: " << sizeof(CEmpty) << endl;

    return 0;
}