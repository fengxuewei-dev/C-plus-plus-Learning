## 关于 c++ 面向对象以及面向过程的设计

### 1. 求圆的周长和面积

```c++
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
```

```bash
# c++ 多文件进行编译
# 头文件只是起到了声明的作用，因此需要编译 *.cpp 文件并链接使用即可
g++ -c Circles.cpp
g++ -c main.cpp


# g++ 在执行编译的时候，分为四步骤 -E, -S, -c, -o
# 1. 预处理，生成 .i 文件【使用的是 -E 参数】
# 2. 将预处理后的文件转换成汇编语言，生成文件 .s [使用的是 -S 参数]
# 3. 将汇编语言变为目标代码生成 .o 文件【使用-c参数】
# 4. 链接目标代码，生成可执行文件 【使用-o参数】
# 链接生成可执行文件
g++ main.o Circles.o -o main
```

### 2、求立方体是否相等

```c++
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
```



### 3、判断一个点是否在圆内

```c++
/*
    判断一个点是否在圆内
*/

#include "Circles.h"

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Circles c1;
    c1.setRXY(10, 5, 5);

    if(c1.JudgeInCircles(20, 20)){
        cout << "在圆内" << endl;
    }else{
        cout << "在圆外" << endl;
    }
}
```

```c++
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
```

```c++
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
```

```bash
g++ -c Circles.cpp
g++ -c 2_oop.cpp 

g++ 2_oop.cpp Circles.o -o 2_oop
```

![image-20210409105028629](/home/fengxuewei/c-plus-plus/C++/C-plus-plus-Learning/basement/2021-04-08/practices/image-20210409105028629.png)

![image-20210409105201232](/home/fengxuewei/c-plus-plus/C++/C-plus-plus-Learning/basement/2021-04-08/practices/image-20210409105201232.png)