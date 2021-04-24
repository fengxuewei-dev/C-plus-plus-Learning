#include <iostream>
/*
    多重继承和虚继承
    多继承内部需要主要的一个概念就是虚继承

   继承关系出现菱形的时候，使用虚继承 虚继承的作用：防止多重继承之后，出现同名变量指代不明确的问题

*/
using namespace std;

class Furniture{
    public:
        int m;  // 材质
};

class Bed : virtual public Furniture{
    public:
        void sleep(){
            cout << "sleeping on the bed..." << endl;
        }
};

class Sofa : virtual public Furniture{
    public:
        void sit(){
            cout << "sit on the sofa..." << endl;
        }
};

class SofaBed : public Bed, public Sofa{
    // 因为 Furniture 类中包含了 成员 m, 同时 bed 和 sofa 都是该类的派生类，那么该类的又是该两个类的派生类，那么该类中就包含了两个 变量 a。该类中包含了两个材质，不合常理
    // 1、SofaBed sb; sb.Bed::m = 20; sb.Sofa::m = 10;
    // 2、上面的方法比较麻烦，所以我们使用另外一个关键字virtual。即可。当检测到 Bed 和 Sofa 类继承方式为虚继承（virtual） 的时候，SofaBed 继承出现同名变量的时候，从 Furniture 中进行继承该变量
};

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    SofaBed sb;
    sb.sleep();
    sb.sit();

    sb.m = 20;  // 虚继承
}