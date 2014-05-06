#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include "CMyFile.h"
#include "CTable.h"

#define ADDR_RECORD(records, i, recordsize)   ((void *)((int)(records) + (i) * (recordsize)))

//////////////////////////////////////////////////////////////////////////
//CTable相关
//////////////////////////////////////////////////////////////////////////
CTable::CTable()
{
    m_nrecords = 0;
}

CTable::~CTable()
{
    m_nrecords = 0;
}

unsigned long 
CTable::GetRecordsNum(void) const
{
    return m_nrecords;
}

void 
CTable::SetRecordsNum(unsigned long num)
{
    m_nrecords = num;
}

int 
CTable::LoadTable(char **ppbuf, const char *psztablefile, size_t recordsize)
{
    FILE *fp   = NULL;
    long size  = 0;     //文件大小
    long count = 0;     //文件中记录的数目
    int result = SUCCESS;
    char *precord = NULL;

    //make sure exist
    result = CMyFile::CheckFile(psztablefile);
    if (NOT_EXIST == result)
    {
        return result;
    }

    //now load into memory
    fp = fopen(psztablefile, "rb");
    if (NULL == fp)
    {
        result = FAILED;
        return result;
    }

    fseek(fp, 0, SEEK_END);
    if (ferror(fp))
    {
        perror("loadtable fseek error");

        result = FAILED;
        goto LOAD_ERROR;
    }

    size = ftell(fp);
    if (ferror(fp))
    {
        perror("loadtable ftell error");

        result = FAILED;
        goto LOAD_ERROR;
    }

    if (size % recordsize)
    {
        result = FAILED;

        //all right to do like this? with ui in logic ?????
        //showinfo("loadtable: data is corrupted\r\n");
        goto LOAD_ERROR;
    }

    count = size / recordsize;
    precord = (char *)malloc(size);    //count * recordsize
    if (NULL == precord)
    {
        result = FAILED;

        //showinfo("loadtable: malloc failed\r\n");
        goto LOAD_ERROR;
    }

    fseek(fp, 0, SEEK_SET);
    if (ferror(fp))
    {
        perror("loadtable fseek to begin error");
        result = FAILED;
        goto LOAD_ERROR;
    }

    m_nrecords = count;
    *ppbuf = precord;
    fread(*ppbuf, size, 1, fp);
   
    if (ferror(fp))
    {
        perror("loadtable fread error");

        result = FAILED;
        goto LOAD_ERROR;
    }

LOAD_ERROR:
    if (fp)
    {
        fclose(fp);
        fp = NULL;
    } 

    return result;
}

int 
CTable::SaveTable(void *buf,
                  const char *psztablefile,
                  unsigned char recordsize
                  )
{
    char szfile_bak[MAX_INPUT] = {0};    
    sprintf(szfile_bak, "%s_bak", psztablefile);
    
    //backup file
    int result = SUCCESS;
    result = CMyFile::FileCopy(psztablefile, szfile_bak);
    if (FAILED == result)
    {
        //showinfo("backup addtablefile error");
        return result;
    }
    
    //clear the file
    result = CMyFile(psztablefile).ResetData();
    if (FAILED == result)
    {
        //showinfo("savetable storerecord add init error");
        return result;
    } 
    
    for (unsigned long i = 0; i < m_nrecords; i++)
    {
        result = CMyFile(psztablefile).AppendData((char *)buf + i * recordsize,
                                                  recordsize
                                                  );
        if (FAILED == result)
        {
            //showinfo("savetable storerecord add error");
            return result;
        }
    }
    
    return result;
}

void
CTable::InsertIntoTable(unsigned long *nrecords,         
                        void *records,                        
                        void *newrecord,                   
                        size_t recordsize,                   
                        int *index,                     
                        int (*compare)(void *, void *)          
                        )
                
{
    int i = 0;
    int j = 0;
    
    //find the proper position
    for (i = *nrecords; i >= 1; i--)
    {
        //i will be the insert point.
        if (0 > compare( //(void *)((int)records + (i-1) * recordsize),
            ADDR_RECORD(records, i-1, recordsize), 
            newrecord) 
            )                   
        {
            break;
        }
    }
    
    //now we need to move i, i+1, .. nrecords-1 to i+1, i+2,...nrecords
    for (j = *nrecords; j >= i + 1; j--)
    {
        memcpy(//(void *)((int)records + j * recordsize), 
            ADDR_RECORD(records, j, recordsize),
            //(void *)((int)records + (j-1) * recordsize),
            ADDR_RECORD(records, j - 1, recordsize),
            recordsize);      
    }
    
    //now insert this record to i
    memcpy(//(void *)((int)records + i * recordsize), 
        ADDR_RECORD(records, i, recordsize),
        newrecord, recordsize);
    
    //update data
    *index = i;
    *nrecords = *nrecords + 1;
}

