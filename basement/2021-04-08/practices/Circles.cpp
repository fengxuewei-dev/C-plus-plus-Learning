#include "Circles.h"

void Circles::setR(double r){
    m_r = r;
}
double  Circles::getR(){
    return m_r;
}
double  Circles::getGirth(){
    return 2 * M_PI * m_r;
}
double  Circles::getArea(){
    return M_PI * m_r * m_r;
}

// 判断一个点是否在圆内
bool Circles::JudgeInCircles(double p_x, double p_y){
    if(sqrt(pow(p_x - m_x,2) + pow(p_y - m_y, 2))>m_r){
        return false;
    }
    return true;
}

void Circles::setRXY(double r, double x, double y){
    m_r = r;
    m_x = x;
    m_y = y;
}