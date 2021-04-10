#ifndef __CIRCLES_H__
#define __CIRCLES_H__

#include <iostream>
#include "Point.hpp"

using namespace std;

class Circles{
    public:
        
        void setCo(const Point &);
        void setR(double);
        Point& getCo();
        double getR();

    private:
        Point m_c_o;
        double m_r;
};


#endif
