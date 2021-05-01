#include <iostream>

using namespace std;

/*
    栈解旋：
*/

class Person{
    public:
        Person(){
            cout << "Person()" << endl;
        }
        ~Person(){
            cout << "~Person()" << endl;
        }
};
int divide(int x, int y){
    Person p1, p2;

    if(y == 0){
        throw y; // 栈解旋：当这个抛出异常的时候，那么在这个之前的定义的对象都会被自动析构掉,之后再将异常抛出； 类似于 return
    }
    return x / y;
}


void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    try{
        divide(10,0);
    }catch(int e){
        cout << "异常捕获: " << e << endl;
    }
}