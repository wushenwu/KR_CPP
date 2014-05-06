#ifndef CTABLE_H_F586A194_99ED_4523_807D_8D3B3822AEE0

#define CTABLE_H_F586A194_99ED_4523_807D_8D3B3822AEE0

#include "Struct.h"
#include "Const.h"

//表基类
class CTable
{
public:
    CTable();
    ~CTable();

    unsigned long GetRecordsNum(void) const;
    void SetRecordsNum(unsigned long num);

protected:
    /*
    Function: 将psztablefile所指示文件中的所有记录读取到buf中
    Param   : buf 用于接收读取到的所有记录
              size 为每条记录的大小
    Return  : SUCCESS 加载成功或者新建成功
              NOT_EXIST 相应文件不存在
               FAILED  加载失败
    */
    int LoadTable(char  **ppbuf, const char *psztablefile, size_t recordsize);

    /*
    Function: 将表文件psztablefile进行备份，
              将内存中buf所指示的表写入到表文件psztablefile中, 每条记录大小为recordsize

    Return : SUCCESS 成功处理 FAILED 失败
    */
    int SaveTable(void *buf,
                  const char *psztablefile,
                  unsigned char recordsize
                  );


    /*
    Function: 与类型无关的插入表操作

    Param   : IN OUT unsigned long *nrecords,         //传入传出的table中record的总数
                    void *records,                    //table中record的起始地址
                    size_t recordsize,                //record的大小 
              IN OUT int *index,                      //接收插入的位置
                int (*compare)(void *, void *)        //比较记录大小的回调函数
    */
    void InsertIntoTable(unsigned long *nrecords,         
                        void *records,                         
                        void *newrecord,                       
                        size_t recordsize,
                        int *index,
                        int (*compare)(void *, void *)     
                        );

    /*
    Function: 与类型无关的表中记录更新操作（整体记录更新）
    Param   :  void *records,          //表中records起始地址
                size_t recordsize,      //表中record的大小
                int index,              //要更新的record
                void *newrecord         //新内容
    */
    void UpdateTable(void *precords,          
                    size_t recordsize,      
                    int index,              
                     void *pnewrecord         
                    );

    /*
    Function: 与类型无关的表数据删除操作
    Param   : IN OUT unsigned long *nrecords,     //传入传出的table中record的总数
              void *records,                      //table中records的起始地址
              size_t recordsize,                  //record的大小
              int index                           //要删除的record在table中的下标
    */
    void RemoveFromTable(unsigned long *pnrecords,     
                        void *precords,                      
                        size_t recordsize,                  
                        int index                          
                        );


protected:
    unsigned long m_nrecords;
};

//添加表
class CAddTable: public CTable
{
public:
    CAddTable();
    ~CAddTable();

    tag_addrecord *GetRecords(void) const;

    /*
    Function: 从pszaddtablefile中加载添加表到内存中
    Return  : SUCCESS 加载成功或者新建成功
               NOT_EXIST 相应文件不存在
               FAILED  加载失败
    */
    int LoadTable(const char *pszaddtablefile);

    /*
    Function: 备份添加表，将内存中的添加表写入到添加表文件pszaddtable中
    
    Return  : SUCCESS 成功处理 FAILED 失败
    */
    int SaveTable(const char *pszaddtablefile);

    /*
    Function: 将paddrecord代表的(start, size, namesize)记录有序的插入到添加表中
                start作为keywords　    　　        　　        
    */
    void
    InsertIntoTable(tag_addrecord *paddrecord);

    /*
    Function: 将添加表中相应index所标识的记录更新为新传入的addrecord。
    */
    void
    UpdateTable(int index, tag_addrecord *paddrecord);

    /*
    Function: 将index 所标识的记录从添加表中删除, 并保证表的有序性。
    */
    void
    RemoveFromTable(int index);

protected:
    tag_addrecord *m_precords;  //变长处理，根据需要实时申请
};

//删除表
class CDelTable: public CTable
{
public:
    CDelTable();
    ~CDelTable();

    tag_delrecord* GetRecords(void) const;
    /*
    Function: 从pszdeltablefile中加载添加表到内存中
    Return  : SUCCESS 加载成功或者新建成功
              NOT_EXIST 相应文件不存在
              FAILED  加载失败
    */
    int LoadTable(const char *pszdeltablefile);

    /*
    Function: 备份删除表，将内存中的删除表写入到删除表文件pszdeltablefile中

    Return : SUCCESS 成功处理 FAILED 失败
    */
    int SaveTable(const char *pszdeltable);


    /*
    Function: 将pdelrecord代表的(start, size)记录有序的插入到**ppdeltable中, 
             并对g_del_table指示连续空闲空间进行整合
    
    Effect  : 更新g_del_table, 对g_del_table指示的连续空闲空间进行整合，进行再分配
             注意，因为我们的g_del_table是按需增长的，所以需要realloc, 
             注意参数的传入
    */
    void InserIntoTable(tag_delrecord *pdelrecord);

    /*
    Function: 考虑g_del_table中，index记录与其前驱、后继是否为连续的空闲空间，进行整合，
            以获取更大的空闲空间，便于后续再分配
    Param   : index
    Effect  : 可能调用removefromtable，
    Caller: this function can only be called by insertintodeltable
    */
    void
    Reorganize(unsigned long index);

    /*
    Function: 将删除表中相应index所标识的记录更新为新传入的pdelrecord。
    */
    void
    UpdateTable(int index, tag_delrecord *pdelrecord);

    /*
    Function: 将index 所标识的记录从表中删除, 并保证有序性。
    */
    void
    RemoveFromTable(int index);
      
protected:
    tag_delrecord *m_precords;   //变长处理，根据需要实时申请
};

#endif
