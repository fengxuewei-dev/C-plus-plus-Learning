#include <iostream>
#include <cmath>

using namespace std;

class Circles{
public:
    void setRXY(double r, double x, double y);
    void setR(double r);
    double getR();
    double getGirth();
    double getArea();

    // 判断一个点是否在圆内
    bool JudgeInCircles(double p_x, double p_y);

private:
    double m_r;
    double m_x;
    double m_y;
};