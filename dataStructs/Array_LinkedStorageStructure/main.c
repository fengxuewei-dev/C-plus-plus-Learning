#include "LinkList.h"

// 自定义数据类型
typedef struct PERSON{
    char name[64];
    int age;
    int score;
}Person;

// test 函数
void test02();
void test03();
void test04();

// 用户自定义 打印函数
void myPrint(void*);

int main(int argc, char **argv){
    
    test04();
    
    return 0;
}

void test02(){
    // 1. 创建一个链表
    LinkList* list = Init_LinkList();

    // 2. 插入数据
    // 2-1 创建数据
    Person p1 = {"aaa", 18, 100};
    Person p2 = {"bbb", 17,  90};
    Person p3 = {"ccc", 16,  80};
    Person p4 = {"ddd", 15,  70};
    Person p5 = {"eee", 14,  60};

    // 2-2 数据插入链表 都插入第一个
    Insert_LinkList(list, 0, &p1); 
    Insert_LinkList(list, 0, &p2);
    Insert_LinkList(list, 0, &p3);
    Insert_LinkList(list, 0, &p4);
    Insert_LinkList(list, 0, &p5);

    // 3 打印数据
    Print_LinkList(list, myPrint);

    // 4 销毁链表
    FreeSpace_LinkList(list);    
}

void test03(){
    // 1. 创建一个链表
    LinkList* list = Init_LinkList();

    // 2. 插入数据
    // 2-1 创建数据
    Person p1 = {"aaa", 18, 100};
    Person p2 = {"bbb", 17,  90};
    Person p3 = {"ccc", 16,  80};
    Person p4 = {"ddd", 15,  70};
    Person p5 = {"eee", 14,  60};

    // 2-2 数据插入链表 都插入第一个
    Insert_LinkList(list, 0, &p1); 
    Insert_LinkList(list, 0, &p2);
    Insert_LinkList(list, 0, &p3);
    Insert_LinkList(list, 0, &p4);
    Insert_LinkList(list, 0, &p5);

    // 3 打印数据
    Print_LinkList(list, myPrint);


    // 4 删除数据 - 3号数据
    RemoveByPos_LinkList(list, 3);

    // 5 打印数据
    Print_LinkList(list, myPrint);

    // 6 销毁链表
    FreeSpace_LinkList(list);    
}

void test04(){
    // 1. 创建一个链表
    LinkList* list = Init_LinkList();

    // 2. 插入数据
    // 2-1 创建数据
    Person p1 = {"aaa", 18, 100};
    Person p2 = {"bbb", 17,  90};
    Person p3 = {"ccc", 16,  80};
    Person p4 = {"ddd", 15,  70};
    Person p5 = {"eee", 14,  60};

    // 2-2 数据插入链表 都插入第一个
    Insert_LinkList(list, 0, &p1); 
    Insert_LinkList(list, 0, &p2);
    Insert_LinkList(list, 0, &p3);
    Insert_LinkList(list, 0, &p4);
    Insert_LinkList(list, 0, &p5);

    // 3 打印数据
    Print_LinkList(list, myPrint);

    // Person* pe = (Person*)Front_LinkList(list);
    myPrint(Front_LinkList(list));

    // 4 销毁链表
    FreeSpace_LinkList(list);    
}

void myPrint(void* data){
    // 1. 将数据data进行类型转换
    Person* p = (Person*)data;

    // 2. 打印数据
    printf("Name: %s\t Age: %d\t Score: %d\n", p->name, p->age, p->score);
}