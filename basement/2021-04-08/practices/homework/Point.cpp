#include "Point.hpp"


void Point::setX(double x){
    m_x = x;
}

void Point::setY(double y){
    m_y = y;
}

double Point::getX(){
    return m_x;
}
double Point::getY(){
    return m_y;
}

double Point::getDistance(Point &p){
    return sqrt(
        (m_x - p.m_x) * (m_x - p.m_x) +
        (m_y - p.m_y) * (m_y - p.m_y)
    );
}