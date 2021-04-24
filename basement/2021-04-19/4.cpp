#include <iostream>

using namespace std;

// 多态的好处是：在早期完成的代码，进行优化的时候，可以不动之前的代码，来实现优化更新 只需要之前写的代码中有父类的指针或者引用
// 架构师的工作就是搭建一个可复用性较高的架构

// 动态联编和静态联编:这个是编译器的概念,多态的实现机制是 动态联编, 不是事先确定好的. 是根据具体的参数值来进行指定的.
// 动态联编 == 晚期联编 == 迟邦定

class Hero{
    public:
        virtual int getAd(){
            return 10;
        }
};

class SuperHero : public Hero{
    public:
        int getAd(){
            return 2000;
        }
};

class Monster{
    public:
        int getAd(){
            return 100;
        }
};

void fight(Hero *hp, Monster *mp){
    if (hp->getAd() > mp->getAd())
    {
        cout << "hero is winned!" << endl;
    }else{
        cout << "hero is dead!" << endl;
    }
}

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    Hero hid;
    hid.getAd();

    Monster m;
    m.getAd();

    SuperHero sp;

    fight(&sp, &m);

}