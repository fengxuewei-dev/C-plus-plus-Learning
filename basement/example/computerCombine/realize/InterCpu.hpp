#ifndef _INTER_CPU_H_
#define _INTER_CPU_H_

#include "../abstract/CPU.hpp"
#include <iostream>
using namespace std;

class InterCpu : public CPU{
    public:
        virtual void calculate();
};

#endif
