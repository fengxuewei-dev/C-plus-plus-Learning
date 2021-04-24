#include <iostream>

using namespace std;

/*
    纯虚函数和抽象类：
        抽象类中至少包含一个纯虚函数
        抽象类不能被实例化
    
    抽象类被继承之后，内部的纯虚函数必须全部被实例化，否则该子类也是一个抽象类，因为继承的关系

    纯虚函数
*/

class Shape{
    public:
        virtual double getArea() = 0;
};

class Retc : public Shape{
    public:
        Retc(int a, int b) :Shape(){
            this->a = a;
            this->b = b;
        }
        virtual double getArea(){
            return this->a * this->b;
        }

    private:
        int a;
        int b;
};

class Circle : public Shape{
    public:
        Circle(int r) :Shape(){
            this->r = r;
        }
        virtual double getArea(){
            return 3.14 * this->r * this->r;
        }

    private:
        int r;
};
void test01();

int main(void){
    test01();
    return 0;
}

// 业务层 面向抽象类编程，在main函数中，只需要关注 shape 类即可，子类中如何定义，是否有其他的方法 main 函数不会进行关心
void test01(){
    Shape *sp1 = new Retc(10, 20);
    cout << "sp1 = " << sp1->getArea() << endl;

    Shape *sp2 = new Circle(20);
    cout << "sp2 = " << sp2->getArea() << endl;
} 

// 当把 Retc 和 Circle 类进行分别定义，且在main函数中，分别定义相关类型的指针来进行实例化，那么这个时候main函数就和两个类存在耦合关系；随着内部类的个数增加，和main函数存在耦合关系的类越来越多... 耦合性越来越高
// 但是当把所有的类抽出来一个公共父类，那么main函数只需要和该父类进行关联 利用 多态特性，实现上面的目的 ==》 利用多态特性写一个架构函数 （架构函数只关心抽象类中的纯虚函数，对子类的其他的方法如何不进行关心）

// main() 是高层业务逻辑层
// 抽象类是 抽象层
// 继承抽象类的各个子类 是 实现层 

// 将main函数和 实现层进行解耦合 ==》 依赖倒转原则