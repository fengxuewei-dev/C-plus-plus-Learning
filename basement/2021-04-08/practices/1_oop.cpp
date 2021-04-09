/*
    设计一个立方体，求出立方体的面积和体积
    求两个立方体，是否相等（全局函数和成员函数）
*/
#include <iostream>

using namespace std;

class Cube{
public:
    // 面积
    double getArea();
    // 体积
    double getVol();

    // 判断是否相等
    bool isEqu(const Cube &cb);

    double getLength(){
        return m_length;
    }
    double getWidth(){
        return m_width;
    }
    double getHeight(){
        return m_height;
    }
    double setVal(double L, double W, double H){
        m_length = L;
        m_width = W;
        m_height = H;
    }
private:
    double m_length;
    double m_width;
    double m_height;
};

    // 面积
double Cube::getArea(){
    return 2 * (m_length * m_width + m_length * m_height + m_width * m_height);
}
    // 体积
double Cube::getVol(){
    return m_length * m_width * m_height;
}

    // 判断是否相等
bool Cube::isEqu(const Cube &cb){
    if(m_length == cb.m_length && m_width == cb.m_width && m_height == cb.m_height){ // 因为 cb 也是 cube ，而这个函数也是 cube 内部的成员函数，所以即使使用私有函数的成员，也有权限进行访问，== 同类无私处
        return true;
    }
    return false;
}
bool getIsEqu(Cube &cb1, Cube &cb2){
    if(cb2.getLength() == cb1.getLength() && cb2.getWidth() == cb1.getWidth() && cb2.getHeight() == cb1.getHeight()){
        return true;
    }
    return false;
}

int main(void){

    Cube c1, c2;
    c1.setVal(10,20,30);
    c2.setVal(10,20,40);
    cout << "the c1 area = " << c1.getArea() << endl;
    cout << "the c2 area = " << c2.getArea() << endl;

    cout << "the c1 Vol = " << c1.getVol() << endl;
    cout << "the c2 Vol = " << c2.getVol() << endl;

    cout << "c1 == c2? ==> " << c1.isEqu(c2) << endl;
    cout << "c1 == c2? ==> " << getIsEqu(c1,c2) << endl;

    return 0;
}