void 
CTable::UpdateTable(void *precords,          
                 size_t recordsize,      
                 int index,              
                 void *newrecord         
                 )
{
    memcpy(ADDR_RECORD(precords, index, recordsize), //records[index],
           newrecord, recordsize);
}

void 
CTable::RemoveFromTable(unsigned long *pnrecords,     
                     void *precords,                      
                     size_t recordsize,                  
                     int index                          
                        )
{
    unsigned long i = 0;
    
    //move index+1, index+2, ..., nrecords-1 to index, index+1, ..., nrecords-2
    for (i = index; i < *pnrecords - 1; i++)
    {
        memcpy(ADDR_RECORD(precords, i, recordsize),
               ADDR_RECORD(precords, i+1, recordsize),
               recordsize);
    }
    
    memset(ADDR_RECORD(precords, *pnrecords-1, recordsize), //records[*nrecords - 1], 
            0, recordsize);
    
    *pnrecords = *pnrecords - 1;
}

//////////////////////////////////////////////////////////////////////////
//CAddTable相关
//////////////////////////////////////////////////////////////////////////

CAddTable::CAddTable()
{
    m_precords = NULL;
}

CAddTable::~CAddTable()
{
    if (m_precords != NULL)
    {
        free(m_precords);
        m_precords = NULL;
    }
}

tag_addrecord *
CAddTable::GetRecords(void) const
{
    return m_precords;
}

int 
CAddTable::LoadTable(const char *pszaddtablefile)
{
    char *ptmp = NULL;
    int nresult = CTable::LoadTable(&ptmp,
                                    pszaddtablefile,
                                    sizeof(tag_addrecord)
                                    );
    m_precords = (tag_addrecord *)ptmp;

    return nresult;
}

int
CAddTable::SaveTable(const char *pszaddtablefile)
{
    return CTable::SaveTable(m_precords,
                            pszaddtablefile,
                            sizeof(tag_addrecord)
                            );
}

int
compare_addrecord(void *record, void *addrecord)
{
    unsigned long x = 0, y = 0;
    
    x = ((tag_addrecord *)record)->ulstart;
    y = ((tag_addrecord *)addrecord)->ulstart;
    
    return x - y;
}

void
CAddTable::InsertIntoTable(tag_addrecord *paddrecord)
{
    size_t newsize = 0;
    int index      = 0;
    
    newsize = (m_nrecords + 1) * sizeof(tag_addrecord)// 增加1个records
               + sizeof(m_nrecords);                 //for m_nrecords
    
    
    m_precords = (tag_addrecord *)realloc(m_precords, newsize);
    
    if (NULL == m_precords)
    {
        //showinfo("Insertintoaddtable realloc error\r\n");
    }
    
    CTable::InsertIntoTable(&m_nrecords,
                            m_precords,
                            paddrecord,
                            sizeof(tag_addrecord),
                            &index,
                            compare_addrecord          //回调函数
                           );
}

void
CAddTable::UpdateTable(int index, tag_addrecord *paddrecord)
{
    CTable::UpdateTable(m_precords,
                        sizeof(tag_addrecord),
                        index,
                        paddrecord
                        );
}

void
CAddTable::RemoveFromTable(int index)
{
    size_t newsize = 0;
    
    CTable::RemoveFromTable(&m_nrecords,
                            m_precords,
                            sizeof(tag_addrecord),
                            index
                            );
    
    //table nrecords already updated,  -1
    newsize = sizeof(m_nrecords)
                + m_nrecords * sizeof(tag_addrecord);
    
    m_precords = (tag_addrecord *)realloc(m_precords,
                    newsize  
                 );
    
    if (NULL == m_precords)
    {
        //showinfo("Removefromaddtable realloc error\r\n");
    }
}

//////////////////////////////////////////////////////////////////////////
//CDelTable相关
//////////////////////////////////////////////////////////////////////////
CDelTable::CDelTable()
{
    m_precords = NULL;
}

