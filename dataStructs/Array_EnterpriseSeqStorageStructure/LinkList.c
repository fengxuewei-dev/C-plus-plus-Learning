    #include "LinkList.h"

    // 1. 初始化链表
    LinkList* Init_LinkList(){
        // 这个时候头结点就不需要分配内存L
        LinkList* list = (LinkList*)malloc(sizeof(LinkList));

        list->head.next = NULL;
        list->size = 0;

        return list;
    }  

    // 2. 插入 需要注意，这里插入的是 LinkNode* 类型的数据
    void Insert_LinkList(LinkList* list, int pos, LinkNode* data){

        // 2-1 判定参数的有效性
        if(list == NULL){
            return;
        }
        if(data == NULL){
            return;
        }

        // 插入末尾
        if(pos < 0 || pos > list->size){
            pos = list->size;
        }

        // 2-2 插入节点
        // 2-2-1 查找插入位置
        LinkNode* pCurrent = &(list->head);
        for(int i = 0; i < pos; i++){
            pCurrent = pCurrent->next;
        }

        // 2-2-2 插入新节点 串接的是地址域
        data->next = pCurrent->next;
        pCurrent->next = data;

        list->size++;
    }

    // 3. 删除
    void RemoveByPos_LinkList(LinkList* list, int pos){

        if(list == NULL){
            return;
        }

        if(pos < 0 || pos >= list->size){
            return;
        }

        LinkNode* pCurrent = &(list->head);
        for(int i = 0; i < pos; i++){
            pCurrent = pCurrent->next; 
        }

        // 删除内存：注意这里 插入的linkNode的时候并没有使用malloc来分配内存，所以释放内存的时候不需要使用free
        pCurrent->next = pCurrent->next->next;
        list->size--;
    }

    // 4. 返回链表大小
    int Size_LinkList(LinkList* list){
        return 0;
    }

    // 5. 打印
    void Print_LinkList(LinkList* list, PRINTFNODE print){
        if(list == NULL){
            return;
        }

        LinkNode* pCurrent = list->head.next;   // 第一个有效值
        while(pCurrent != NULL){
            print(pCurrent);
            pCurrent = pCurrent->next;
        }

        printf("---------------------------------\n");

    }

    // 6. 释放内存空间
    void FreeSpace_LinkList(LinkList* list){
        if(list == NULL){
            return;
        }

        free(list);
    }

    // 7. 查找
    int Find_LinkList(LinkList* list, LinkNode* data, COMPARENODE compare){
        if(list == NULL){
            return -1;
        }
        if(data == NULL){
            return -1;
        }

        // 定义辅助变量，因为是需要查找，所以辅助变量初始化为头结点的next位置
        LinkNode* pCurrent = list->head.next;
        int index = 0;   
        int flag = -1;
        while (pCurrent != NULL)
        {
            // 找到逻辑的判断
            // 需要一个比较的函数指针和遍历的函数指针
            if(compare(pCurrent, data) == 0) // 相等返回0
            {
                flag = index;
                break;
            }
            // 遍历下一个
            pCurrent = pCurrent->next;
            index++;    // 遍历是从第0开始
        }
        
        return flag;
    }
