#include <iostream>
#include <cmath>

// 同类之间无私处，异类对象有友元
/*
计算两个点之间的距离
    1. 使用全局函数来计算
    2. 使用类的成员函数来计算

    那么如果该函数经常倍调用，那么就会经常来访问该类的私有成员，就会调用类的函数来访问该私有成员函数，需要压栈和出栈的内存和时间开销。那么存不存在这样一个函数，让该函数直接访问 p1.x, p2.x, 获取私有成员，不需要调用函数来访问私有成员。

    那么我们在类的外部没有办法实现，因为是私有成员
    那么c++中规定，若当前某个函数是我这个类的一个朋友，那么你就可以通过点运算符来访问我的私有成员变量，-- 俗称该哥们 为 该类的友元函数

    3. 在类中声明该类的友元函数，切记是声明，不能是定义。这个声明可以写在类中的任何地方。
        可以是 访问限制符号的前面，私有访问符号内部，均可。那么该友元类就可以访问的我的私有成员。(全员函数)
    
    但是该方法会在一定程度上破坏类的封装性和隐藏性。一般不介意这样做

    友元函数

    4. 如果一个类的函数需要作为另外一个类的友元，需要如何去做呢？
        定义该类，将该类中的是这个函数定义放在另外那个类的定义后面.
*/

using namespace std;

class Point; // 声明该类，但是没有告诉编译器这个类内部的的数据有哪些，所以若将类中的函数定义为另外一个类的友元函数的时候，需要将其实现体放在这个类定义的下面，让内部的访问指定数据的存放位置，可以访问到即可
// 4
class PointManager{
    public:
        double getDistance(Point& p1, Point& p2);
};

class Point{
    // 3. 只是声明
    // friend double getDistance(Point& p1, Point& p2);

    // 4.

    friend double PointManager::getDistance(Point& p1, Point& p2);
    public:

        Point(double x, double y){
            this->m_x = x;
            this->m_y = y;
        }

        double getX() const{
            return this->m_x;
        }

        double getY() const{
            return this->m_y;
        }

        // 2. 
        // double getDistance(Point &p) const{ // double getDistance(Point &p) const{}  this is the const Test * const this.
        //     double dd_x = this->m_x - p.m_x;
        //     double dd_y = this->m_y - p.m_y;

        //     return sqrt(dd_x * dd_x + dd_y * dd_y);
        // }
    private:
        double m_x;
        double m_y;
};
// 4.
double PointManager::getDistance(Point& p1, Point& p2)
{
    double dd_x = p1.m_x - p2.m_x;
    double dd_y = p1.m_y - p2.m_y;

    double res = sqrt(dd_x * dd_x + dd_y * dd_y);
    return res;
}

// 1. 计算两个点之间的距离
// double getDistance(const Point* p1, const Point* p2){
//     double dd_x = p1->getX() - p2->getX();
//     double dd_y = p1->getY() - p2->getY();

//     double res = sqrt(dd_x * dd_x + dd_y * dd_y);
//     return res;
// }

// 3.
// double getDistance(Point& p1, Point& p2){
//     double dd_x = p1.m_x - p2.m_x;
//     double dd_y = p1.m_y - p2.m_y;

//     double res = sqrt(dd_x * dd_x + dd_y * dd_y);
//     return res;
// }
void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Point p1(20, 30);
    Point p2(40, 30);

    PointManager pm;
    // 1.
    // cout << getDistance(&p1, &p2) << endl;

    // 2.
    // cout << p1.getDistance(p2) << endl;

    // 3.
    // cout << getDistance(p1, p2) << endl;

    // 4. 
    cout << pm.getDistance(p1, p2) << endl;
}