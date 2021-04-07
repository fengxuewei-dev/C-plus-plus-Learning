#include "LinkList.h"


// 1. 初始化链表
LinkList* Init_LinkList(){
    
    // 1-1 分配内存
    LinkList* list = (LinkList*)malloc(sizeof(LinkList));
    list->size = 0;

    // 1-2 保证头节点存在性：如果没有头节点需要考虑数据是否插入到头节点了；如果有头结点就不需要考虑这个问题；为了
    // 为了让链表实现起来思路更加清晰简单；带不带都可以，只不过是说带了头结点问题会变得简单
    list->head = (LinkNode*)malloc(sizeof(LinkNode));
    list->head->data = NULL;
    list->head->next = NULL;

    return list;

}

// 2. 在指定位置插入 链表的位置是从0开始的
void Insert_LinkList(LinkList* list, int pos, void* data){

    // 2-1 判断输入的有效性
    if(list == NULL){
        return;
    }
    if(data == NULL){
        return;
    }
    // 2-1 判断位置：pos 越界；pos < 0; 的时候，默认插入尾部
    if(pos < 0 || pos > list->size){
        pos = list->size;
    }

    // 2-2 创建新的节点
    LinkNode* newnode = (LinkNode*)malloc(sizeof(LinkNode));
    newnode->data = data;
    newnode->next = NULL;

    // 2-3 寻找 pos 的前一个节点
    LinkNode* pCurrent = list->head;    // 辅助指针变量; 先让它指向list的头结点
    for(int i = 0; i < pos; i++){
        pCurrent = pCurrent->next;
    }

    // 2-4 新节点入列表
    newnode->next = pCurrent->next;
    pCurrent->next = newnode;

    list->size++;
}

// 3. 删除指定位置的值
void RemoveByPos_LinkList(LinkList* list, int pos){
    // 3-1 判断输入的有效性
    if(list == NULL){
        return;
    }
    // 3-1 判断位置：pos 越界；pos < 0;
    if(pos < 0 || pos >= list->size){
        return;
    }

    // 3-2 寻找位置的前一个节点
    LinkNode* pCurrent = list->head;
    for(int i = 0; i < pos; i++){
        pCurrent = pCurrent->next;
    }

    // 3-3 删除节点
    LinkNode* pDel = pCurrent->next;
    pCurrent->next = pDel->next;

    // 3-4 释放空间 
    free(pDel);

    list->size--;

}

// 4. 获得链表的长度
int Size_LineList(LinkList* list){
    if(list == NULL){
        return -1;
    }

    return list->size;
}

// 5. 返回第一个节点
void* Front_LinkList(LinkList* list){
    return list->head->next->data;        // 若该链表为空，那么就返回NULL
}

// 6. 释放链表内存
void FreeSpace_LinkList(LinkList* list){
    if(list == NULL){
        return;
    }

    // 6-1 释放内存； 每一个节点的内存都是手动分配，所以每一个节点都需要手动释放，需要变量
    LinkNode* pCurrent = list->head;
    LinkNode* pNext = NULL;
    while(pCurrent != NULL){
        pNext = pCurrent->next;
        free(pCurrent);
        pCurrent = pNext;
    }

    // 6-2 释放链表内存
    free(pNext);
    list->size = 0;             // 可写可不写，习惯写上
    free(list);
}

// 7. 查找某个值 根据指针（地址）来查找某个值 
int Find_LinkList(LinkList* list, void* data){

    // 7-1 有效性判断
    if(list == NULL){
        return -1;
    }
    if(data == NULL){
        return -1; 
    }

    // 7-2 遍历查找
    LinkNode* pCurrent = list->head->next;      // 因为head不保存数据，所以将其执行head的下一个节点 
    int i = 0;
    for(; i < list->size; i++){
        if(pCurrent->data == data)
            break;
        pCurrent = pCurrent->next;
    }

    return i;
}

// 8. 打印链表节点 事先不知道data是什么类型的；开发者不确定的事情，让用户去完成
// 这样每一次打印的时候，调用用户传递进来的函数即可 print 是打印函数指针 
void Print_LinkList(LinkList* list, PRINTLINKNODE print){
    if(list == NULL){
        return;
    }

    // 打印数据
    LinkNode* pCurrent = list->head->next;
    while(pCurrent != NULL){
        // 打印数据，因为不知道数据类型，调用用户传进来的函数
        print(pCurrent->data);
        pCurrent = pCurrent->next;
    }

    printf("---------------------------------------\n");
}