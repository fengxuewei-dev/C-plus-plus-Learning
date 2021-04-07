#include "CircylarLinkedlists.h"


// 1. 初始化函数
CircylarLinkList* Init_CircylarLinkList(){

    CircylarLinkList* clist = (CircylarLinkList*)malloc(sizeof(CircylarLinkList));

    clist->head.next = &(clist->head); 
    clist->size = 0;

    return clist;
}

// 2. 插入函数(插入位置，插入的数据)
void Insert_CircylarLinkList(CircylarLinkList* clist, int pos, CircylarLinkNode* data){
    if(clist == NULL){
        return;
    }
    if(data == NULL){
        return;
    }
    if(pos < 0 || pos > clist->size){
        pos = clist->size;
    }

    // 查找前一个节点
    CircylarLinkNode* pCurrent = &(clist->head); 
    for(int i = 0; i < pos; i++){
        pCurrent = pCurrent->next; 
    }

    // 入链表
    data->next = pCurrent->next;
    pCurrent->next = data;

    clist->size++;
}

// 3. 获得第一个元素
CircylarLinkNode* Front_CircylarLinkList(CircylarLinkList* clist){
    return clist->head.next;
}

// 4. 根据位置删除
void RemoveByPos_CircylarLinkList(CircylarLinkList* clist, int pos){
    if(clist == NULL){
        return;
    }
    if(pos < 0 || pos >= clist->size){
        return;
    }

    // 查找前一个节点
    CircylarLinkNode* pCurrent = &(clist->head); 
    for(int i = 0; i < pos; i++){
        pCurrent = pCurrent->next; 
    }

    // 删除操作，这里不需要 free 操作，因为这个 CircylarLinkNode 并不是我们通过手动来分配内存的.
    pCurrent->next = pCurrent->next->next;

    clist->size--;
}

// 5. 根据元素值来删除
void RemoveByVal_CircylarLinkList(CircylarLinkList* clist, CircylarLinkNode* data, COMPARENODE compare){
    if(clist == NULL){
        return;
    }
    if(data == NULL){
        return;
    }

    CircylarLinkNode* pPrevious = &(clist->head);
    CircylarLinkNode* pCurrent = clist->head.next;
    // while(pCurrent != NULL){
    //     if(compare(pCurrent, data) == 0){
            
    //     }
    //     // next 节点
    //     pCurrent = pCurrent->next;
    // }
    for (int i = 0; i < clist->size; i++){
        if (compare(pCurrent, data) == CIRCYLARTLINKLIST_TRUE)
        {
            // 删除
            pPrevious->next = pCurrent->next;

            clist->size--;
         
            break;
        }
        pPrevious = pCurrent;
        pCurrent = pPrevious->next;
    }
}

// 6. 获得链表的长度
int Size_CircylarLinkList(CircylarLinkList* clist){
    return clist->size;
}

// 7. 查找元素
int Find_CircylarLinkList(CircylarLinkList* clist, CircylarLinkNode* data, COMPARENODE compare){
    if(clist == NULL){
        return -1;
    }
    if(data == NULL){
        return -1;
    }

    CircylarLinkNode* pCurrent = clist->head.next;
    int i = 0;
    int flag = -1;
    for (; i < clist->size; i++)
    {
        if(compare(pCurrent,data) == 0){
            flag = i;
            break;
        }
        pCurrent = pCurrent->next;
    }
    
    return flag;
}

// 8. 打印链表
void Print_CircylarLinkList(CircylarLinkList* clist, PRINTNODE print){
    if(clist == NULL){
        return;
    }

    CircylarLinkNode* pCurrent = clist->head.next;
    for(int i = 0; i < clist->size; i++){ //
        print(pCurrent);
        pCurrent = pCurrent->next;
    }
    printf("---------------------------------\n");
    
    // 打印多遍
    // for(int i = 0; i < clist->size * 3; i++){ 
    //     if(pCurrent == &(clist->head)){
    //         pCurrent = pCurrent->next;
    //         printf("---------------------------------\n");
    //     }
    //     print(pCurrent);
    //     pCurrent = pCurrent->next;
    // }
}

// 9. 释放内存
void FreeSpace_CircylarLinkList(CircylarLinkList* clist){
    if(clist == NULL){
        return;
    }

    free(clist);
}

// 10. 判断是否为空
int IsEmpty_CircylarLinkList(CircylarLinkList* clist){
    if(clist->size == 0){
        return CIRCYLARTLINKLIST_TRUE;
    }
    return CIRCYLARTLINKLIST_FALSE;
}
