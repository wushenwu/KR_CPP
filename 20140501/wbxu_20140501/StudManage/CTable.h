#ifndef CTABLE_H_F586A194_99ED_4523_807D_8D3B3822AEE0

#define CTABLE_H_F586A194_99ED_4523_807D_8D3B3822AEE0

#include "Struct.h"
#include "Const.h"

//�����
class CTable
{
public:
    CTable();
    ~CTable();

    unsigned long GetRecordsNum(void) const;
    void SetRecordsNum(unsigned long num);

protected:
    /*
    Function: ��psztablefile��ָʾ�ļ��е����м�¼��ȡ��buf��
    Param   : buf ���ڽ��ն�ȡ�������м�¼
              size Ϊÿ����¼�Ĵ�С
    Return  : SUCCESS ���سɹ������½��ɹ�
              NOT_EXIST ��Ӧ�ļ�������
               FAILED  ����ʧ��
    */
    int LoadTable(char  **ppbuf, const char *psztablefile, size_t recordsize);

    /*
    Function: �����ļ�psztablefile���б��ݣ�
              ���ڴ���buf��ָʾ�ı�д�뵽���ļ�psztablefile��, ÿ����¼��СΪrecordsize

    Return : SUCCESS �ɹ����� FAILED ʧ��
    */
    int SaveTable(void *buf,
                  const char *psztablefile,
                  unsigned char recordsize
                  );


    /*
    Function: �������޹صĲ�������

    Param   : IN OUT unsigned long *nrecords,         //���봫����table��record������
                    void *records,                    //table��record����ʼ��ַ
                    size_t recordsize,                //record�Ĵ�С 
              IN OUT int *index,                      //���ղ����λ��
                int (*compare)(void *, void *)        //�Ƚϼ�¼��С�Ļص�����
    */
    void InsertIntoTable(unsigned long *nrecords,         
                        void *records,                         
                        void *newrecord,                       
                        size_t recordsize,
                        int *index,
                        int (*compare)(void *, void *)     
                        );

    /*
    Function: �������޹صı��м�¼���²����������¼���£�
    Param   :  void *records,          //����records��ʼ��ַ
                size_t recordsize,      //����record�Ĵ�С
                int index,              //Ҫ���µ�record
                void *newrecord         //������
    */
    void UpdateTable(void *precords,          
                    size_t recordsize,      
                    int index,              
                     void *pnewrecord         
                    );

    /*
    Function: �������޹صı�����ɾ������
    Param   : IN OUT unsigned long *nrecords,     //���봫����table��record������
              void *records,                      //table��records����ʼ��ַ
              size_t recordsize,                  //record�Ĵ�С
              int index                           //Ҫɾ����record��table�е��±�
    */
    void RemoveFromTable(unsigned long *pnrecords,     
                        void *precords,                      
                        size_t recordsize,                  
                        int index                          
                        );


protected:
    unsigned long m_nrecords;
};

//��ӱ�
class CAddTable: public CTable
{
public:
    CAddTable();
    ~CAddTable();

    tag_addrecord *GetRecords(void) const;

    /*
    Function: ��pszaddtablefile�м�����ӱ��ڴ���
    Return  : SUCCESS ���سɹ������½��ɹ�
               NOT_EXIST ��Ӧ�ļ�������
               FAILED  ����ʧ��
    */
    int LoadTable(const char *pszaddtablefile);

    /*
    Function: ������ӱ����ڴ��е���ӱ�д�뵽��ӱ��ļ�pszaddtable��
    
    Return  : SUCCESS �ɹ����� FAILED ʧ��
    */
    int SaveTable(const char *pszaddtablefile);

    /*
    Function: ��paddrecord�����(start, size, namesize)��¼����Ĳ��뵽��ӱ���
                start��Ϊkeywords��    ����        ����        
    */
    void
    InsertIntoTable(tag_addrecord *paddrecord);

    /*
    Function: ����ӱ�����Ӧindex����ʶ�ļ�¼����Ϊ�´����addrecord��
    */
    void
    UpdateTable(int index, tag_addrecord *paddrecord);

    /*
    Function: ��index ����ʶ�ļ�¼����ӱ���ɾ��, ����֤��������ԡ�
    */
    void
    RemoveFromTable(int index);

protected:
    tag_addrecord *m_precords;  //�䳤����������Ҫʵʱ����
};

//ɾ����
class CDelTable: public CTable
{
public:
    CDelTable();
    ~CDelTable();

    tag_delrecord* GetRecords(void) const;
    /*
    Function: ��pszdeltablefile�м�����ӱ��ڴ���
    Return  : SUCCESS ���سɹ������½��ɹ�
              NOT_EXIST ��Ӧ�ļ�������
              FAILED  ����ʧ��
    */
    int LoadTable(const char *pszdeltablefile);

    /*
    Function: ����ɾ�������ڴ��е�ɾ����д�뵽ɾ�����ļ�pszdeltablefile��

    Return : SUCCESS �ɹ����� FAILED ʧ��
    */
    int SaveTable(const char *pszdeltable);


    /*
    Function: ��pdelrecord�����(start, size)��¼����Ĳ��뵽**ppdeltable��, 
             ����g_del_tableָʾ�������пռ��������
    
    Effect  : ����g_del_table, ��g_del_tableָʾ���������пռ�������ϣ������ٷ���
             ע�⣬��Ϊ���ǵ�g_del_table�ǰ��������ģ�������Ҫrealloc, 
             ע������Ĵ���
    */
    void InserIntoTable(tag_delrecord *pdelrecord);

    /*
    Function: ����g_del_table�У�index��¼����ǰ��������Ƿ�Ϊ�����Ŀ��пռ䣬�������ϣ�
            �Ի�ȡ����Ŀ��пռ䣬���ں����ٷ���
    Param   : index
    Effect  : ���ܵ���removefromtable��
    Caller: this function can only be called by insertintodeltable
    */
    void
    Reorganize(unsigned long index);

    /*
    Function: ��ɾ��������Ӧindex����ʶ�ļ�¼����Ϊ�´����pdelrecord��
    */
    void
    UpdateTable(int index, tag_delrecord *pdelrecord);

    /*
    Function: ��index ����ʶ�ļ�¼�ӱ���ɾ��, ����֤�����ԡ�
    */
    void
    RemoveFromTable(int index);
      
protected:
    tag_delrecord *m_precords;   //�䳤����������Ҫʵʱ����
};

#endif
