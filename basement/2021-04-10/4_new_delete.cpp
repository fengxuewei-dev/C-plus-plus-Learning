#include <iostream>
#include <cstring>

/*
    new & delete: 是运算符 不是函数名字 取代了 malloc 和 free

    创建一个变量，我们只是讨论了在栈上创建，没有考虑如何在堆上进行创建


    int *p = new int;       delete p;
    int *p1 = new int[10];  delete[] p1; // delete [] p1;
    int *p2 = new int(10);  delete p2;

    char *p = (char*)malloc(sizeof(char)*len);
                            free(p);

*/
using namespace std;

void test01(){

    // 在 c 语言中
    int *p = (int *)malloc(sizeof(int));    // 在堆上开辟了4个字节，返回一个地址给指针p
    *p = 10;
    printf("%d\n", *p);
    if(p != NULL){
        free(p);
        p = NULL;
    }

    // 开辟一个数组
    char *name = (char*)malloc(sizeof(char) * 64);
    strcpy(name, "helloworld");
    printf("%s\n", name);
    if(name != NULL){
        free(name);
        name = NULL;
    }

}
void test02(){

    // c++ 
    int *p1 = new int;   // 使用new运算符来开辟 空间大小的为 new 的字节数空间，并且将该地址返回给p
    *p1 = 10;
    cout << *p1 << endl;
    if(p1 != NULL){
        delete p1;
        p1 = NULL;
    }

    int *p = new int[10];   // 开辟一个数组空间，大小为10个 int类型的数据
    // int *p = new int(10);   // 开辟一个地址空间，切为该地址空间赋值为10

    for(int i = 0; i < 10; i++){
        p[i] = i+1;
    }
    for(int i = 0; i < 10; i++){
        cout << p[i];
    }
    if(p != NULL){
        delete[] p;
        p = NULL;
    }

    cout << endl;
}

int main(void){
    test02();
    return 0;
}