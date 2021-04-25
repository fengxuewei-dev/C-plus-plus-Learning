#ifndef _COMPUTER_H_
#define _COMPUTER_H_

#include <iostream>

#include "CPU.hpp"
#include "Memory.hpp"
#include "Card.hpp"

// 电脑和其他零件是 包含关系，所以不应该是 继承关系，是 has a 关系

// 架构类
class Computer{
    public:
        Computer(CPU *, Memory*, Card*);
        ~Computer();

        void work();
    private:
        CPU *cpu;
        Memory *memory;
        Card *card;
};

#endif
