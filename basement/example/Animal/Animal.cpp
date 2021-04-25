#include "Animal.hpp"


Animal::Animal(){
}
Animal::~Animal(){

}

// 架构函数  此时我们就可以将一个匿名函数作为参数传入到该函数中，在该函数中会进行释放内存空间，不需要担心内存泄露
void printAni(Animal *ap){
    ap->voice();

    if(ap != NULL){
        delete ap;
    }
}