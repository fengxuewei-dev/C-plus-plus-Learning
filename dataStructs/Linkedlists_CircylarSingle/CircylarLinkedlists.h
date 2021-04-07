#ifndef CIRCYLAR_LINKED_LISTS_SINGLE_H
#define CIRCYLAR_LINKED_LISTS_SINGLE_H


#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/**
 * 单向循环链表：每个节点都有一个数据域和一个指针域，这个和单向链表是一致的。但是
 * 不一样的地方是，单向循环链表的最后一个节点的指针域不为NULL，它指向头节点也可以
 * 指向第一个有效的数据节点。这些都是单向循环链表，我们一般让其指向头结点
 * 
 * 在初始化的时候，应该将头结点的next域指向自己
 * 
 * 判断链表末尾的方式：
 * 1. 节点 next 是否等于 头结点 ==> 表示该链表结束
 * 2. 通过维护 size() 来判断是否 是该链表结束标志
 */

// 链表的挂钩
typedef struct CIRCYLARLINKNODE{
    struct CIRCYLARLINKNODE* next;
}CircylarLinkNode;


// 链表的结构体：保存的就是关于该链表的一些详细信息
typedef struct CIRCYLARLINKLIST{
    CircylarLinkNode head;
    int size;
}CircylarLinkList;

#define CIRCYLARTLINKLIST_TRUE  1
#define CIRCYLARTLINKLIST_FALSE 0

// 当两个元素相同的话，返回0；否则返回-1
typedef int(*COMPARENODE)(CircylarLinkNode*, CircylarLinkNode*); // 比较的回调函数

typedef void(*PRINTNODE)(CircylarLinkNode*);

// APIs

// 1. 初始化函数
CircylarLinkList* Init_CircylarLinkList();

// 2. 插入函数(插入位置，插入的数据)
void Insert_CircylarLinkList(CircylarLinkList* clist, int pos, CircylarLinkNode* data);

// 3. 获得第一个元素
CircylarLinkNode* Front_CircylarLinkList(CircylarLinkList* clist);

// 4. 根据位置删除
void RemoveByPos_CircylarLinkList(CircylarLinkList* clist, int pos);

// 5. 根据元素值来删除
void RemoveByVal_CircylarLinkList(CircylarLinkList* clist, CircylarLinkNode* data, COMPARENODE compare);

// 6. 获得链表的长度
int Size_CircylarLinkList(CircylarLinkList* clist);

// 7. 查找元素
int Find_CircylarLinkList(CircylarLinkList* clist, CircylarLinkNode* data, COMPARENODE compare);

// 8. 打印链表
void Print_CircylarLinkList(CircylarLinkList* clist, PRINTNODE print);

// 9. 释放内存
void FreeSpace_CircylarLinkList(CircylarLinkList* clist);

// 10. 判断是否为空
int IsEmpty_CircylarLinkList(CircylarLinkList* clist);

#endif
