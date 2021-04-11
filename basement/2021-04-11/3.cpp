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


    malloc 和 new 可以互换
    free 和 delete 可以互换
        他们之间的底层实现关系是相似的，有什么区别呢？
            malloc and free 是函数， 是标准库中的函数
            new and delete 是c++中的操作，是集成出来的
            因此后者在调用的时候没有函数的入栈和出栈的操作，效率更高
                new 在定义一个对象的时候，会触发该对象的构造函数（有参数、无参数）、malloc没有该功能
                delete 在释放一块内存空间的时候，会触发该对象的析构函数、free没有该功能，需要手动来调用
                deleta 在释放该空间之前，先触发析构函数，之后释放空间内存
    
    AA *a1 = new AA(12, 2); // new 会触发一个类的构造函数
*/
using namespace std;

class AA{
    public:
        AA(){
            m_x = 0;
            m_y = 0;
        }
        AA(double x, double y){
            m_x = x;
            m_y = y;
        }
        ~AA(){
            cout << "~AA()" << endl;
        }
        void printXY(){
            cout << "x = " << m_x << ", y = " << m_y << endl;
        }
    private:    
        double m_x;
        double m_y;
};

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


void test03(){
    // 在c语言中，创建一个类的对象，为其在堆上开辟内存空间
    AA *a1 = (AA*)malloc(sizeof(AA)); // 为其开辟了空间之后，没有办法为其赋值，只能手动调用初始化方法Init
    AA a2(2,3);
    a1 = &a2;
    a1->printXY();
    a2.printXY();
    if(a1 != NULL){
        free(a1);
        a1 = NULL;
    }
    // free(a1);
}
void test04(){
    // 在c++ 中，创建一个类的对象，为其在堆上开辟空间
    AA *a1 = new AA; // 触发无参数构造函数
    // AA *a1 = new AA(12, 2); // 触发有参数构造函数

    a1->printXY();

    if(a1 != NULL){
        delete a1;
        a1 = NULL;
    }
}
int main(void){
    test04();
    return 0;
}