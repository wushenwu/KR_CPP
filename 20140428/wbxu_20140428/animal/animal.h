#ifndef ANIMAL_H_0ACA3076_EA9B_4850_9A77_21E5B899C926

#define ANIMAL_H_0ACA3076_EA9B_4850_9A77_21E5B899C926

/************************************************************************/
/* 1.写一基类动物Animal有年龄，名字成员，有吃方法，
其子类鱼fish,人person和老虎tiger也都有各自的吃方法。
请实现喂鱼，人吃饭，喂老虎                                                                     */
/************************************************************************/

#include <iostream>
using namespace std;

class CAnimal
{
public:
    void eat(void) 
    {
        cout << "animal eating" << endl;
    }
  
private:
    int m_nage;
    char *m_szname[64];
};

class CFish: public CAnimal
{
public:
    void eat(void) 
    {
        cout << "Fish eating" << endl;
    }
};

class CTiger: public CAnimal
{
public:
    void eat(void) 
    {
        cout << "Tiger eating" << endl;
    }
};

class CPerson: public CAnimal
{
public:
    void eat(void) 
    {
        cout << "Person eating" << endl;
    }

    void feed_fish(CFish &fish)
    {
        cout << "Person feeding fish" << endl;
        fish.eat();
    }

    void feed_tiger( CTiger &tiger)
    {
        cout << "Person feeding tiger" << endl;
        tiger.eat();
    }
};
#endif
