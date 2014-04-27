#include <iostream>
using namespace std;

const int MAX_LINE = 128;
const int SUCCESS = 0;
const int FAIL = 1;

enum START_TYPE {COMMENT_SINGLE, COMMENT_MULT, CODE};

void
usage(void)
{
    cout << "usage: codestat your.cpp" << endl;
}

void
skipspace(char * &pszline)
{
    while (' ' == *pszline)
    {
        pszline++;
    }
}

int
findcommentend(char * &pszline)
{
    while (*pszline)
    {
        if ('*' == *pszline
            && '/' == *(pszline + 1))
        {
            pszline += 2;
            return SUCCESS;
        }

        pszline++;
    }

    return FAIL;
}

int
getstarttype(char *pszline)
{
    //start with //
    if ('/' == *pszline
        && *pszline == *(pszline + 1)
        )
    {
        return COMMENT_SINGLE;
    }

    //start with / * 
    if ('/' == *pszline
        && '*' == *(pszline + 1))
    {
        return COMMENT_MULT;
    }

    //start with * /
    if ('*' == *pszline
        && '/' == *(pszline + 1))
    {
        return COMMENT_MULT;
    }

    return CODE;
}

/*
Function: 统计pszfile所指定的代码文件中，注释行、代码行和空行的个数

Return  : 0 成功统计，1统计失败

1) if one line starts with //, then it can only be the comment line.
2) as for code and / * * /, //
   a) / * * / + code + 
   b) code + //
   c) code + / * * /  

*/
int
codestat(char *pszfile,
         int &ncommentline,
         int &ncodeline,
         int &nblankline,
         int &ntotalline,
         int &nbothline
        )
{
    FILE *fp = NULL;
    int result = SUCCESS;

    fp = fopen(pszfile, "r");
    if (NULL == fp)
    {
        cout << "Cannot open file" << endl;
        return FAIL;                                                     
    }

    char szline[MAX_LINE] = {0};
    char *pszline = NULL;
    int flg_commentstart = 0;   //
    int start_type = CODE;      //
    int flg_alreadycomment = 0;        //同时包含comment和code的

    while (0 == feof(fp))
    {
        fgets(szline, MAX_LINE, fp);
        if (ferror(fp))
        {
            perror("fgets readline error");

            result = FAIL;
            goto CODE_STAT_ERROR;
        }

        ntotalline++;
        flg_alreadycomment = 0;

        pszline = szline;
        skipspace(pszline);
       
        //空行情况，或为空行，或为注释中的空行
        if (0 == strcmp(szline, "\n")
            || 0 == strcmp(szline, "\r\n"))
        {
            if (1 == flg_commentstart)
            {
                ncommentline++;
            }
            else
            {
                nblankline++;
                cout << nblankline << " " << ntotalline << endl;
            }            
            continue;
        }  
        
        start_type = getstarttype(pszline);

        //以//开头的注释行
        if (COMMENT_SINGLE == start_type)
        {
            ncommentline++;
            continue;
        }

        // 以/* 或者 */开头的注释行，也可能包含代码
        if (COMMENT_MULT == start_type)
        {
            ncommentline++;
            flg_alreadycomment = 1;
            flg_commentstart = 1;
            
            // find the * / within the same line, this is a comment line, maybe code exist
            if (SUCCESS == findcommentend(pszline))
            {
                flg_commentstart = 0;
            }
            else    // this can only be the comment line
            {
                flg_alreadycomment = 0;
                continue;
            }                  
        }

        /*接下来是以代码开始的行，或者在* /之后的代码部分 */

        //以代码开始的行，但在多注释中，是注释行
        if (CODE == start_type
            && 1 == flg_commentstart)
        {
            ncommentline++;
            continue;
        }

        skipspace(pszline);

        if (0 == strcmp(pszline, "\n")
            || 0 == strcmp(pszline, "\r\n")
            )
        {
            continue;
        }

        ncodeline++;

        //now if we can find / * or * / or //, it can also be a comment line
        while (*pszline)
        {
            if (('/' == *pszline && *pszline == *(pszline + 1))
                || ('/' == *pszline && '*' == *(pszline + 1))
                //|| ('*' == *pszline && '/' == *(pszline + 1))
                )
            {
                nbothline++;

                //是代码开头， 后有注释的情况
                if (0 == flg_alreadycomment)
                {
                    ncommentline++;
                }
                else    //是注释开头，后有代码，再跟注释的情况
                {
                    flg_alreadycomment = 0; //reset, for next line
                }

                if ('/' == *pszline && '*' == *(pszline + 1))
                {
                    flg_commentstart = 1;
                }

                break;
            } //end for comment

            pszline++;
        }
    }

CODE_STAT_ERROR:
    if (fp)
    {
        fclose(fp);
        fp = NULL;
    }

    return result;
}

int
main(int argc, char **argv)
{
    if (argc != 2)
    {
        usage();
        return 1;
    }

    int ncommentline = 0;
    int ncodeline = 0;
    int nblankline = 0;
    int ntotalline = 0;
    int nbothline = 0;

    int result = codestat(argv[1], ncommentline, ncodeline, nblankline, ntotalline, nbothline);
    if (SUCCESS == result)
    {
        cout << "comment line: " << ncommentline
             << "\r\ncode line: " << ncodeline
             << "\r\nboth line: " << nbothline
             << "\r\nblank line: " << nblankline
             << "\r\ntotal line: " << ntotalline
             << endl;
    }

    return 0;
}