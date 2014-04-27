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
    Function: ����������
    Return  : true �Ϸ������ڣ� false �Ƿ�������
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
    Function: ���������ַ���
    Param   : pszdate���ڽ��������ַ����� chΪ�ָ��
    */
    void GetDate(char **pszdate, char ch = '-') const;

    /*
    Function: �ж��Ƿ�Ϸ�������
    Return  : true �Ϸ��� false �Ƿ�
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
