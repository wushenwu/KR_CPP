#ifndef CMyFile_H_CC91F08E_62AC_4c63_A060_570FFB2580DC

#define CMyFile_H_CC91F08E_62AC_4c63_A060_570FFB2580DC

#include "CMyString.h"
#include "Struct.h"

class CMyFile
{
public:
    CMyFile() { }
    CMyFile(const char *pszfile)
        :m_filename(pszfile)
    {

    }

    /*
    Function: �����ļ��� ����ѧ����Ϣ�洢�ļ�����ӱ�ɾ����洢�ļ�
    */
    void SetFile(const char *pszfile);
    const char *GetFile(void) const;

    /*
    Function: ��m_filename��offset��ַ��ȡsize�ֽڵ�buf��
    
    Return : SUCCESS �ɹ���ȡ�� FAILED ʧ��
    */
    int ReadData(void *pbuf, unsigned long offset, unsigned char size) const;

    /*
    Function: ��m_filename�ļ���׷�Ӵ�СΪsize��buf
      
    Return  : SUCCESS �ɹ�д��  FAILED ʧ��
    */
    int AppendData(void *pbuf, unsigned char size);

    /*
    Function: ��m_filename�ļ���ա�
    
    Return  : SUCCESS �ɹ����  FAILED ʧ��
    */
    int ResetData(void);

    /*
    Function: ��m_filename�ļ���offset��ַ�����ݸ�дΪ��СΪsize�ֽڵ�buf.
    
    Return : SUCCESS �ɹ��޸ģ� FAILED ʧ��
    */
    int ModifyData(void *pbuf, unsigned long offset, unsigned char size) const;

    /*
    Function: ����ļ��Ƿ���ڣ� ����������ͼ�½���    
    Param   : pszfile �ļ����� ��MAX_INPUT���ƣ�
    Return  : SUCCESS ȷ�ϴ��ڻ����½��ɹ�
               NOT_EXIST �����ڣ��½�ʧ�ܣ�
    
    Remark  : ��������init�׶Σ������Ϣ�洢�ļ�����ӱ��ļ���ɾ�����ļ�
    */
    static int CheckFile(const char *pszfile);

    /*
    Function: �ļ�������ÿ4�ֽڽ��У�
    Param   : 
    Return  : SUCCESS �ɹ������� FAILED ����ʧ��
    */
    static int FileCopy(const char *pfilesrc, const char *pfiledst);
    
protected:
    CMyString m_filename;
    
};

//ѧ����Ϣ�洢�ļ����
class CInfoFile: public CMyFile       
{
public:
    CInfoFile(const char *pszfile = "info.txt");

    int
    ReadData(tag_student *pstudent, char *pszname, char *pszno,  //���ն�ȡ��ѧ������Ϣ
             tag_addrecord *paddrecord                      //Ҫ��ȡ��ѧ����Ϣ
              ) const;

    int
    AppendData(tag_student *pstudent, char *pszname, char *pszno,   //ѧ����Ϣ
               unsigned long offset,                             //�ļ���ַ
               unsigned char namesize,                          //ѧ������ռ�ÿռ��С��
               unsigned char nosize);                           // 

    /*
    Function: ��student, szname, sznoָ����ѧ����Ϣ������ļ���
    Param   : tag_student *student, char *szname, char *szno,   //ѧ����Ϣ
            unsigned long start,                              //���봫�����ļ���ַ
            unsigned char namesize ,                          //ѧ������ռ�ÿռ��С
            unsigned char nosize                              //ѧ��ѧ��ռ�ÿռ��С

    Return  : SUCCESS �ɹ��洢  FAILED  �洢ʧ��
    */
    int
    ModifyData(tag_student *pstudent, char *szname, char *szno,   
                unsigned long offset,                              
                unsigned char namesize ,                          
                unsigned char nosize
              );
   
};

//��ӱ�洢�ļ����
class CAddTableFile: public CMyFile
{
public:
    CAddTableFile(const char *pszfile = "addtable.txt");

};

//ɾ����洢�ļ����
class CDelTableFile: public CMyFile
{
public:
    CDelTableFile(const char *pszfile = "deltable.txt");
};

#endif

