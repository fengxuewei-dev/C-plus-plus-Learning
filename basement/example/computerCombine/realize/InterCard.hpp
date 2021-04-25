#ifndef _INTER_CARD_H_
#define _INTER_CARD_H_

#include "../abstract/Card.hpp"
#include <iostream>
using namespace std;

class InterCard : public Card{
    public:
        virtual void display();
};

#endif
