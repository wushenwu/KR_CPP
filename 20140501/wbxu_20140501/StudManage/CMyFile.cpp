#include <stdio.h>
#include <string.h>
#include "CMyFile.h"
#include "MyCopy.h"


//////////////////////////////////////////////////////////////////////////
//CMyFile���
//////////////////////////////////////////////////////////////////////////
void 
CMyFile::SetFile(const char *pszfile)
{
   m_filename.SetString(pszfile);
}

const char *
CMyFile::GetFile(void) const
{
    return m_filename.GetString();
}

int
CMyFile::CheckFile(const char *pszfile)
{
    FILE *fp   = NULL;
    int result = SUCCESS;
    
    fp = fopen(pszfile, "rb+");
    if (NULL == fp)
    {
        //try to create
        fp = fopen(pszfile, "wb+");
        if (NULL == fp)
        {
            result = NOT_EXIST;
        }
    }
    
    if (fp)
    {
        fclose(fp);
        fp = NULL;
    }
    
    return result;
}

int 
CMyFile::FileCopy(const char *pfilesrc, const char *pfiledst)
{
    int result = SUCCESS;
    
    result = mycopy_v2(pfilesrc, pfiledst);
    
    return result;
}

int
CMyFile::ReadData(void *pbuf,             
                unsigned long offset,    
                unsigned char size
                ) const
                        
{
    FILE *fp   = NULL;
    int result = SUCCESS;    
    
    fp = fopen(m_filename.GetString(), "rb");
    if (NULL == fp)
    {
        result = FAILED;
        return result;
    }
    
    fseek(fp, offset, SEEK_SET);
    if (ferror(fp))
    {
        perror("Fetch1info_whole fseek error");
        
        result = FAILED;
        goto FETCH_WHOLE_ERROR;
    }
    
    fread(pbuf, size, 1, fp);
    if (ferror(fp))
    {
        perror("Fetch1info_whole fread error");
        
        result = FAILED;
        goto FETCH_WHOLE_ERROR;
    }
    
FETCH_WHOLE_ERROR:
    if (fp)
    {
        fclose(fp);
        fp = NULL;
    }
    
    return result;
}

/*
Function: ��pszfile��д���СΪsize�ֽڵ�pbuf. ���������޹أ�

Param   : void *pbuf ��Ҫд�����Ϣ
          initflg  1 ��ʾ����д�룬�Ὣ֮ǰ��������ա� 0 ������ӡ�
  
Return  : SUCCESS �ɹ�д��  FAILED ʧ��
*/
static int
storerecord(const char *pszfile, void *pbuf, unsigned char size, int initflg)
{
    FILE *fp = NULL;
    int result = SUCCESS;
    
    if (1 == initflg)
    {
        fp = fopen(pszfile, "wb");  //reset the file
        goto STORERECORD_ERROR;
    }
    else
    {
        fp = fopen(pszfile, "rb+");
    }
    
    if (NULL == fp)
    {
        perror("storerecord fopen error");
        result = FAILED;
        return result;
    }
    
    result = fseek(fp, 0, SEEK_END);
    if (0 != result)
    {
        perror("storerecord fseek error");
        result = FAILED;
        goto STORERECORD_ERROR;
    }
    
    result = fwrite(pbuf, size, 1, fp);
    if (ferror(fp))
    {
        perror("storerecord fwrite error");
        result = FAILED;
        goto STORERECORD_ERROR;
    }
    
STORERECORD_ERROR:
    if (fp)
    {
        fclose(fp);
        fp = NULL;
    }
    
    return result;
}

int 
CMyFile::AppendData(void *pbuf, unsigned char size)
{
    //׷������
    int initflg = 0;    
    return storerecord(m_filename.GetString(),
                        pbuf,
                        size,
                        initflg   
                        );
}

int 
CMyFile::ResetData(void)
{
    //����д�룬�������
    int initflg = 1; 
    return storerecord(m_filename.GetString(),
                        "",
                        0,
                        initflg       
                        );
}

int 
CMyFile::ModifyData(void *pbuf, unsigned long offset, unsigned char size) const
{
    FILE *fp    = NULL;
    int result  = SUCCESS;
    
    fp = fopen(m_filename.GetString(), "rb+");
    if (NULL == fp)
    {
        result = FAILED;
        return result;
    }
    
    fseek(fp, offset, SEEK_SET);    
    if (ferror(fp))
    {
        perror("StoreInfo_whole fseek error");
        
        result = FAILED;
        goto STOREINFO_WHOLE_ERROR;
    }
    
    fwrite(pbuf, size, 1, fp);
    if (ferror(fp))
    {
        perror("StoreInfo_whole fwrite error");
        
        result = FAILED;
        goto STOREINFO_WHOLE_ERROR;
    }
    
STOREINFO_WHOLE_ERROR:
    if (fp)
    {
        fclose(fp);
        fp = NULL;
    }
    
    return result;
}

//////////////////////////////////////////////////////////////////////////
//CInfoFile���
//////////////////////////////////////////////////////////////////////////
CInfoFile::CInfoFile(const char *pszfile)
{
    SetFile(pszfile);
}

int
CInfoFile::ReadData(tag_student *pstudent, char *pszname, char *pszno,  
                    tag_addrecord *paddrecord                        
                    ) const
{
    char pbuf[MAX_INPUT * 2] = {0};
    int nresult = CMyFile::ReadData(pbuf,
                      paddrecord->ulstart,
                      paddrecord->uchsize);

    if (FAILED == nresult)
    {
        return nresult;
    }

    unsigned char uchsize    = 0;
    unsigned char uchnamesize = 0;
    unsigned char uchnosize   = 0;
    
    uchsize     = paddrecord->uchsize;
    uchnamesize = paddrecord->uchnamesize;
    uchnosize   = uchsize - uchnamesize - sizeof(tag_student);

    memcpy(pstudent, pbuf, sizeof(tag_student));
    memcpy(pszname, pbuf + sizeof(tag_student), uchnamesize);
    memcpy(pszno, pbuf + sizeof(tag_student) + uchnamesize, uchnosize);

    return SUCCESS;    
}


int
CInfoFile::AppendData(tag_student *pstudent, char *pszname, char *pszno,   //ѧ����Ϣ
          unsigned long offset,                                         //�ļ���ַ
          unsigned char namesize,                                       //ѧ������ռ�ÿռ��С��
          unsigned char nosize                                          // 
          )
{
    char buf[MAX_INPUT * 2] = {0};
    memcpy(buf, pstudent, sizeof(tag_student));
    memcpy(buf + sizeof(tag_student), pszname, namesize);
    memcpy(buf + sizeof(tag_student) + namesize, pszno, nosize);
    
    return CMyFile::ModifyData(buf, offset, sizeof(tag_student) + namesize + nosize);
   
}

int
CInfoFile::ModifyData(tag_student *pstudent, char *szname, char *szno,   
           unsigned long offset,                              
           unsigned char namesize,                          
           unsigned char nosize
              )
{
    char buf[MAX_INPUT * 2] = {0};
    memcpy(buf, pstudent, sizeof(tag_student));
    memcpy(buf + sizeof(tag_student), szname, namesize);
    memcpy(buf + sizeof(tag_student) + namesize, szno, nosize);

    return CMyFile::ModifyData(buf, offset, sizeof(tag_student) + namesize + nosize);
}

//////////////////////////////////////////////////////////////////////////
CAddTableFile::CAddTableFile(const char *pszfile)
{
    SetFile(pszfile);
}

CDelTableFile::CDelTableFile(const char *pszfile)
{
    SetFile(pszfile);
}

