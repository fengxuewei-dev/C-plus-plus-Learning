#include <iostream>
#include "../abstract/Card.hpp"
#include "../abstract/CPU.hpp"
#include "../abstract/Memory.hpp"
#include "../abstract/Computer.hpp"
#include "../realize/InterCpu.hpp"
#include "../realize/InterMemory.hpp"
#include "../realize/InterCard.hpp"
#include "../realize/NvidiaCard.hpp"
#include "../realize/Kingstor.hpp"

using namespace std;

/*
    computer 类包含了下面三个抽象类的接口

    1、CPU
    2、显卡
    3、内存条

    组装出来一台 Inter 的电脑
    组装出来一台 InterCpu、Kingston 内存、nvidia 显卡 的电脑

*/

/*
    分三个层次
    
    实现层
    抽象层
    业务层
*/

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    // 组装电脑
    CPU *interCpu = new InterCpu;
    Memory *interMemory = new InterMemory;
    Card *interCard = new InterCard;
    
    Computer *InterCom = new Computer(interCpu, interMemory, interCard);

    InterCom->work();

    Card *nividiaCard = new NividiaCard;
    Memory *kingstor = new Kingstor;

    Computer *com2 = new Computer(interCpu, kingstor, nividiaCard);
    com2->work();

    delete interCpu;
    delete interMemory;
    delete interCard;
    delete nividiaCard;
    delete kingstor;

    delete InterCom;
    delete com2;
}