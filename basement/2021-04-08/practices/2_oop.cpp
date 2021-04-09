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