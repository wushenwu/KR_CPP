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
    Function: 设置文件， 比如学生信息存储文件，添加表、删除表存储文件
    */
    void SetFile(const char *pszfile);
    const char *GetFile(void) const;

    /*
    Function: 从m_filename中offset地址读取size字节到buf中
    
    Return : SUCCESS 成功读取， FAILED 失败
    */
    int ReadData(void *pbuf, unsigned long offset, unsigned char size) const;

    /*
    Function: 向m_filename文件中追加大小为size的buf
      
    Return  : SUCCESS 成功写入  FAILED 失败
    */
    int AppendData(void *pbuf, unsigned char size);

    /*
    Function: 将m_filename文件清空。
    
    Return  : SUCCESS 成功清空  FAILED 失败
    */
    int ResetData(void);

    /*
    Function: 将m_filename文件中offset地址的数据改写为大小为size字节的buf.
    
    Return : SUCCESS 成功修改， FAILED 失败
    */
    int ModifyData(void *pbuf, unsigned long offset, unsigned char size) const;

    /*
    Function: 检测文件是否存在， 不存在则试图新建。    
    Param   : pszfile 文件名称 （MAX_INPUT限制）
    Return  : SUCCESS 确认存在或者新建成功
               NOT_EXIST 不存在（新建失败）
    
    Remark  : 可以用于init阶段，检测信息存储文件，添加表文件，删除表文件
    */
    static int CheckFile(const char *pszfile);

    /*
    Function: 文件拷贝（每4字节进行）
    Param   : 
    Return  : SUCCESS 成功拷贝， FAILED 拷贝失败
    */
    static int FileCopy(const char *pfilesrc, const char *pfiledst);
    
protected:
    CMyString m_filename;
    
};

//学生信息存储文件相关
class CInfoFile: public CMyFile       
{
public:
    CInfoFile(const char *pszfile = "info.txt");

    int
    ReadData(tag_student *pstudent, char *pszname, char *pszno,  //接收读取的学生各信息
             tag_addrecord *paddrecord                      //要读取的学生信息
              ) const;

    int
    AppendData(tag_student *pstudent, char *pszname, char *pszno,   //学生信息
               unsigned long offset,                             //文件地址
               unsigned char namesize,                          //学生姓名占用空间大小，
               unsigned char nosize);                           // 

    /*
    Function: 将student, szname, szno指定的学生信息存放至文件中
    Param   : tag_student *student, char *szname, char *szno,   //学生信息
            unsigned long start,                              //传入传出的文件地址
            unsigned char namesize ,                          //学生姓名占用空间大小
            unsigned char nosize                              //学生学号占用空间大小

    Return  : SUCCESS 成功存储  FAILED  存储失败
    */
    int
    ModifyData(tag_student *pstudent, char *szname, char *szno,   
                unsigned long offset,                              
                unsigned char namesize ,                          
                unsigned char nosize
              );
   
};

//添加表存储文件相关
class CAddTableFile: public CMyFile
{
public:
    CAddTableFile(const char *pszfile = "addtable.txt");

};

//删除表存储文件相关
class CDelTableFile: public CMyFile
{
public:
    CDelTableFile(const char *pszfile = "deltable.txt");
};

#endif

