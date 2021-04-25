#ifndef _CPU_H_
#define _CPU_H_


class CPU{
    public:
        CPU(){
            
        }
        virtual ~CPU(){
            
        }
        virtual void calculate() = 0;

    private:
};


#endif

