#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <iostream>

class Animal{
    public:
        virtual void voice() = 0;
        Animal();
        // 加入一个虚析构函数，避免出现内存泄露
        virtual ~Animal();
};

void printAni(Animal *ap);
#endif
