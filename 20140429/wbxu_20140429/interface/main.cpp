/************************************************************************/
/* 2.��Ϊ�������ƶ��ýӿڣ�
ʹ�������Լ��ݷ��ϴ˱�׼�ӿڵ��������������Կ���
(������ʵ�֣���Ӧ�Ľӿڼ�Ϊ����ͳһ��׼��Ϊͳһ����)��                                                                     */
/************************************************************************/

#include "interface.h"

int
main(void)
{
    CMainBoard boardobj;

    //not pluged now, access USB
    boardobj.Play();

    //plug and play
    boardobj.Plug(new CAudioCardInterface);
    boardobj.Play();

    boardobj.Plug(new CNetCardInterface);
    boardobj.Play();

    boardobj.Plug(new CGraphCardInterface);
    boardobj.Play();

    return 0;
}