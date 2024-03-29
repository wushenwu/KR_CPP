#ifndef CMYSTRING_H_A5D8D5F8_B1DC_46d7_9E79_C4E8EAF111A7

#define CMYSTRING_H_A5D8D5F8_B1DC_46d7_9E79_C4E8EAF111A7

/************************************************************************/
/* 4.实现MyString有成员函数MyString* stringcat(MyString *pString)即为一般的字符串连接,
类和它的子类MyNumString(顾名思义，里面只能是数字串),
其中它的连接函数要用加法加起来，比如23,和34的话，它们连接起来就是57了，不是2334。
请编程并实现它们的多态性                                                                     */
/************************************************************************/

#define REFCOUNT

class CMyString
{
public:
    CMyString();
    CMyString(const char *psz);
    CMyString(const CMyString &str);
    CMyString(int nsize);   //申请nsize字节的空间

    virtual ~CMyString();           //virtual, 这些都可能需要被派生类所进行覆盖

public:
    //构造字符串
    virtual void SetString(const char *psz);        //virtual
    virtual void SetString(const CMyString &str);   //virtual

    inline const char *GetString(void) const;   //
    
    inline size_t GetLen(void)  const;

    virtual const char *StringCopy(const char *psz);        //virtual
    virtual const char *StringCopy(const CMyString &str);   //virtual

    virtual const char *StringCat(const char *psz);         //virtual
    virtual const char *StringCat(const CMyString &str);    //virtual
    virtual CMyString *StringCat(CMyString *pstr);          //virtual

    /*
    Function: 字符串比较
    Return : true 该字符串与psz相等  false 不相等
    */
    bool StringCompare(const char *psz) const;
    bool StringCompare(const CMyString &str) const;

    /*
    Function: 查找一个字符
    Return : 如果存在，则返回指向该位置的指针，否则返回NULL。
             其中StringChr返回的是第一次出现的位置，而StringRchr返回的是最后一次出现的位置
    */
    const char *StringChr(int ch) const;
    const char *StringRchr(int ch) const;

    /*
    Function: 查找任何几个字符, 查找任何一组字符第1次在字符串中出现的位置
    Return: 返回一个指向第一个匹配group中任何一个字符的位置， 如果未找到，则返回NULL
    */
    const char *StringPbrk(const char *pszgroup) const;
    const char *StringPbrk(const CMyString &str) const;


    /*
    Function: 查找子串
    Return: 在该字符串中查找psz第一次出现的起始位置，并返回一个指向该位置的指针。
            如果没有找到，则返回NULL
    */
    const char *StringStr(const char *psz) const;
    const char *StringStr(const CMyString &str) const;

    //对字符串进行大小写转换
    void StringToUpper(void);
    void StringToLower(void);


//private:
protected:
    void StringInit(void);

#ifdef REFCOUNT
    //引用计数相关
    void AddRef(void);
    void Release(void);
#endif

//private:
protected:
    char *m_psz;        //字符串存储地址
    size_t m_nlen;      //字符串实际占用长度
    size_t m_nspace;    //所申请空间的总长度

#ifdef REFCOUNT
    int *m_prefcount;   //引用计数
#endif

};

inline const char *
CMyString::GetString(void) const
{
    return m_psz;
}

inline size_t 
CMyString::GetLen(void) const
{
    return m_nlen;
}

//////////////////////////////////////////////////////////////////////////
//以下为CMyNumString
//////////////////////////////////////////////////////////////////////////
class CMyNumString: public CMyString
{
public:
    CMyNumString();
    CMyNumString(const char *psz);
    CMyNumString(const CMyNumString &str);

    ~CMyNumString();   
                          

    //////////////////////////////////////////////////////////////////////////
    //需要与基类中的构成覆盖，方能构成多态
    //////////////////////////////////////////////////////////////////////////
    /*
    Function: 设置数字串
    注意    : 如果传入的字符串为数字串，则进行设置
               否则，不予设置，保持原样
    */
    void SetString(const char *psz);        
    void SetString(const CMyString &str);

    /*
    Function: 针对数字串的拷贝
    Return  : 如果传入的字符串是数字串，则进行拷贝，将原字符串覆盖，返回新的字符串
               否则，原字符串保持不变，返回原始字符串。
    */
    const char *StringCopy(const char *psz);       
    const char *StringCopy(const CMyString &str); 
    
    /*
    Function: 针对数字串的连接
    Return  : 如果传入的字符串是数字串，则进行数字串的加法（数学意义上的加法），并返回修改后的新串
                否则，原数字串保持不变，并返回。
    */
    const char *StringCat(const char *psz);
    const char *StringCat(const CMyString &str);
    CMyString *StringCat(CMyString *pstr);

private:
    /*
    Function:检查字符串psz是否均为数字
    Return  : true 全为数字， false 否
    */
    bool CheckNum(const char *psz) const;
    
};


#endif