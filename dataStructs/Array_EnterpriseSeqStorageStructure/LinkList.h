#ifndef LINK_LIST_H
#define LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// 链表小节点
typedef struct  LINKNODE{
    struct LINKNODE* next;
}LinkNode;

// 链表节点
typedef struct LINKLIST
{
    LinkNode head;
    int size;
}LinkList;


// 定义一个函数指针
typedef void(*PRINTFNODE)(LinkNode*);

// 定义一个比较的函数类型
typedef int(*COMPARENODE)(LinkNode*, LinkNode*);

// 1. 初始化链表
LinkList* Init_LinkList();  

// 2. 插入 需要注意，这里插入的是 LinkNode* 类型的数据
void Insert_LinkList(LinkList* list, int pos, LinkNode* data);

// 3. 删除
void RemoveByPos_LinkList(LinkList* list, int pos);

// 4. 返回链表大小
int Size_LinkList(LinkList* list);

// 5. 打印
void Print_LinkList(LinkList* list, PRINTFNODE print);

// 6. 释放内存空间
void FreeSpace_LinkList(LinkList* list);

// 7. 查找
int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare);

#endif

