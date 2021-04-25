#ifndef _NIVIDIA_CARD_H_
#define _NIVIDIA_CARD_H_

#include "../abstract/Card.hpp"
#include <iostream>

class NividiaCard : public Card{
    public:
        virtual void display();
};

#endif
