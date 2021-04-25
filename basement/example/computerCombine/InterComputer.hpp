#ifndef _INTER_COM_H_
#define _INTER_COM_H_

#include "Computer.hpp"

class Inter : public Computer{
    public:
        virtual void calculate();
        virtual void display();
        virtual void stroage();
    private:

};


#endif