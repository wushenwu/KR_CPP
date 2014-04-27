#include <iostream>
using namespace std;

#include "studinfo.h"

/*
    对CStudent(const char *pszname, 
            int nyear, int nmonth, int nday,
            int id)

    进行测试
*/
void
test_method1()
{
    int nresult;
    int nyear = 1999;
    int nmonth = 1;
    int nday = 1;
    int i = 0;
    
    while(1)
    {
        CStudent tmp("method1", 
                    nyear++, nmonth++, nday++,
                    i++);    

        nresult = AddStudent(tmp);            
        if (NO_SPACE == nresult)
        {
            cout << "           Method 1, No more space, quit now" << endl;
            break;
        }
    }
    
    ShowStudent();
}

/*
    对
    CStudent(const CMyString &strname, const CMyDate &date, const CStudID &id)  //有参构造
            : m_strname(strname), m_birthday(date), m_id(id)

    进行测试
*/
void
test_method2()
{
    int nresult;
    int nyear = 1999;
    int nmonth = 1;
    int nday = 1;
    int i = 0;
    
    while(1)
    {
        CStudent tmp(                                   //利用无名对象处理
                    CMyString("method2"),
                    CMyDate(nyear++, nmonth++, nday++),
                    CStudID(i++)
                    );    
        
        nresult = AddStudent(tmp);            
        if (NO_SPACE == nresult)
        {
            cout << "           Method 2. No more space, quit now" << endl;
            break;
        }
    }
    
    ShowStudent();
}

/*
  对  CStudent(const CStudent &stud)      //拷贝构造
            : m_strname(stud.m_strname),
            m_birthday(stud.m_birthday),
            m_id(stud.m_id)
    进行测试
*/
void
test_method3(void)
{
    int nresult;
    int nyear = 1999;
    int nmonth = 1;
    int nday = 1;
    int i = 0;
    
    while(1)
    {
        CStudent t(                                   //利用无名对象处理
            CMyString("method2"),
            CMyDate(nyear++, nmonth++, nday++),
            CStudID(i++)
            );   
        
        CStudent tmp(t);
        
        nresult = AddStudent(tmp);            
        if (NO_SPACE == nresult)
        {
            cout << "           Method 3. No more space, quit now" << endl;
            break;
        }
    }
    
    ShowStudent();

}


void
test_method_input()
{
    int nresult;
    char szname[64] = {0};
    int no;
    int nyear, nmonth, nday;
    
    while (1)
    {
        cout << "Please enter student name, no and birthday: " << endl;
        cin >> szname;
        cin >> no;
        cin >> nyear >> nmonth >> nday;
        
        CStudent tmp(szname, nyear, nmonth, nday, no);
        nresult = AddStudent(tmp);
        
        if (NO_SPACE == nresult)
        {
            cout << "                           No more space" << endl;
            break;
        }
        
        if (REPEATED == nresult)
        {
            cout << "                           Student No already exist, enter again" << endl;
            continue;
        }
    }//end for while (1)  input
    
    ShowStudent();
}

int
main(void)
{
    int nNumber = 0;
    cout << "Please enter number of students you want to store: " << endl;
    cin >> nNumber;
    
    int nresult = SetStudNumber(nNumber);
    if (NO_SPACE == nresult)
    {
        cout << "New Heap Space for these students failed " << endl;
        return -1;
    }
    
    //test_method1();

    //test_method2();
    
    test_method3();
    
    FreeSpace();

    return 0;
}
