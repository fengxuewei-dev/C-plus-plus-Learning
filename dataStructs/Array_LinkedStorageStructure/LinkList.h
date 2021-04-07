#ifndef LINK_LIST_H
#define LINK_LIST_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 线性表的链式存储：用不连续的内存空间、
 * 
 * 链表是由一系列的节点组成，每个节点包括两个域，指针域和数字域；需要指针域保存下一个节点的地址；
 * 当指针域指向为NULL，代表链表结束
 * 
 * 若想要插入一个新的节点。首先需要找到该位置的前一个节点，使用新的节点的指针域指向前一个节点的后一个节点；最后将前一个节点的指针域指向新的节点的首地址
 * 
 * 若想要删除一个节点，首先需要找到该节点和它前一个节点，其次让前一个节点的指针域指向该节点的下一个节点，最后让该节点的指针域设置为空，释放该节点的内存
 */

// 0-1. 链表节点
typedef struct LINKNODE{
    void* data;            // 无类型指针：使用无类型指针指向任意数据类型的数据
    struct LINKNODE* next;
}LinkNode;


// 0-2. 建立链表
typedef struct  LINKLIST{
    LinkNode* head;         // 头节点
    int size;               // 链表的大小
    // 不需要容量
}LinkList;
  

// 0-3 打印函数指针: 形参类型是 void*， 返回值是 void
typedef void(*PRINTLINKNODE)(void *);

// 1. 初始化链表
LinkList* Init_LinkList();

// 2. 在指定位置插入
void Insert_LinkList(LinkList* list, int pos, void* data);

// 3. 删除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos);

// 4. 获得链表的长度
int Size_LineList(LinkList* list);

// 5. 返回第一个节点
void* Front_LinkList(LinkList* list);

// 6. 释放链表内存
void FreeSpace_LinkList(LinkList* list);

// 7. 查找某个值 根据指针来查找某个值
int Find_LinkList(LinkList* list, void* data);

// 8. 打印链表节点 事先不知道data是什么类型的；开发者不确定的事情，让用户去完成
// 这样每一次打印的时候，调用用户传递进来的函数即可 print 是打印函数指针 
void Print_LinkList(LinkList* list, PRINTLINKNODE print);
 

#endif
