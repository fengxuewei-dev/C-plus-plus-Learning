#ifndef _INTER_MEMORY_H_
#define _INTER_MEMORY_H_

#include "../abstract/Memory.hpp"
#include <iostream>
using namespace std;

class InterMemory : public Memory{
    public:
        virtual void stroage();
};

#endif
