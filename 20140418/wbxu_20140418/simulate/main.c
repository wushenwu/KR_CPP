#include <stdio.h>
#include "simulate.h"

int
main(void)
{
    tag_class object1;
    tag_class object2;

    ClassInit(&object1);
    object1.pfnSetData(&object1, 3);

    printf("%d\r\n", object1.pfnGetData(&object1));

    //���ʵ�ֲ�ͬ��������ݳ�Ա�ĸ���
    ClassInit(&object2);
    object2.pfnSetData(&object2, 4);

    printf("%d\r\n", object1.pfnGetData(&object1));
    printf("%d\r\n", object2.pfnGetData(&object2));

    return 0;
}