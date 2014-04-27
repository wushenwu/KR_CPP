#ifndef SIMULATE_H_8391572A_D653_4dc5_BEC6_A3ECF8A55076

#define SIMULATE_H_8391572A_D653_4dc5_BEC6_A3ECF8A55076

typedef struct tag_class_ tag_class;

struct tag_class_
{
    //public data
    int m_ndata; 

    //public method
    void (*pfnSetData)(tag_class *pself, int ndata);
    int (*pfnGetData)(tag_class *pself);    
    
};

/*
“类”对象的初始化
*/
void
ClassInit(tag_class *pobject);

#endif