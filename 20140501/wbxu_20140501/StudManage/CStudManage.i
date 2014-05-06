#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.cpp"
#line 1 "e:\\program\\vc98\\include\\stdio.h"















#pragma once
#line 18 "e:\\program\\vc98\\include\\stdio.h"






#line 25 "e:\\program\\vc98\\include\\stdio.h"







#pragma pack(push,8)
#line 34 "e:\\program\\vc98\\include\\stdio.h"


extern "C" {
#line 38 "e:\\program\\vc98\\include\\stdio.h"










#line 49 "e:\\program\\vc98\\include\\stdio.h"
#line 50 "e:\\program\\vc98\\include\\stdio.h"






#line 57 "e:\\program\\vc98\\include\\stdio.h"








#line 66 "e:\\program\\vc98\\include\\stdio.h"
#line 67 "e:\\program\\vc98\\include\\stdio.h"



typedef unsigned int size_t;

#line 73 "e:\\program\\vc98\\include\\stdio.h"




typedef unsigned short wchar_t;

#line 80 "e:\\program\\vc98\\include\\stdio.h"



typedef wchar_t wint_t;
typedef wchar_t wctype_t;

#line 87 "e:\\program\\vc98\\include\\stdio.h"
#line 88 "e:\\program\\vc98\\include\\stdio.h"









typedef char *  va_list;
#line 99 "e:\\program\\vc98\\include\\stdio.h"

#line 101 "e:\\program\\vc98\\include\\stdio.h"






#line 108 "e:\\program\\vc98\\include\\stdio.h"

#line 110 "e:\\program\\vc98\\include\\stdio.h"






























#line 141 "e:\\program\\vc98\\include\\stdio.h"





struct _iobuf {
        char *_ptr;
        int   _cnt;
        char *_base;
        int   _flag;
        int   _file;
        int   _charbuf;
        int   _bufsiz;
        char *_tmpfname;
        };
typedef struct _iobuf FILE;

#line 159 "e:\\program\\vc98\\include\\stdio.h"












#line 172 "e:\\program\\vc98\\include\\stdio.h"












#line 185 "e:\\program\\vc98\\include\\stdio.h"




























#line 214 "e:\\program\\vc98\\include\\stdio.h"
#line 215 "e:\\program\\vc98\\include\\stdio.h"





 extern FILE _iob[];
#line 222 "e:\\program\\vc98\\include\\stdio.h"









#line 232 "e:\\program\\vc98\\include\\stdio.h"


typedef __int64 fpos_t;







#line 243 "e:\\program\\vc98\\include\\stdio.h"
#line 244 "e:\\program\\vc98\\include\\stdio.h"


#line 247 "e:\\program\\vc98\\include\\stdio.h"




























 int __cdecl _filbuf(FILE *);
 int __cdecl _flsbuf(int, FILE *);




 FILE * __cdecl _fsopen(const char *, const char *, int);
#line 283 "e:\\program\\vc98\\include\\stdio.h"

 void __cdecl clearerr(FILE *);
 int __cdecl fclose(FILE *);
 int __cdecl _fcloseall(void);




 FILE * __cdecl _fdopen(int, const char *);
#line 293 "e:\\program\\vc98\\include\\stdio.h"

 int __cdecl feof(FILE *);
 int __cdecl ferror(FILE *);
 int __cdecl fflush(FILE *);
 int __cdecl fgetc(FILE *);
 int __cdecl _fgetchar(void);
 int __cdecl fgetpos(FILE *, fpos_t *);
 char * __cdecl fgets(char *, int, FILE *);




 int __cdecl _fileno(FILE *);
#line 307 "e:\\program\\vc98\\include\\stdio.h"

 int __cdecl _flushall(void);
 FILE * __cdecl fopen(const char *, const char *);
 int __cdecl fprintf(FILE *, const char *, ...);
 int __cdecl fputc(int, FILE *);
 int __cdecl _fputchar(int);
 int __cdecl fputs(const char *, FILE *);
 size_t __cdecl fread(void *, size_t, size_t, FILE *);
 FILE * __cdecl freopen(const char *, const char *, FILE *);
 int __cdecl fscanf(FILE *, const char *, ...);
 int __cdecl fsetpos(FILE *, const fpos_t *);
 int __cdecl fseek(FILE *, long, int);
 long __cdecl ftell(FILE *);
 size_t __cdecl fwrite(const void *, size_t, size_t, FILE *);
 int __cdecl getc(FILE *);
 int __cdecl getchar(void);
 int __cdecl _getmaxstdio(void);
 char * __cdecl gets(char *);
 int __cdecl _getw(FILE *);
 void __cdecl perror(const char *);
 int __cdecl _pclose(FILE *);
 FILE * __cdecl _popen(const char *, const char *);
 int __cdecl printf(const char *, ...);
 int __cdecl putc(int, FILE *);
 int __cdecl putchar(int);
 int __cdecl puts(const char *);
 int __cdecl _putw(int, FILE *);
 int __cdecl remove(const char *);
 int __cdecl rename(const char *, const char *);
 void __cdecl rewind(FILE *);
 int __cdecl _rmtmp(void);
 int __cdecl scanf(const char *, ...);
 void __cdecl setbuf(FILE *, char *);
 int __cdecl _setmaxstdio(int);
 int __cdecl setvbuf(FILE *, char *, int, size_t);
 int __cdecl _snprintf(char *, size_t, const char *, ...);
 int __cdecl sprintf(char *, const char *, ...);
 int __cdecl sscanf(const char *, const char *, ...);
 char * __cdecl _tempnam(const char *, const char *);
 FILE * __cdecl tmpfile(void);
 char * __cdecl tmpnam(char *);
 int __cdecl ungetc(int, FILE *);
 int __cdecl _unlink(const char *);
 int __cdecl vfprintf(FILE *, const char *, va_list);
 int __cdecl vprintf(const char *, va_list);
 int __cdecl _vsnprintf(char *, size_t, const char *, va_list);
 int __cdecl vsprintf(char *, const char *, va_list);








#line 363 "e:\\program\\vc98\\include\\stdio.h"




 FILE * __cdecl _wfsopen(const wchar_t *, const wchar_t *, int);
#line 369 "e:\\program\\vc98\\include\\stdio.h"

 wint_t __cdecl fgetwc(FILE *);
 wint_t __cdecl _fgetwchar(void);
 wint_t __cdecl fputwc(wint_t, FILE *);
 wint_t __cdecl _fputwchar(wint_t);
 wint_t __cdecl getwc(FILE *);
 wint_t __cdecl getwchar(void);
 wint_t __cdecl putwc(wint_t, FILE *);
 wint_t __cdecl putwchar(wint_t);
 wint_t __cdecl ungetwc(wint_t, FILE *);

 wchar_t * __cdecl fgetws(wchar_t *, int, FILE *);
 int __cdecl fputws(const wchar_t *, FILE *);
 wchar_t * __cdecl _getws(wchar_t *);
 int __cdecl _putws(const wchar_t *);

 int __cdecl fwprintf(FILE *, const wchar_t *, ...);
 int __cdecl wprintf(const wchar_t *, ...);
 int __cdecl _snwprintf(wchar_t *, size_t, const wchar_t *, ...);
 int __cdecl swprintf(wchar_t *, const wchar_t *, ...);
 int __cdecl vfwprintf(FILE *, const wchar_t *, va_list);
 int __cdecl vwprintf(const wchar_t *, va_list);
 int __cdecl _vsnwprintf(wchar_t *, size_t, const wchar_t *, va_list);
 int __cdecl vswprintf(wchar_t *, const wchar_t *, va_list);
 int __cdecl fwscanf(FILE *, const wchar_t *, ...);
 int __cdecl swscanf(const wchar_t *, const wchar_t *, ...);
 int __cdecl wscanf(const wchar_t *, ...);






 FILE * __cdecl _wfdopen(int, const wchar_t *);
 FILE * __cdecl _wfopen(const wchar_t *, const wchar_t *);
 FILE * __cdecl _wfreopen(const wchar_t *, const wchar_t *, FILE *);
 void __cdecl _wperror(const wchar_t *);
 FILE * __cdecl _wpopen(const wchar_t *, const wchar_t *);
 int __cdecl _wremove(const wchar_t *);
 wchar_t * __cdecl _wtempnam(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl _wtmpnam(wchar_t *);



#line 414 "e:\\program\\vc98\\include\\stdio.h"
#line 415 "e:\\program\\vc98\\include\\stdio.h"


#line 418 "e:\\program\\vc98\\include\\stdio.h"
































 int __cdecl fcloseall(void);
 FILE * __cdecl fdopen(int, const char *);
 int __cdecl fgetchar(void);
 int __cdecl fileno(FILE *);
 int __cdecl flushall(void);
 int __cdecl fputchar(int);
 int __cdecl getw(FILE *);
 int __cdecl putw(int, FILE *);
 int __cdecl rmtmp(void);
 char * __cdecl tempnam(const char *, const char *);
 int __cdecl unlink(const char *);

#line 463 "e:\\program\\vc98\\include\\stdio.h"


}
#line 467 "e:\\program\\vc98\\include\\stdio.h"


#pragma pack(pop)
#line 471 "e:\\program\\vc98\\include\\stdio.h"

#line 473 "e:\\program\\vc98\\include\\stdio.h"
#line 2 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.cpp"
#line 1 "e:\\program\\vc98\\include\\string.h"















#pragma once
#line 18 "e:\\program\\vc98\\include\\string.h"






#line 25 "e:\\program\\vc98\\include\\string.h"



extern "C" {
#line 30 "e:\\program\\vc98\\include\\string.h"

















#line 48 "e:\\program\\vc98\\include\\string.h"























#line 72 "e:\\program\\vc98\\include\\string.h"




#line 77 "e:\\program\\vc98\\include\\string.h"
























        void *  __cdecl memcpy(void *, const void *, size_t);
        int     __cdecl memcmp(const void *, const void *, size_t);
        void *  __cdecl memset(void *, int, size_t);
        char *  __cdecl _strset(char *, int);
        char *  __cdecl strcpy(char *, const char *);
        char *  __cdecl strcat(char *, const char *);
        int     __cdecl strcmp(const char *, const char *);
        size_t  __cdecl strlen(const char *);
#line 110 "e:\\program\\vc98\\include\\string.h"
 void *  __cdecl _memccpy(void *, const void *, int, unsigned int);
 void *  __cdecl memchr(const void *, int, size_t);
 int     __cdecl _memicmp(const void *, const void *, unsigned int);





 void *  __cdecl memmove(void *, const void *, size_t);
#line 120 "e:\\program\\vc98\\include\\string.h"


 char *  __cdecl strchr(const char *, int);
 int     __cdecl _strcmpi(const char *, const char *);
 int     __cdecl _stricmp(const char *, const char *);
 int     __cdecl strcoll(const char *, const char *);
 int     __cdecl _stricoll(const char *, const char *);
 int     __cdecl _strncoll(const char *, const char *, size_t);
 int     __cdecl _strnicoll(const char *, const char *, size_t);
 size_t  __cdecl strcspn(const char *, const char *);
 char *  __cdecl _strdup(const char *);
 char *  __cdecl _strerror(const char *);
 char *  __cdecl strerror(int);
 char *  __cdecl _strlwr(char *);
 char *  __cdecl strncat(char *, const char *, size_t);
 int     __cdecl strncmp(const char *, const char *, size_t);
 int     __cdecl _strnicmp(const char *, const char *, size_t);
 char *  __cdecl strncpy(char *, const char *, size_t);
 char *  __cdecl _strnset(char *, int, size_t);
 char *  __cdecl strpbrk(const char *, const char *);
 char *  __cdecl strrchr(const char *, int);
 char *  __cdecl _strrev(char *);
 size_t  __cdecl strspn(const char *, const char *);
 char *  __cdecl strstr(const char *, const char *);
 char *  __cdecl strtok(char *, const char *);
 char *  __cdecl _strupr(char *);
 size_t  __cdecl strxfrm (char *, const char *, size_t);














 void * __cdecl memccpy(void *, const void *, int, unsigned int);
 int __cdecl memicmp(const void *, const void *, unsigned int);
 int __cdecl strcmpi(const char *, const char *);
 int __cdecl stricmp(const char *, const char *);
 char * __cdecl strdup(const char *);
 char * __cdecl strlwr(char *);
 int __cdecl strnicmp(const char *, const char *, size_t);
 char * __cdecl strnset(char *, int, size_t);
 char * __cdecl strrev(char *);
        char * __cdecl strset(char *, int);
 char * __cdecl strupr(char *);

#line 174 "e:\\program\\vc98\\include\\string.h"







 wchar_t * __cdecl wcscat(wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcschr(const wchar_t *, wchar_t);
 int __cdecl wcscmp(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcscpy(wchar_t *, const wchar_t *);
 size_t __cdecl wcscspn(const wchar_t *, const wchar_t *);
 size_t __cdecl wcslen(const wchar_t *);
 wchar_t * __cdecl wcsncat(wchar_t *, const wchar_t *, size_t);
 int __cdecl wcsncmp(const wchar_t *, const wchar_t *, size_t);
 wchar_t * __cdecl wcsncpy(wchar_t *, const wchar_t *, size_t);
 wchar_t * __cdecl wcspbrk(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcsrchr(const wchar_t *, wchar_t);
 size_t __cdecl wcsspn(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcsstr(const wchar_t *, const wchar_t *);
 wchar_t * __cdecl wcstok(wchar_t *, const wchar_t *);

 wchar_t * __cdecl _wcsdup(const wchar_t *);
 int __cdecl _wcsicmp(const wchar_t *, const wchar_t *);
 int __cdecl _wcsnicmp(const wchar_t *, const wchar_t *, size_t);
 wchar_t * __cdecl _wcsnset(wchar_t *, wchar_t, size_t);
 wchar_t * __cdecl _wcsrev(wchar_t *);
 wchar_t * __cdecl _wcsset(wchar_t *, wchar_t);

 wchar_t * __cdecl _wcslwr(wchar_t *);
 wchar_t * __cdecl _wcsupr(wchar_t *);
 size_t __cdecl wcsxfrm(wchar_t *, const wchar_t *, size_t);
 int __cdecl wcscoll(const wchar_t *, const wchar_t *);
 int __cdecl _wcsicoll(const wchar_t *, const wchar_t *);
 int __cdecl _wcsncoll(const wchar_t *, const wchar_t *, size_t);
 int __cdecl _wcsnicoll(const wchar_t *, const wchar_t *, size_t);







 wchar_t * __cdecl wcsdup(const wchar_t *);
 int __cdecl wcsicmp(const wchar_t *, const wchar_t *);
 int __cdecl wcsnicmp(const wchar_t *, const wchar_t *, size_t);
 wchar_t * __cdecl wcsnset(wchar_t *, wchar_t, size_t);
 wchar_t * __cdecl wcsrev(wchar_t *);
 wchar_t * __cdecl wcsset(wchar_t *, wchar_t);
 wchar_t * __cdecl wcslwr(wchar_t *);
 wchar_t * __cdecl wcsupr(wchar_t *);
 int __cdecl wcsicoll(const wchar_t *, const wchar_t *);

#line 228 "e:\\program\\vc98\\include\\string.h"


#line 231 "e:\\program\\vc98\\include\\string.h"

#line 233 "e:\\program\\vc98\\include\\string.h"


}
#line 237 "e:\\program\\vc98\\include\\string.h"

#line 239 "e:\\program\\vc98\\include\\string.h"
#line 3 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.cpp"
#line 1 "e:\\program\\vc98\\include\\malloc.h"















#pragma once
#line 18 "e:\\program\\vc98\\include\\malloc.h"






#line 25 "e:\\program\\vc98\\include\\malloc.h"







#pragma pack(push,8)
#line 34 "e:\\program\\vc98\\include\\malloc.h"


extern "C" {
#line 38 "e:\\program\\vc98\\include\\malloc.h"

















#line 56 "e:\\program\\vc98\\include\\malloc.h"


































typedef struct _heapinfo {
        int * _pentry;
        size_t _size;
        int _useflag;
        } _HEAPINFO;

#line 97 "e:\\program\\vc98\\include\\malloc.h"



extern unsigned int _amblksiz;




 void *  __cdecl calloc(size_t, size_t);
 void    __cdecl free(void *);
 void *  __cdecl malloc(size_t);
 void *  __cdecl realloc(void *, size_t);






void *          __cdecl _alloca(size_t);
 void *  __cdecl _expand(void *, size_t);
 size_t  __cdecl _get_sbh_threshold(void);
 int     __cdecl _set_sbh_threshold(size_t);
 int     __cdecl _heapadd(void *, size_t);
 int     __cdecl _heapchk(void);
 int     __cdecl _heapmin(void);
 int     __cdecl _heapset(unsigned int);
 int     __cdecl _heapwalk(_HEAPINFO *);
 size_t  __cdecl _heapused(size_t *, size_t *);
 size_t  __cdecl _msize(void *);




#line 131 "e:\\program\\vc98\\include\\malloc.h"



#line 135 "e:\\program\\vc98\\include\\malloc.h"

#line 137 "e:\\program\\vc98\\include\\malloc.h"






















}
#line 161 "e:\\program\\vc98\\include\\malloc.h"


#pragma pack(pop)
#line 165 "e:\\program\\vc98\\include\\malloc.h"

#line 167 "e:\\program\\vc98\\include\\malloc.h"
#line 4 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.cpp"
#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.h"




#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cmyfile.h"




#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cmystring.h"






class CMyString
{
public:
    CMyString();
    CMyString(const char *psz);
    CMyString(const CMyString &str);

    virtual ~CMyString();

public:
    
    void SetString(const char *psz);
    void SetString(const CMyString &str);

    inline const char *GetString(void) const;   
    
    inline size_t GetLen(void)  const;

    const char *StringCopy(const char *psz);
    const char *StringCopy(const CMyString &str);

    const char *StringCat(const char *psz);
    const char *StringCat(const CMyString &str);

    



    bool StringCompare(const char *psz) const;
    bool StringCompare(const CMyString &str) const;

    




    const char *StringChr(int ch) const;
    const char *StringRchr(int ch) const;

    



    const char *StringPbrk(const char *pszgroup) const;
    const char *StringPbrk(const CMyString &str) const;


    




    const char *StringStr(const char *psz) const;
    const char *StringStr(const CMyString &str) const;

    
    void StringToUpper(void);
    void StringToLower(void);


private:
    void StringInit(void);


    
    void AddRef(void);
    void Release(void);
#line 75 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cmystring.h"

private:
    char *m_psz;        
    size_t m_nlen;      
    size_t m_nspace;    


    int *m_prefcount;   
#line 84 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cmystring.h"

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


#line 101 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cmystring.h"
#line 6 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cmyfile.h"
#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\struct.h"




#pragma pack(push)
#pragma pack(1)


typedef struct tag_student
{
    char           chgender;    
    unsigned short ushbirth;    
    float          fscore;  
    


}tag_student;


typedef struct tag_addrecord
{
    unsigned long ulstart;      
    unsigned char uchsize;      
    unsigned char uchnamesize;  
    
    
}tag_addrecord;


typedef struct tag_delrecord
{
    unsigned long ulstart;
    unsigned char uchsize;
}tag_delrecord;


typedef struct tag_newinfo
{
    unsigned char gender:1;
    unsigned char birth:1;
    unsigned char score:1;
    unsigned char name:1;
    unsigned char no:1;
    unsigned char infoid:1;
}tag_newinfo;

#pragma pack(pop)

#line 50 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\struct.h"
#line 7 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cmyfile.h"

class CMyFile
{
public:
    CMyFile() { }
    CMyFile(const char *pszfile)
        :m_filename(pszfile)
    {

    }

    


    void SetFile(const char *pszfile);
    const char *GetFile(void) const;

    




    int ReadData(void *pbuf, unsigned long offset, unsigned char size) const;

    




    int AppendData(void *pbuf, unsigned char size);

    




    int ResetData(void);

    




    int ModifyData(void *pbuf, unsigned long offset, unsigned char size) const;

    







    static int CheckFile(const char *pszfile);

    




    static int FileCopy(const char *pfilesrc, const char *pfiledst);
    
protected:
    CMyString m_filename;
    
};


class CInfoFile: public CMyFile       
{
public:
    CInfoFile(const char *pszfile = "info.txt");

    int
    ReadData(tag_student *pstudent, char *pszname, char *pszno,  
             tag_addrecord *paddrecord                      
              ) const;

    int
    AppendData(tag_student *pstudent, char *pszname, char *pszno,   
               unsigned long offset,                             
               unsigned char namesize,                          
               unsigned char nosize);                           

    








    int
    ModifyData(tag_student *pstudent, char *szname, char *szno,   
                unsigned long offset,                              
                unsigned char namesize ,                          
                unsigned char nosize
              );
   
};


class CAddTableFile: public CMyFile
{
public:
    CAddTableFile(const char *pszfile = "addtable.txt");

};


class CDelTableFile: public CMyFile
{
public:
    CDelTableFile(const char *pszfile = "deltable.txt");
};

#line 125 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cmyfile.h"

#line 6 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.h"
#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\ctable.h"




#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\struct.h"

















































#line 6 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\ctable.h"
#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\const.h"





const	int MAX_INPUT = 128;


const   int ADD     = 1;
const	int DEL	    = 2;
const   int QUERY   = 3;
const   int MODIFY  = 4;


const   int SUCCESS     = 0x00;
const   int NOT_EXIST   = 0x01;
const   int NO_SPACE    = 0x02;
const   int FAILED      = 0x03;


const   int RELATIVE    = 0x00;
const   int ABSOLUTE    = 0x01;


const   int SPLIT   = 8;

#line 28 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\const.h"

#line 7 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\ctable.h"


class CTable
{
public:
    CTable();
    ~CTable();

    unsigned long GetRecordsNum(void) const;
    void SetRecordsNum(unsigned long num);

protected:
    







    int LoadTable(char  **ppbuf, const char *psztablefile, size_t recordsize);

    





    int SaveTable(void *buf,
                  const char *psztablefile,
                  unsigned char recordsize
                  );


    








    void InsertIntoTable(unsigned long *nrecords,         
                        void *records,                         
                        void *newrecord,                       
                        size_t recordsize,
                        int *index,
                        int (*compare)(void *, void *)     
                        );

    






    void UpdateTable(void *precords,          
                    size_t recordsize,      
                    int index,              
                     void *pnewrecord         
                    );

    






    void RemoveFromTable(unsigned long *pnrecords,     
                        void *precords,                      
                        size_t recordsize,                  
                        int index                          
                        );


protected:
    unsigned long m_nrecords;
};


class CAddTable: public CTable
{
public:
    CAddTable();
    ~CAddTable();

    tag_addrecord *GetRecords(void) const;

    





    int LoadTable(const char *pszaddtablefile);

    




    int SaveTable(const char *pszaddtablefile);

    



    void
    InsertIntoTable(tag_addrecord *paddrecord);

    


    void
    UpdateTable(int index, tag_addrecord *paddrecord);

    


    void
    RemoveFromTable(int index);

protected:
    tag_addrecord *m_precords;  
};


class CDelTable: public CTable
{
public:
    CDelTable();
    ~CDelTable();

    tag_delrecord* GetRecords(void) const;
    





    int LoadTable(const char *pszdeltablefile);

    




    int SaveTable(const char *pszdeltable);


    







    void InserIntoTable(tag_delrecord *pdelrecord);

    






    void
    Reorganize(unsigned long index);

    


    void
    UpdateTable(int index, tag_delrecord *pdelrecord);

    


    void
    RemoveFromTable(int index);
      
protected:
    tag_delrecord *m_precords;   
};

#line 197 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\ctable.h"
#line 7 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.h"
#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\ui.h"




#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\struct.h"

















































#line 6 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\ui.h"
#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\const.h"




























#line 7 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\ui.h"

class CPanel
{
public:
    


    static void ShowMenu(void);

    static void ShowMenuEn(void);

    


    static void ShowFit(void);

    



    static void ShowInfo(const char *szhitinfo);

    


    static void
    Show1Info(const tag_student *student, const char *szname, const char *szno, int infoid);

    


    static void GetSelect(unsigned long *pnselect);

    


    static void GetGender(char *gender, const char *szhitinfo);

    


    static void GetBirthday(unsigned short *birthday, const char *szhitinfo);

    


    static void GetScore(float *fscore, const char *szhitinfo);

    



    static void GetInput(char *chinput, const char *szhitinfo);

    


    static bool IsSure(void);
   
    




    static void
    GetNewInfo(tag_student *student, char *szname, char *szno, unsigned long *infoid, 
               int actiontype,
               tag_newinfo *flag
               ); 

    
};

class CYourPanel: public CPanel
{
public:
    
};
#line 86 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\ui.h"
#line 8 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.h"

class CInfoFile;
class CAddTableFile;
class CDelTableFile;

class CStudManage
{
public:
    


    static CStudManage *CreateSystem(void);

    







    int Run(const char *pszinfofile = "info.txt", 
            const char *pszaddtablefile = "addtable.txt", 
            const char *pszdeltablefile = "deltable.txt");

    


    void End(void);

protected:
    CStudManage();

    ~CStudManage();

public:
    




















    int InfoAdd(tag_student *student, char *szname, char *szno);

    













    int
    InfoQueryAbout(tag_student *student, char *szname, char *szno,   
                    unsigned long infoid,                                  
                    int *indexary,                                     
                    int *num,                                           
                    tag_newinfo *flag
                    );

    






    int 
    InfoQueryById(unsigned long infoid);

    













    int
    InfoDel(int infoid);

    





















    int
    InfoModify(tag_student *student, char *szname, char *szno, int infoid, tag_newinfo *flag);

    



    void Display();

    


    void SpaceStat(void);

    
    void Defrag(void);

    
    void InfoStat(void);

    
    int GetAverScore(float *fscore);

    
    void SaveTable(void);

    const CInfoFile *GetInfoFile(void) const;
    const CAddTableFile *GetAddTableFile(void) const;
    const CDelTableFile *GetDelTableFile(void) const;
    CAddTable *GetAddTable(void) const;
    CDelTable *GetDelTable(void) const;

private:
    





    int Init(void);

    


    int Finish(void);

    
    void SetNULL(void);

    
    

    void Dispatch(int nselect);
    void ProcessAdd(void);
    void ProcessQuery(void);
    int ProcessDel(void);
    int ProcessModify(void);
    void ProcessFit(void);

    
    void ShowTable(void);
    
private:
    
    CInfoFile *m_pinfofile;
    CAddTableFile *m_paddtablefile;
    CDelTableFile *m_pdeltablefile;

    
    CAddTable *m_paddtable;
    CDelTable *m_pdeltable;
};








int GetFileSize(unsigned long *pfilesize, const CStudManage *pstudmanage);











int
gettable(unsigned long index, unsigned long *max, 
         unsigned long index_add, unsigned long index_del,
         const CStudManage *pstudmanage);

#line 236 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.h"
#line 5 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.cpp"
#line 1 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\fit.h"

















int 
FitEqual(unsigned char requestsize, int *index);








int 
FitEnouth(unsigned char requestsize, int *index);








int 
FitFirst(unsigned char requestsize, int *index);









class CStudManage;
int 
GetSize(unsigned char requestsize, int *index, const CStudManage *pstudmanage);




void
SetFit(int select);

#line 60 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\fit.h"
#line 6 "e:\\programming\\git\\kr\\ph1_cpp\\n20140501\\wbxu_20140501\\studmanage\\cstudmanage.cpp"

CStudManage *
CStudManage::CreateSystem(void)
{
    static CStudManage *pobj = new CStudManage;
    return pobj;
}

int
CStudManage::Run(const char *pszinfofile, 
                 const char *pszaddtablefile, 
                 const char *pszdeltablefile)
{
    m_pinfofile = new CInfoFile;
    m_paddtablefile = new CAddTableFile;
    m_pdeltablefile = new CDelTableFile;

    m_paddtable = new CAddTable;
    m_pdeltable = new CDelTable;
    
    if (0 == m_pinfofile
        || 0 == m_paddtablefile
        || 0 == m_pdeltablefile
        || 0 == m_paddtable
        || 0 == m_pdeltable)
    {
        return FAILED;
    }
    
    m_pinfofile->SetFile(pszinfofile);
    m_paddtablefile->SetFile(pszaddtablefile);
    m_pdeltablefile->SetFile(pszdeltablefile);

    int nresult = Init();
    if (FAILED == nresult)
    {
        return FAILED;
    }

    unsigned long nselect = 0;
    while (true)
    {
        CYourPanel::ShowMenu();
        
        CYourPanel::GetSelect(&nselect);
        
        if (0 == nselect)
        {
            break;
        }
        else if(nselect < 0 || nselect > 10) 
        {
            CYourPanel::ShowInfo("Please make the right decision ^_^\r\n");
            continue;
        }
        
        Dispatch(nselect);
        
        
        ShowTable();
    }

    return SUCCESS;
}

void
CStudManage::End(void)
{
    Finish();

    delete this;
}

CStudManage::CStudManage()
{
    SetNULL();
}

void 
CStudManage::SetNULL(void)
{
    m_pinfofile = 0;
    m_paddtablefile = 0;
    m_pdeltablefile = 0;
    
    m_paddtable = 0;
    m_pdeltable = 0;
}

CStudManage::~CStudManage()
{

    
    (if ((m_pinfofile) != 0) { delete (m_pinfofile); (m_pinfofile) = 0; } )
    (if ((m_paddtablefile) != 0) { delete (m_paddtablefile); (m_paddtablefile) = 0; } )
    (if ((m_pdeltablefile) != 0) { delete (m_pdeltablefile); (m_pdeltablefile) = 0; } )

    (if ((m_paddtable) != 0) { delete (m_paddtable); (m_paddtable) = 0; } )
    (if ((m_pdeltable) != 0) { delete (m_pdeltable); (m_pdeltable) = 0; } )
}

int
CStudManage::Finish(void)
{
    SaveTable();

    if (m_paddtable != 0)
    {
        delete m_paddtable;
        m_paddtable = 0;
    }

    if (m_pdeltable != 0)
    {
        delete m_pdeltable;
        m_pdeltable = 0;
    }

    return SUCCESS;
}

const CInfoFile *
CStudManage::GetInfoFile(void) const
{
    return m_pinfofile;
}

const CAddTableFile *
CStudManage::GetAddTableFile(void) const
{
    return m_paddtablefile;
}

const CDelTableFile *
CStudManage::GetDelTableFile(void) const
{
    return m_pdeltablefile;
}

CAddTable *
CStudManage::GetAddTable(void) const
{
    return m_paddtable;
}
    
CDelTable *
CStudManage::GetDelTable(void) const
{
    return m_pdeltable;
}

void
CStudManage::SaveTable(void)
{
    m_paddtable->SaveTable(m_paddtablefile->GetFile());
    m_pdeltable->SaveTable(m_pdeltablefile->GetFile());
}

int
CStudManage::Init(void)
{
    int result = SUCCESS;

    

    if (SUCCESS != CMyFile::CheckFile(m_pinfofile->GetFile()))
    {
        goto INIT_ERROR;
    }
    
    result = m_paddtable->LoadTable(m_paddtablefile->GetFile());
    if (SUCCESS != result)
    {
        
        goto INIT_ERROR;        
    }
    
    result = m_pdeltable->LoadTable(m_pdeltablefile->GetFile());
    if (SUCCESS != result)
    {
        goto INIT_ERROR;
    }
    
INIT_ERROR:
    if (result != SUCCESS)
    {
        result = FAILED;
    }
    
    return result;
}

int 
CStudManage::InfoAdd(tag_student *pstudent, char *pszname, char *pszno)
{
    unsigned long ulstart     = 0;      
    unsigned char uchsize     = 0;      
    unsigned char uchnamesize = 0;      
    unsigned char uchnosize   = 0;      
    unsigned char uchtmpsize  = 0;      
    
    tag_addrecord addrecord = {0};
    tag_delrecord delrecord = {0};
    
    int index  = 0;
    int result = SUCCESS;
    
    
    uchnamesize = strlen(pszname) + 1;
    uchnosize   = strlen(pszno) +1;
    uchsize     = sizeof(tag_student) + uchnamesize + uchnosize;
    
    
    result = GetSize(uchsize, &index, this);  
    if (NOT_EXIST == result)
    {
        GetFileSize(&ulstart, this);
        result = m_pinfofile->AppendData(pstudent, pszname, pszno,
                                        ulstart,             
                                        uchnamesize,
                                        uchnosize
                                        );
        
        if (FAILED == result)
        {
            return result;
        }
        
        addrecord.ulstart     = ulstart;
        addrecord.uchsize     = uchsize;
        addrecord.uchnamesize = uchnamesize;
        m_paddtable->InsertIntoTable(&addrecord);                            
        
    }
    else
    {     
        tag_delrecord *pdelrecords = m_pdeltable->GetRecords();
        uchtmpsize  = pdelrecords[index].uchsize;
        ulstart     = pdelrecords[index].ulstart;
        
        result = m_pinfofile->AppendData(pstudent, pszname, pszno,
                                        ulstart,
                                        uchnamesize,
                                        uchnosize);
        
        if (FAILED == result)
        {
            return result;
        }
        
        if (uchtmpsize == uchsize)
        {
            addrecord.uchsize  = uchsize;
            addrecord.ulstart  = ulstart;
            m_pdeltable->RemoveFromTable(index);
            m_paddtable->InsertIntoTable(&addrecord); 
        }
        else
        {
            delrecord.uchsize  = uchtmpsize - uchsize;
            delrecord.ulstart  =  ulstart + uchsize;
            m_pdeltable->UpdateTable(index, &delrecord);
            
            addrecord.uchsize  = uchsize;
            addrecord.ulstart  = ulstart;
            m_paddtable->InsertIntoTable(&addrecord); 
        }
    }
    
    
    result = addrecord.ulstart;
    return result;
}

int
CStudManage::InfoQueryAbout(tag_student *student, char *szname, char *szno,   
               unsigned long infoid,                                  
               int *indexary,                                     
               int *num,                                           
               tag_newinfo *flag
                    )
{
    unsigned char uchnamesize = 0;
    unsigned char uchnosize   = 0;
    unsigned long nrecords    = 0;
    
    tag_addrecord *paddrecord = 0;
    tag_student tmpstudent    = {0};
    char sztmpname[MAX_INPUT] = {0};
    char sztmpno[MAX_INPUT]   = {0};
    
    FILE *fp   = 0;
    int result = NOT_EXIST;
    unsigned long i = 0;
    
    if (1 == flag->name)
    {
        uchnamesize = strlen(szname) + 1;
    }
    
    if (1 == flag->no)
    {
        uchnosize = strlen(szno) + 1;
    }
    
    *num = 0;   

    tag_addrecord *paddrecords = m_paddtable->GetRecords();
    nrecords = m_paddtable->GetRecordsNum();
    for (i = 0; i < nrecords; i++)
    {
        
        
        if (uchnamesize > paddrecords[i].uchnamesize
            || uchnosize > (paddrecords[i].uchsize 
                            - paddrecords[i].uchnamesize
                             - sizeof(tag_student))
            )
        {
            continue;
        }
        
        paddrecord = &paddrecords[i];
        result = m_pinfofile->ReadData(&tmpstudent, sztmpname, sztmpno,
                                    paddrecord
                                    );
        if (FAILED == result)
        {
            return FAILED;
        }
        
        if (uchnamesize > 1
            && (0 == strstr(sztmpname, szname))
            )
        {
            continue;
        }
        
        if (uchnosize > 1
            && (0 == strstr(sztmpno, szno))
            )
        {
            continue;
        }
        
        if (1 == flag->gender
            && student->chgender != tmpstudent.chgender)
        {
            continue;
        }
        
        if (1 == flag->score
            && tmpstudent.fscore < student->fscore)
        {
            continue;
        }
        
        if (1 == flag->birth
            && tmpstudent.ushbirth < student->ushbirth)
        {
            continue;
        }
        
        if (1 == flag->infoid
            && infoid != i)
        {
            continue;
        }
        
        *(indexary + *num) = i;
        *num += 1;       
    }
    
    if (0 != *num)
    {
        result = SUCCESS;
    }
    
    return result;
}

int 
CStudManage::InfoQueryById(unsigned long infoid)
{
    unsigned long nrecords = 0;
    
    nrecords = m_paddtable->GetRecordsNum();
    if (infoid >= 0 && infoid < nrecords)
    {
        return SUCCESS;
    }
    else
    {
        return NOT_EXIST;
    }   
}

int
CStudManage::InfoDel(int infoid)
{
    tag_delrecord delrecord = {0};
    unsigned char uchsize = 0;
    unsigned long ulstart = 0;
    
    tag_student student    = {0};
    char szname[MAX_INPUT] = {0};
    char szno[MAX_INPUT]   = {0};
 
    int result = SUCCESS;
    
    tag_addrecord *paddrecords = m_paddtable->GetRecords();
    uchsize  = paddrecords[infoid].uchsize;
    ulstart = paddrecords[infoid].ulstart;
    
    delrecord.uchsize = uchsize;
    delrecord.ulstart = ulstart;
    
    m_pdeltable->InserIntoTable(&delrecord); 
    m_paddtable->RemoveFromTable(infoid);     
    
    return result;
}

int
CStudManage::InfoModify(tag_student *student, char *szname, char *szno, int infoid,
                        tag_newinfo *flag)
{
    tag_delrecord delrecord  = {0};
    tag_addrecord addrecord  = {0};
    unsigned char uchnewsize = 0;
    unsigned char ucholdsize = 0;
    unsigned char uchsize    = 0;
    unsigned char uchnamesize = 0;
    unsigned char uchnosize   = 0;
    unsigned long ulstart   = 0;
    
    tag_addrecord *paddrecord = 0;
    tag_student tmpstudent    = {0};
    char sztmpname[MAX_INPUT] = {0};
    char sztmpno[MAX_INPUT]   = {0};
    
    int result = SUCCESS; 
    
    tag_addrecord *paddrecords = m_paddtable->GetRecords();
    ulstart     = paddrecords[infoid].ulstart; 
    
    
    paddrecord = &paddrecords[infoid];
    result = m_pinfofile->ReadData(&tmpstudent, sztmpname, sztmpno, 
                                    paddrecord
                        );

    if (FAILED == result)
    {
        
        return result;
    }

    ucholdsize = paddrecords[infoid].uchsize;
    uchnewsize = sizeof(tag_student);  

    uchnamesize = paddrecords[infoid].uchnamesize;  
    uchnosize   = ucholdsize - uchnamesize - sizeof(tag_student);

    
    if (1 == flag->gender)
    {
        tmpstudent.chgender = student->chgender; 
    }

    if (1 == flag->birth)
    {
        tmpstudent.ushbirth = student->ushbirth;
    }

    if (1 == flag->score)
    {
        tmpstudent.fscore = student->fscore;
    }
      
    
    if (1 == flag->name)
    {
        strcpy(sztmpname, szname);
        uchnamesize = strlen(sztmpname) + 1;
    }

    uchnewsize += uchnamesize;

    if (1 == flag->no)
    {
        strcpy(sztmpno, szno);
        uchnosize = strlen(sztmpno) + 1;
    }

    uchnewsize += uchnosize;
    
    
    if (uchnewsize < ucholdsize)
    {
        result = m_pinfofile->ModifyData(&tmpstudent, sztmpname, sztmpno,
                                        ulstart,
                                        uchnamesize,
                                        uchnosize
                                        );
                                   
        if (FAILED == result)
        {
            return result;
        }
        
        addrecord.uchsize  = uchnewsize;
        addrecord.ulstart = ulstart;
        addrecord.uchnamesize = uchnamesize;
        m_paddtable->UpdateTable(infoid, &addrecord);
        
        delrecord.uchsize  = ucholdsize - uchnewsize;
        delrecord.ulstart = ulstart + uchnewsize;
        m_pdeltable->InserIntoTable(&delrecord);  
    }
    else if (uchnewsize == ucholdsize)
    {
        result = m_pinfofile->ModifyData(&tmpstudent, sztmpname, sztmpno,
                                        ulstart,
                                        uchnamesize,
                                        uchnosize
                                        );
        
        if (FAILED == result)
        {
            return result;
        }
    }
    else
    {
        InfoDel(infoid);
        result = InfoAdd(&tmpstudent, sztmpname, sztmpno);
    }
    
    return result;
}

void
CStudManage::Display(void)
{
    char szhitinfo[MAX_INPUT * 2] = {0};
    char szname[MAX_INPUT]    = {0};
    char szno[MAX_INPUT]      = {0};
    tag_student student       = {0};
    tag_addrecord *paddrecord = 0;
    
    unsigned long ulstart = 0;
    unsigned long nrecords = 0;
    int result   = SUCCESS;
    unsigned long i = 0;
    
    tag_addrecord *paddrecords = m_paddtable->GetRecords();
    nrecords = m_paddtable->GetRecordsNum(); 
        
    CYourPanel::ShowInfo("id   name   no   gender   birthday   score\r\n");
    for (i = 0; i < nrecords; i++)
    {
        ulstart = paddrecords[i].ulstart;
        
        paddrecord = &paddrecords[i];
        result = m_pinfofile->ReadData(&student, szname, szno, 
                                        paddrecord);
        if (FAILED == result)
        {
            CYourPanel::ShowInfo("Display fetch1info error\r\n");
        }
        
        sprintf(szhitinfo, "    start at: %d\r\n", ulstart);
        CYourPanel::ShowInfo(szhitinfo);
        
        sprintf(szhitinfo, "%d   %s   %s   %c   %d   %f\r\n",
                i,
                szname,
                szno,
                student.chgender,
                student.ushbirth,
                student.fscore
                );
        CYourPanel::ShowInfo(szhitinfo);
    }
}




void
showbuf(char *buf, int index, int len,
        void (*pfnshowinfo)(const char *))
{
    char szhitinfo[8] = {0};
    int i;
    
    
    if (index < 0)
    {
        index = 0;
    }
    
    for (i = index; i < index + len; i++)
    {
        if ('\0' == buf[i])
        {
            pfnshowinfo("\\0 ");
        }
        else
        {
            sprintf(szhitinfo, "%02X ", (unsigned char)buf[i]);  
            pfnshowinfo(szhitinfo);
        }
    }
}

int
space_stat(unsigned long startaddr, unsigned long size, 
           int relativeaddrflg,     
           const char *szfile,            
           const CStudManage *pstudmanage,
           void (*pfnshowinfo)(const char *)
           )
{
    char szhitinfo[32] = {0};
    char buf[SPLIT * 2] = {0};
    unsigned long index_add = 0;   
    unsigned long index_del = 0;   
    unsigned long index_buf = 0;   
    unsigned long readcount = 0;   
    unsigned char readremain = 0;  
    unsigned long max       = 0;    

    int col       = 0;    
    int table     = 0;
    int start     = 0;
    int len       = 0;
    int remain    = 0;
    int i         = 0;
    char flag     = '\0'; 
    int result    = SUCCESS;

    CMyFile fileobj(szfile);

    table     = ADD;
    max       = 0; 
    
    readcount = size / (SPLIT);
    readremain = (unsigned char)(size % (SPLIT));

    for (index_buf = startaddr; index_buf < startaddr + size; index_buf++)
    {
        
        if (0 == col % SPLIT)
        {
            col = 0;

            if (0 == readcount)
            {
                result = fileobj.ReadData(buf, index_buf, readremain);
            }
            else
            {
                
                result = fileobj.ReadData(buf, index_buf, SPLIT);
                if (SUCCESS == result)
                {
                    readcount--;
                }
            }

            if (SUCCESS != result)
            {
                return result;
            }           
        }

        
        if (index_buf >= max)
        {
            table = gettable(index_buf, &max, index_add, index_del, pstudmanage);  
            
            if (ADD == table)
            {
                
                index_add++;
            }
            else
            {
                index_del++;
            }
        }
        else
        {
            
            
        }        

        if (ADD == table)       
        {
            flag = 'U';
        }
        else if (DEL == table)  
        {
            flag = 'F';
        }
        else
        {
            
        }

        
        if (0 == col % (SPLIT))
        {
            sprintf(szhitinfo, "%p: ", index_buf); 
            pfnshowinfo(szhitinfo);
        }
       
        
        sprintf(szhitinfo, "%c ", flag);
        pfnshowinfo(szhitinfo);
  
        
        if ((col != 0)
            &&(0 == (col + 1) % (SPLIT)) 
            )
        {
            pfnshowinfo("    ");

            start = 0;
            len   = (SPLIT);
            showbuf(buf, start, len, pfnshowinfo);

            pfnshowinfo("\r\n");
        }
        col += 1;
    } 
    
    
    remain = (SPLIT) - col % (SPLIT);
    for (i = 0; i < remain; i++)
    {
        pfnshowinfo("  ");
    }
    pfnshowinfo("  ");
    
    len   = (SPLIT) - remain;
    start = 0;
    
    showbuf(buf, start, len, pfnshowinfo);
    
    return result;
}

int
space_stat_for_file(const char *pszfile, 
                    const CStudManage *pstudmanage, 
                    void (*pfnshowinfo)(const char *))
{
    unsigned long startaddr = 0; 
    unsigned long filesize = 0;

    int result = SUCCESS;

    result = GetFileSize(&filesize, pstudmanage);
    if (FAILED == result)
    {
        return result;
    }

    result = space_stat(startaddr, filesize, RELATIVE, pszfile, pstudmanage, pfnshowinfo);
    if (FAILED == result)
    {
        return result;
    }

    return result;
}

void
CStudManage::SpaceStat()
{
    space_stat_for_file(m_pinfofile->GetFile(), this, CYourPanel::ShowInfo);
}

int
moveforward(int index, unsigned char step, const CStudManage *pstudmanage)
{
    char strinfobuf[MAX_INPUT * 2] = {0};
    unsigned long  nrecords = 0;
    unsigned long ulstart = 0;
    unsigned char uchsize = 0;
    
    int result = 0;
    unsigned long i = 0;

    CAddTable *paddtable = pstudmanage->GetAddTable();
    tag_addrecord *paddrecords = paddtable->GetRecords();

    const CInfoFile *pinfofile = pstudmanage->GetInfoFile();
    
    nrecords = paddtable->GetRecordsNum();
    for (i = index; i <= nrecords; i++)
    {
        ulstart = paddrecords[i - 1].ulstart;
        uchsize = paddrecords[i - 1].uchsize;
        
        const CMyFile *pfile = pinfofile;
        result = pfile->ReadData(strinfobuf, ulstart, uchsize);
        if (FAILED == result)
        {
            
            return result;
        }
        
        
        result = pfile->ModifyData(strinfobuf, ulstart - step, uchsize);
        if (FAILED == result)
        {
            
            return result;
        }
    }
    
    
    
    
    return result;
}

void
CStudManage::Defrag(void)
{
    unsigned char size_del = 0;
    unsigned long start_del = 0;
    unsigned char size_add = 0;
    unsigned long start_add = 0;    
    int nrecords_add = 0;
    unsigned long i = 0, j = 0, k = 0;
    
    nrecords_add = m_paddtable->GetRecordsNum();
    i            = m_pdeltable->GetRecordsNum(); 

    tag_addrecord *paddrecords = m_paddtable->GetRecords();
    tag_delrecord *pdelrecords = m_pdeltable->GetRecords();
    
    
    for ( ;i >= 1; i--)
    {
        size_del  = pdelrecords[i - 1].uchsize;
        start_del = pdelrecords[i - 1].ulstart;        
        
        
        for (j = nrecords_add ; j >= 1; j--)
        {
            size_add  = paddrecords[j - 1].uchsize;
            start_add = paddrecords[j - 1].ulstart;
            
            if (start_add == start_del + size_del)
            {
                
                break;
            }
        }
        
        
        moveforward(j, size_del, this);
        
        
        pdelrecords[i - 1].uchsize  = 0; 
        pdelrecords[i - 1].ulstart = 0; 
        m_pdeltable->SetRecordsNum(m_pdeltable->GetRecordsNum() - 1);
        
        
        for (k = nrecords_add; (j >= 1) && (k >= j); k--)
        {
            paddrecords[k - 1].ulstart = paddrecords[k - 1].ulstart - size_del;            
        }           
    }

    SaveTable();
}




void
CStudManage::Dispatch(int nselect)
{
    char szhitinfo[MAX_INPUT] = {0};
    float fscore = 0.0f;
    int result = 0;
    
    switch (nselect)
    {
    default:
        {
            CYourPanel::ShowInfo("Please make the right decision ^_^\r\n");
            break;
        }
        
    case 1:
        {
            ProcessAdd();
            break;
        }
        
    case 2:
        {
            ProcessQuery();
            break;
        }
        
    case 3:
        {
            ProcessDel();
            break;
        }
        
    case 4:
        {
            ProcessModify();
            break;
        }
        
    case 5:
        {
            
            CYourPanel::ShowInfo("Displaying......\r\n");
            
            Display();
            break;
        }
        
    case 6:
        {
            
            CYourPanel::ShowInfo("Statisticsing......U for Used, F for Free\r\n\r\n");
            
            SpaceStat();
            break;
        }
        
    case 7:
        {
            ProcessFit();
            break;
        }
        
    case 8:
        {
            Defrag();            
            break;
        }
        
    case 9:
        {
            InfoStat();
            break;
        }
        
    case 10:
        {
            result = GetAverScore(&fscore);
            if (SUCCESS == result)
            {
                sprintf(szhitinfo, "averscore is %f\r\n", fscore);
                CYourPanel::ShowInfo(szhitinfo);
            }
            
            break;
        }
    }
}

void
CStudManage::ProcessAdd(void)
{
    char szhitinfo[MAX_INPUT] = {0};    
    char szname[MAX_INPUT]    = {0};
    char szno[MAX_INPUT]      = {0};
    char           chgender   = 'F';    
    unsigned short ushbirth   = 1212;   
    float          fscore     = 0.0f;
    tag_student student       = {0};
    int result                = 0;     
    
    
    CYourPanel::GetInput(szname, "Enter Name:   ");
    CYourPanel::GetInput(szno,   "Enter No  :   ");
    CYourPanel::GetGender(&chgender, "Enter Gender:   ");
    CYourPanel::GetBirthday(&ushbirth, "Enter Birthday(mmdd):   ");
    CYourPanel::GetScore(&fscore, "Enter Score:   ");
    
    student.chgender = chgender;
    student.ushbirth = ushbirth;
    student.fscore   = fscore;    
    
    result = InfoAdd(&student, szname, szno);
    if (NO_SPACE == result)
    {
        CYourPanel::ShowInfo("Add failed, for No More Space\r\n");
    }
    else
    {
        
        sprintf(szhitinfo, "\r\nADD: store into %d\r\n", result);
        CYourPanel::ShowInfo(szhitinfo);
    }
    
    SaveTable();
}

void
CStudManage::ProcessQuery(void)
{
    char szhitinfo[MAX_INPUT] = {0};    
    char szname[MAX_INPUT]    = {0};
    char szno[MAX_INPUT]      = {0};
    tag_student student       = {0};
    tag_newinfo flag          = {0};
    tag_addrecord *paddrecord = 0;
    unsigned long infoid      = 0;
    
    int result                = 0;     
    int ch = 0;    
    int i  = 0;
    
    int indexary[MAX_INPUT]   = {0};    
    int num                   = 0;      
    int index                 = 0;
    char szqueryed[MAX_INPUT*2] = {0};
    
    
    CYourPanel::ShowInfo("支持对学生基本信息、姓名、学号和编号的模糊查询、联合查询\r\n");
    CYourPanel::GetNewInfo(&student, szname, szno, &infoid, QUERY, &flag);
    
    if (0 == *(unsigned char*)(&flag))
    {
        return;
    }
    
    result = InfoQueryAbout(&student, szname, szno,
        infoid,
        indexary,
        &num,
        &flag
        );
    
    if (NOT_EXIST == result)
    {
        CYourPanel::ShowInfo("Query: not exist\r\n");
        return;
    }
    
    tag_addrecord *paddrecords = m_paddtable->GetRecords();
    const CInfoFile *pinfofile = m_pinfofile;

    
    CYourPanel::ShowInfo("Queryed: id  name     no      gender birthday  score \r\n");
    for (i = 0; i < num; i++)
    {
        
        index = indexary[i];    
        
        paddrecord = &paddrecords[index];
        result = pinfofile->ReadData(&student, szname, szno, 
            paddrecord);
        
        if (FAILED == result)
        {
            CYourPanel::ShowInfo("process_query fetch1info error");
        }
        
        CYourPanel::Show1Info(&student, szname, szno, infoid);
    }
}

int
CStudManage::ProcessDel(void)
{
    char szhitinfo[MAX_INPUT] = {0};    
    unsigned long infoid      = 0;  
    int result                = 0;
    int ch                    = 0;
    
    tag_addrecord *paddrecord = 0;
    tag_student student    = {0};
    char szname[MAX_INPUT] = {0};
    char szno[MAX_INPUT]   = {0};
    
    CYourPanel::ShowInfo("仅能删除具体编号的学生信息，请根据模糊查询确认编号\r\n");
    CYourPanel::ShowInfo("请输入编号：");
    CYourPanel::GetSelect(&infoid);
    
    result = InfoQueryById(infoid);   
    if (NOT_EXIST == result)
    {
        sprintf(szhitinfo, "%d does not exist\r\n", infoid);
        CYourPanel::ShowInfo(szhitinfo);
        return result;
    }
    
    paddrecord = &(m_paddtable->GetRecords())[infoid];
    result = m_pinfofile->ReadData(&student, szname, szno, 
                                    paddrecord
                                   );
    if (FAILED == result)
    {
        CYourPanel::ShowInfo("info_del fetch1info error\r\n");
        return result;
    }
    
    CYourPanel::ShowInfo("queryed:  id  name   no    gender  birthday  score\r\n");
    CYourPanel::Show1Info(&student, szname, szno, infoid);
    
    CYourPanel::ShowInfo("Are you sure to delete this one? (Y/N) >>");
    if (!CYourPanel::IsSure())
    {
        return result;
    }
    
    result = InfoDel(infoid); 
    CYourPanel::ShowInfo("Del ok\r\n");
    
    SaveTable();
    
    return result;
}

int
CStudManage::ProcessModify(void)
{
    char szhitinfo[MAX_INPUT] = {0};    
    char szname[MAX_INPUT]    = {0};
    char szno[MAX_INPUT]      = {0};
    tag_student student       = {0};
    tag_newinfo flag          = {0};
    tag_addrecord *paddrecord = 0;
    unsigned long infoid      = 0;
    int result                = SUCCESS;     
    int ch = 0;    
    int i  = 0;
    
    int indexary[MAX_INPUT]   = {0};    
    int num                   = 0;      
    int index                 = 0;
    char szqueryed[MAX_INPUT*2] = {0};
    
    CYourPanel::ShowInfo("仅能修改指定编号的学生信息，可通过模糊查询确认编号\r\n");
    CYourPanel::ShowInfo("请输入具体编号: ");
    CYourPanel::GetSelect(&infoid);
    
    result = InfoQueryById(infoid);
    if (NOT_EXIST == result)
    {
        CYourPanel::ShowInfo("NOT EXIST\r\n");
        return result;
    }
    
    tag_addrecord *paddrecords = m_paddtable->GetRecords();
    const CInfoFile *pinfofile = m_pinfofile;
    paddrecord = &paddrecords[infoid];
    result = pinfofile->ReadData(&student, szname, szno, 
                                paddrecord
                                );
    if (FAILED == result)
    {
        CYourPanel::ShowInfo("Process_modify fetch1info error\r\n");
        return result;
    }
    
    CYourPanel::ShowInfo("queryed: id  name   no  gender birthday score\r\n");
    CYourPanel::Show1Info(&student, szname, szno, infoid);
    
    CYourPanel::ShowInfo("Are you sure to modify? (Y/N) >>");
    if (!CYourPanel::IsSure())
    {
        return result;
    }      
    
    
    CYourPanel::ShowInfo("支持对学生基本信息、姓名、学号修改\r\n");
    CYourPanel::GetNewInfo(&student, szname, szno, &infoid, MODIFY, &flag);
    
    if (0 == *(unsigned char *)&flag)
    {
        return SUCCESS;
    }
    
    result = InfoModify(&student, szname, szno, infoid, &flag);
    if (NOT_EXIST == result)
    {
        sprintf(szhitinfo, "Modify: %d not exist\r\n", infoid);
        CYourPanel::ShowInfo(szhitinfo);
    }
    else if (NO_SPACE == result)
    {
        CYourPanel::ShowInfo("Modify: no more space to store newinput\r\n");
    }
    else
    {
        CYourPanel::ShowInfo("Modify ok\r\n");
    }
    
    SaveTable();
    
    return result;
}

void
CStudManage::ProcessFit(void)
{
    unsigned long nselect = 0;
    
    
    CYourPanel::ShowInfo("Please choose the fit way\r\n");    
    CYourPanel::ShowFit();    
    CYourPanel::GetSelect(&nselect);
    
    if (nselect < 0 || nselect > 4 )  
    {
        CYourPanel::ShowInfo("Please make the right decision ^_^\r\n");
    }
    else
    {
        SetFit(nselect);
    }
}

void
CStudManage::ShowTable(void)
{
    char szhitinfo[64] = {0};
    unsigned long nrecords = 0;
    unsigned long i = 0;
    
    CYourPanel::ShowInfo("\r\n[ Debug ]showing g_add_table (start, size) ......\r\n");    
    CYourPanel::ShowInfo("g_add_table:\r\n");

    CAddTable *paddtable = m_paddtable;
    tag_addrecord *paddrecords = paddtable->GetRecords();
    
    nrecords = paddtable->GetRecordsNum();
    for (i = 0; i < nrecords; i++)
    {
        
        sprintf(szhitinfo, "(%d %d) ", paddrecords[i].ulstart, 
                paddrecords[i].uchsize);
        CYourPanel::ShowInfo(szhitinfo);
    }
    CYourPanel::ShowInfo("\r\n\r\n");
    
    CYourPanel::ShowInfo("g_del_table:\r\n");

    CDelTable *pdeltable = m_pdeltable;
    tag_delrecord *pdelrecords = pdeltable->GetRecords();

    nrecords = pdeltable->GetRecordsNum();
    for (i = 0; i < nrecords; i++)
    {
        sprintf(szhitinfo, "(%d %d) ", pdelrecords[i].ulstart, 
                        pdelrecords[i].uchsize);
        CYourPanel::ShowInfo(szhitinfo);
    }
    CYourPanel::ShowInfo("\r\n\r\n"); 
}

void
CStudManage::InfoStat(void)
{
    char szhitinfo[MAX_INPUT] = {0};
    unsigned char uchsize  = 0;
    unsigned long nrecords = 0;
    unsigned long filesize = 0; 
    int  result   = SUCCESS;
    unsigned long i = 0;
    
    result = GetFileSize(&filesize, this);
    if (FAILED == result)
    {
        CYourPanel::ShowInfo("info_stat getfilesize error");
        return;
    }
    
    CYourPanel::ShowInfo("id: 占用大小  占比\r\n");
    
    CAddTable *paddtable = m_paddtable;
    tag_addrecord *paddrecords = paddtable->GetRecords();
    
    nrecords = paddtable->GetRecordsNum();
    for (i = 0; i < nrecords; i++)
    {
        uchsize = paddrecords[i].uchsize;
        sprintf(szhitinfo, "%d: %d  %f\r\n", i, uchsize, uchsize * 1.0f/filesize);
        CYourPanel::ShowInfo(szhitinfo);
    } 
}

int
CStudManage::GetAverScore(float *fscore)
{
    unsigned long nrecords = 0;
    
    tag_student student = {0};
    tag_addrecord *paddrecord = 0;
    char szname[MAX_INPUT] = {0};
    char szno[MAX_INPUT]    = {0};
    
    float totalscore = 0.0;
    float averscore  = 0.0;
    int result = SUCCESS;
    unsigned long i = 0;
    
    CAddTable *paddtable = m_paddtable;
    tag_addrecord *paddrecords = paddtable->GetRecords();
    
    const CInfoFile *pinfofile = m_pinfofile;
    
    nrecords = paddtable->GetRecordsNum();
    for (i = 0; i < nrecords; i++)
    {
        paddrecord = &paddrecords[i];
        result = pinfofile->ReadData(&student, szname, szno,
                                    paddrecord);
        if (FAILED == result)
        {
            CYourPanel::ShowInfo("process_averscore fetch1info error");
            return result;
        }
        
        totalscore += student.fscore;
    }
    
    if (nrecords)
    {
        averscore = totalscore / nrecords;
        
        *fscore = averscore;
    }
    
    return result;
}

int
GetFileSize(unsigned long *filesize, const CStudManage *pstudmanage)
{
    FILE *fp    = 0;
    unsigned long addoffset   = 0;
    unsigned long deloffset   = 0;
    long size   = 0;
    long offset = 0;
    int result  = SUCCESS;
    
    fp = fopen(pstudmanage->GetInfoFile()->GetFile(), "rb");
    if (0 == fp)
    {
        result = FAILED;
        return result;
    }
    
    
    CAddTable *paddtable = pstudmanage->GetAddTable();
    CDelTable *pdeltable = pstudmanage->GetDelTable();
    tag_addrecord *paddrecords = paddtable->GetRecords();
    tag_delrecord *pdelrecords = pdeltable->GetRecords();
    unsigned long naddrecords = paddtable->GetRecordsNum();
    unsigned long ndelrecords = pdeltable->GetRecordsNum();
    if (0 != naddrecords)
    {
        addoffset = paddrecords[naddrecords- 1].ulstart
            + paddrecords[naddrecords - 1].uchsize;
        
    }
    
    if (0 != ndelrecords)
    {
        deloffset = pdelrecords[ndelrecords - 1].ulstart
            + pdelrecords[ndelrecords - 1].uchsize;    
    }
    
    offset = (addoffset > deloffset ? addoffset : deloffset);       
    
    
    fseek(fp, offset, 1);
    if (((fp)->_flag & 0x0020))
    {
        perror("Getfilesize fseek error");
        
        result = FAILED;
        goto GETFILESIZE_ERROR;
    }
    
    size = ftell(fp);
    if (((fp)->_flag & 0x0020))
    {
        perror("Getfilesize ftell error");
        
        result = FAILED;
        goto GETFILESIZE_ERROR;
    }
    
    *filesize = size;
    
GETFILESIZE_ERROR:
    if (fp)
    {
        fclose(fp);
        fp = 0;
    }
    
    return result;
}

int
gettable(unsigned long index, unsigned long *max, unsigned long index_add, unsigned long index_del,
         const CStudManage *pstudmanage)
{
    unsigned char size_add  = 0;
    unsigned long start_add = 0;
    unsigned char size_del  = 0;
    unsigned long start_del = 0;
    int table               = 0;
    
    CAddTable *paddtable = pstudmanage->GetAddTable();
    tag_addrecord *paddrecords = paddtable->GetRecords();
    
    if (index_add != paddtable->GetRecordsNum())
    {
        size_add  = paddrecords[index_add].uchsize;
        start_add = paddrecords[index_add].ulstart;
    }
    
    CDelTable *pdeltable = pstudmanage->GetDelTable();
    tag_delrecord *pdelrecords = pdeltable->GetRecords();
    
    if (index_del != pdeltable->GetRecordsNum())
    {
        size_del  = pdelrecords[index_del].uchsize;
        start_del = pdelrecords[index_del].ulstart;
    }
    
    if ((index >= start_add) && (index < start_add + size_add))
    {
        *max = start_add + size_add;
        return ADD;
    }
    
    if ((index >= start_del) && (index <= start_del + size_del))
    {
        *max = start_del + size_del;
        return DEL;
    }
    
    
    return table;
}


