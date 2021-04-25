#ifndef _ANIMAL_CAT_H_
#define _ANIMAL_CAT_H_

#include "Animal.hpp"
#include <cstring>
#include <iostream>

using namespace std;

class Cat : public Animal{
    public:
        Cat(const char *const name);
        ~Cat();

        virtual void voice();

    private:
        char *name;

};


#endif