CDelTable::~CDelTable()
{
    if (m_precords != NULL)
    {
        free(m_precords);
        m_precords = NULL;
    }
}

tag_delrecord *
CDelTable::GetRecords(void) const
{
    return m_precords;
}

int
CDelTable::LoadTable(const char *pszdeltablefile)
{
    char *ptmp = NULL;
    int nresult = CTable::LoadTable(&ptmp,
                                    pszdeltablefile,
                                    sizeof(tag_delrecord)
                                    );
    m_precords = (tag_delrecord *)ptmp;
    return nresult;
}

int
CDelTable::SaveTable(const char *pszdeltable)
{
    return CTable::SaveTable(m_precords,
                            pszdeltable,
                            sizeof(tag_delrecord)
                            );
}

void
CDelTable::Reorganize(unsigned long index)
{
    unsigned long indexpre = 0;
    unsigned char sizepre  = 0;
    unsigned long startpre = 0;
    
    unsigned long indexaft = 0; 
    unsigned char  sizeaft  = 0;
    unsigned long  startaft = 0;
    
    unsigned char size     = 0;
    unsigned long start    = 0;
    
    tag_delrecord delrecord;
    CDelTable *pdeltable = NULL;
    
    size  = m_precords[index].uchsize;
    start = m_precords[index].ulstart;   
    
    //aft
    if ((index + 1) != m_nrecords)
    {
        indexaft = index + 1;
        sizeaft  = m_precords[indexaft].uchsize;
        startaft = m_precords[indexaft].ulstart;
        
        if (startaft == start + size)
        {
            delrecord.uchsize  = size + sizeaft;
            delrecord.ulstart  = start;
            UpdateTable(index, &delrecord);
            RemoveFromTable(indexaft);            
            //showinfo("reorganize space aft happens\r\n");
        }
    }//end for aft
    
    //pre
    if (index != 0)
    {
        indexpre = index - 1;  
        sizepre  = m_precords[indexpre].uchsize;
        startpre = m_precords[indexpre].ulstart;
        
        if (start == startpre + sizepre)
        {
            //take care, may size already updated, we need to use g_del_table[index]
            delrecord.uchsize  = sizepre +m_precords[index].uchsize;
            delrecord.ulstart  = startpre;
            UpdateTable(indexpre, &delrecord);
            RemoveFromTable(index);
            //showinfo("reorganize space pre happens\r\n");
        }   
    }//end for pre 
}

int
compare_delrecord(void *record, void *delrecord)
{
    unsigned long x = 0, y = 0;
    
    x = ((tag_delrecord *)record)->ulstart;
    y = ((tag_delrecord *)delrecord)->ulstart;
    
    return x - y;
}

void 
CDelTable::InserIntoTable(tag_delrecord *pdelrecord)
{
    size_t newsize = 0;
    int index      = 0;
    
    newsize = (m_nrecords + 1) * sizeof(tag_delrecord) //增加1各records
                + sizeof(m_nrecords);        //for m_nrecords
    
    m_precords = (tag_delrecord *)realloc(m_precords, newsize);
    
    if (NULL == m_precords)
    {
        //sth wrong
        //showinfo("Insertintodeltable realloc error\r\n");
    }
    
    CTable::InsertIntoTable(&m_nrecords,
                            m_precords,
                            pdelrecord,
                            sizeof(tag_delrecord),
                            &index,
                            compare_delrecord
                            );
    
    Reorganize(index);
}

void
CDelTable::UpdateTable(int index, tag_delrecord *pdelrecord)
{
    CTable::UpdateTable(m_precords,
                        sizeof(tag_delrecord),
                        index,
                        pdelrecord
                        );
}

void
CDelTable::RemoveFromTable(int index)
{
    size_t newsize = 0;
    
    CTable::RemoveFromTable(&m_nrecords,
                            m_precords,
                            sizeof(tag_delrecord),
                            index
                           );
    
    //deltable nrecords already updated, -1
    newsize = sizeof(m_nrecords)
                + m_nrecords * sizeof(tag_delrecord);
    
    m_precords = (tag_delrecord *)realloc(m_precords,
                                            newsize
                                         );
    if (NULL == m_precords)
    {
        //showinfo("Removefromdeltable realloc error\r\n");
    }
}

