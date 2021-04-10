#ifndef ____POINT_H_
#define ____POINT_H_

#include <iostream>
#include <cmath>

class Point{
    public:
        
        void setX(double);
        void setY(double);
        double getX();
        double getY();

        double getDistance(Point &p);

    private:

        double m_x;
        double m_y;

};


#endif