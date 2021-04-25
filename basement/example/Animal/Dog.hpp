#ifndef _ANIMAL_DOG_H_
#define _ANIMAL_DOG_H_


#include "Animal.hpp"
#include <cstring>
#include <iostream>

using namespace std;

class Dog : public Animal{
    public:
        Dog( const char *const name);
        ~Dog();
        virtual void voice();
    private:
        char *name;
};

#endif
