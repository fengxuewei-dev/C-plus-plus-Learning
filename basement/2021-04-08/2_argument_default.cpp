#include <iostream>

/*
    函数的默认参数: 必须是从右往左
    函数的占位参数: 可以结合默认参数一起使用，但是这个是c++ 的一个坑，在运算符重载的时候，会使用到
*/

using namespace std;

void test01();

int getVolumn(int width, int length, int high = 10){
    cout << "width = " << width << endl;
    cout << "length = " << length << endl;
    cout << "high = " << high << endl;

    return width * length * high;
}

int fool1(int a, int = 0){ // 编译器获得函数原型就是int fool1(int, int ); 所以我们在使用的时候，需要给第二个变量也赋值，哪怕它没有用到.
// 当第二个参数和默认参数结合使用，就可以不需要为其进行赋值
    cout << "a = " << a << endl;
}

void test02();

int main(void){
    test02();
    return 0;
}

void test01(){
    int w = 10;
    int l = 5;
    int h = 6;

    int vol = getVolumn(w, l);

    cout << "volumn = " << vol << endl;
}   

void test02(){
    fool1(20, 10); 
    fool1(2);
}