#include "LinkList.h"


/**
 * 1. 首先定义数据类型，内部包含了 LinkNode 小挂钩(内部存放下一个节点地址) 和 数据域(内部存放name 和 age)
 * 定义其对象P1
 * 2. 使用一个LinkNode指针来指向 该对象 P1 地址且进行强制转换为 LinkNode 类型
 * (指针赋值相互操作的机制，因为是 指针类型是 LinkNode 类型， 而Person 第一个数据也是该类型
 * 所以使用该指针可以访问到第一快内存，若想访问到下面几个数据，需要手动计算需要跳过的字节数，获得其地址来进行访问)
 * 3. 插入的时候，只需要插入的 LinkNode 指针，也就是数据对象的地址就可以了
 * 相当于把地址串起来，使用的时候，获得该地址，再将其强转获得数据即可。
 */
typedef struct PERSON{
    LinkNode node; // 小挂钩 相等于一个next
    char name[64];
    int age;
}Person;

void test01();
void test02();
void test03();
void Myprint(LinkNode*);
int Mycompare(LinkNode*, LinkNode*);

int main(int argc, char**argv){

    test03();

    return 0;
}

void test01(){
    // 创建 一个链表
    LinkList* list = Init_LinkList();

    // 创建数据
    Person P1, P2, P3, P4, P5;
    strcpy(P1.name, "aaa");
    strcpy(P2.name, "bbb");
    strcpy(P3.name, "ccc");
    strcpy(P4.name, "ddd");
    strcpy(P5.name, "eee");

    P1.age = 10;
    P2.age = 20;
    P3.age = 30;
    P4.age = 40;
    P5.age = 50;

    // 将节点插入到列表
    Insert_LinkList(list, 0, (LinkNode*)&P1);   // 这个data只能访问到 Person 中的 LinkNode 变量
    Insert_LinkList(list, 0, (LinkNode*)&P2); 
    Insert_LinkList(list, 0, (LinkNode*)&P3); 
    Insert_LinkList(list, 0, (LinkNode*)&P4); 
    Insert_LinkList(list, 0, (LinkNode*)&P5); 


    // 打印
    Print_LinkList(list, Myprint);


    // 释放内存
    FreeSpace_LinkList(list);
}

void test02(){
    // 创建 一个链表
    LinkList* list = Init_LinkList();

    // 创建数据
    Person P1, P2, P3, P4, P5;
    strcpy(P1.name, "aaa");
    strcpy(P2.name, "bbb");
    strcpy(P3.name, "ccc");
    strcpy(P4.name, "ddd");
    strcpy(P5.name, "eee");

    P1.age = 10;
    P2.age = 20;
    P3.age = 30;
    P4.age = 40;
    P5.age = 50;

    // 将节点插入到列表
    Insert_LinkList(list, 0, (LinkNode*)&P1);   // 这个data只能访问到 Person 中的 LinkNode 变量
    Insert_LinkList(list, 0, (LinkNode*)&P2); 
    Insert_LinkList(list, 0, (LinkNode*)&P3); 
    Insert_LinkList(list, 0, (LinkNode*)&P4); 
    Insert_LinkList(list, 0, (LinkNode*)&P5); 


    // 打印
    Print_LinkList(list, Myprint);

    // 删除节点
    RemoveByPos_LinkList(list, 2);  

    // 打印
    Print_LinkList(list, Myprint);

    // 释放内存
    FreeSpace_LinkList(list);
}

void test03(){
    // 创建 一个链表
    LinkList* list = Init_LinkList();

    // 创建数据
    Person P1, P2, P3, P4, P5;
    strcpy(P1.name, "aaa");
    strcpy(P2.name, "bbb");
    strcpy(P3.name, "ccc");
    strcpy(P4.name, "ddd");
    strcpy(P5.name, "eee");

    P1.age = 10;
    P2.age = 20;
    P3.age = 30;
    P4.age = 40;
    P5.age = 50;

    // 将节点插入到列表
    Insert_LinkList(list, 0, (LinkNode*)&P1);   // 这个data只能访问到 Person 中的 LinkNode 变量
    Insert_LinkList(list, 0, (LinkNode*)&P2); 
    Insert_LinkList(list, 0, (LinkNode*)&P3); 
    Insert_LinkList(list, 0, (LinkNode*)&P4); 
    Insert_LinkList(list, 0, (LinkNode*)&P5); 


    // 打印
    Print_LinkList(list, Myprint);


    // 查找
    Person findP;
    strcpy(findP.name, "ccc");
    findP.age = 30;
    printf("pos = %d\n", Find_LinkList(list, (LinkNode*)&findP, Mycompare));

    // 释放内存
    FreeSpace_LinkList(list);
}

void Myprint(LinkNode* data){
    // 1. 将数据类型再次转回来
    Person* p = (Person*)data;

    // 2. 打印数据
    printf("Name: %s\t Age: %d\n", p->name, p->age);
}

int Mycompare(LinkNode* node1, LinkNode* node2){

    // 1. 将数据类型再次转回来
    Person* p1 = (Person*)node1;
    Person* p2 = (Person*)node2;

    // 2. 判断
    if(strcmp(p1->name, p2->name) == 0 && p1->age == p2->age){
        return 0;
    }
    return -1;
}