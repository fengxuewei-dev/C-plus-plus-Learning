#include "Circles.hpp"


void Circles::setCo(const Point &p){
    m_c_o = p;
}
void Circles::setR(double r){
    m_r = r;
}
Point& Circles::getCo(){
    return m_c_o;
}
double Circles::getR(){
    return m_r;
}