#include <iostream>
#include <cmath>
/*
    求圆的面积和周长
    数据处理：
            输入半径r
            计算周长 = 2 pi r
            计算面积 = pi r ^ 2
            输出半径、周长、面积
*/
using namespace std;

class Circles{
    public:

        void set_r(double new_r){
            m_r = new_r;    
        }

        double get_area(){
            return M_PI * pow(m_r, 2);
        }
        double get_length(){
            return 2 * M_PI * m_r;
        }

    private: // 一般写一个类的私有成员是，m_ 开头 m 代表 my / me
    // 定义全局变量的时候命名使用 g_
    // 在定义函数名字的时候，起的名字需要规则保持一致 
        double m_r;     
        double m_girth;         // 圆的周长
        double m_area;          // 圆的面积

        // 直接通过下面的方式来进行求解是不可以的
        // double m_girth = m_r * 2 * M_PI;
        // double m_area = m_r * m_r * M_PI;

        /*
            在一个类中，成员变量占据一定的内存空间，方法是不占据内存的空间
            当我们定义了一个 Circle 对象的时候，系统就会在 内存上为成员变量开辟一个空间

            当是成员变量在初始化之前是一个随机数字，是一个乱码；这个时候当 m_r 是一个随机值，导致m_girth, m_area 都是关于该随机值的一个计算结果。
            当初始化该类之后，为 m_r 赋初始值， 这个时候m_girth m_area 并没有重新计算，使用的换是初始化之前计算的数据，因此不准确
        */

};

void test01();
int main(void){
    test01();
    return 0;
}
void test01(){
    double r = 0;
    Circles c1;

    cout << "Input the radius of the circles: ";
    cin >> r;

    c1.set_r(r);
    cout << "the area = " << c1.get_area() << endl;
    cout << "the length = " << c1.get_length() << endl;

}