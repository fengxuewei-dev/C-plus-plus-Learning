#ifndef _DISPLAY_H_
#define _DISPLAY_H_


class Card{
    public:
        Card(){
            
        }
        virtual ~Card(){
            
        }
        virtual void display() = 0; // 一个类中包含一个纯虚函数，称为单一原则

    private:
};


#endif

