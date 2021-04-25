#include <iostream>

using namespace std;

/*
    C语言中的数组类型

    定义方法1：typedef 定义新的数据类型 ARRAY_INT_10 数组指针 array 数组名字
    定义方法2：typedef 定义新的数组指针类型]
    定义方法3：直接使用数组指针类型进行定义数组
*/


// 1、直接定义一个数组类型
typedef int(ARRAY_INT_10)[10];

// 2、定义一个数组指针类型
typedef int(*ARRAY_INT_10_POINTER)[10];

void test01();
void test02();
void test03();

int main(void){
    test03();
    return 0;
}

void test03(){
    int array[10];

    int(*p)[10] = &array; // int *p[10] 指针数组 p[10] 先进行结合形成一个数组 数组中的每一个类型都是 int * 所以是指针数组
    // int (*p)[10] 说明 p 是一个指针，该指针指向 int[10]的数组 ==》 数组指针

    for(size_t i = 0; i < 10 ; i++){
        (*p)[i] = i + 10;
    }

    for(size_t i = 0; i < 10; i++){
        cout << array[i] << endl;
    }
}
void test02(){
    int array[10];
    ARRAY_INT_10_POINTER array_i_10 = &array; // array_i_10 ==== array

    // 通过数组指针来为 array 进行赋值
    for(size_t i = 0; i<10; i++){
        (*array_i_10)[i] = i + 10;
    }

    for(size_t i = 0; i < 10; i++){
        cout << array[i] << endl;
    }

}
void test01(){

    // 方法1
    int array[10];      // array 是一个 int * 的指针 执行 array+1 的时候，会上移一个int类型数据

    ARRAY_INT_10 *array_i_10 = &array;    // 执行 array_i_10 的时候，会移动10个int类型数据的大小空间 此时二代 *array_i_10 ==== array 

    // 通过数组指针来为 array 进行赋值
    for(size_t i = 0; i<10; i++){
        (*array_i_10)[i] = i + 10;
    }

    for(size_t i = 0; i < 10; i++){
        cout << array[i] << endl;
    }

    
}