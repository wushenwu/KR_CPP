#ifndef CMYDATE_H_2133FDD5_03ED_4609_9CF1_7A5A2141120D

#define CMYDATE_H_2133FDD5_03ED_4609_9CF1_7A5A2141120D

class CMyDate
{
public:
    CMyDate();
    CMyDate(int nyear, int nmonth, int nday);
    CMyDate(const CMyDate &date);

    ~CMyDate();

public:
    /*
    Function: 设置年月日
    Return  : true 合法的日期， false 非法的日期
    */
    bool SetDate(const CMyDate &date);
    bool SetDate(int nyear, int nmonth, int nday);

    bool SetYear(int nyear);
    bool SetMonth(int nmonth);
    bool SetDay(int nday);

    int GetYear(void) const;
    int GetMonth(void) const;
    int GetDay(void) const;

    /*
    Function: 返回日期字符串
    Param   : pszdate用于接收日期字符串， ch为分割符
    */
    void GetDate(char **pszdate, char ch = '-') const;

    /*
    Function: 判断是否合法的日期
    Return  : true 合法， false 非法
    */
    bool isleapyear(int nyear) const;
    bool isvalidyear(int nyear) const;
    bool isvalidmonth(int nmonth) const;
    bool isvalidday(int nyear, int nmonth, int nday) const;
  
private:
    bool init(int nyear, int nmonth, int nday); 

private:
    int m_nyear;
    int m_nmonth;
    int m_nday;
};


#endif
