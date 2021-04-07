#include "DynamicArray.h"

/**
 * @file    DynamicArray.c
 * @brief   线性表的顺序存储操作
 * @author  fengxuewei
 * @return  Dynamic_Array
 */

// 1. 初始化
Dynamic_Array* Init_Dynamic_Array(){
    // 1.1 为结构体分配内存空间
    Dynamic_Array* myArray = (Dynamic_Array*)malloc(sizeof(Dynamic_Array));

    // 1.2 初始化
    myArray->size = 0;
    myArray->capacity = 20; // 初始化 给定特定的空间
    myArray->pAddr = (int *)malloc(sizeof(int)*myArray->capacity);

    return myArray;
}

// 2. 插入 默认的是在尾部插入，不需要指定插入位置；需要整个数组，需要插入的元素值
void PushBack_Dynamic_Array(Dynamic_Array* arr, int val){
    // 需要考虑内存是否充足
    
    // 2.1 判断数组是否为空
    if(arr == NULL){
        return;
    }

    // 2.2 判断空间是否充足; 不足就进行扩容
    if(arr->size == arr->capacity){

        // 2.2.1 扩展空间 -- 申请一个更大的内存空间 默认新空间是旧空间的2倍
        int* newSpace = (int *)malloc(sizeof(int)*arr->capacity*2);

        // 2.2.2 拷贝数据到新空间 memcpy 按照字节进行拷贝，所以下面需要再次乘以 sizeof(int)
        memcpy(newSpace, arr->pAddr, arr->capacity * sizeof(int));

        // 2.2.3 释放旧空间的内存
        free(arr->pAddr);

        // 2.2.4 更新容量
        arr->capacity = arr->capacity * 2;
        arr->pAddr = newSpace;
         
    }

    // 2.3 插入新元素
    arr->pAddr[arr->size] = val;
    arr->size++;
}

// 3. 删除1: 根据位置删除 整个数组，需要删除的位置
void RemoveByPos_Dynamic_Array(Dynamic_Array* arr, int pos){
    // 3.1 判断是否为空
    if(arr == NULL){
        return;
    }

    // 3.2 判断位置是否有效
    if(pos < 0 && pos >= arr->size){
        // 位置无效
        return;
    }

    // 3.3 删除元素
    for(int i = pos; i < arr->size - 1; i++){
        arr->pAddr[i] = arr->pAddr[i+1];
    }

    arr->size--;
}

// 4  删除2：根据值删除 删除这个值第一次出现的位置
void RemoveByVal_Dynamic_Array(Dynamic_Array* arr, int val){
    if(arr == NULL){
        return;
    }

    // 4.1 找到值的位置
    int pos = Find_Dynamic_Array(arr, val);

    // 4.2 根据位置删除数据
    RemoveByPos_Dynamic_Array(arr, pos);
}

// 5. 查找
int Find_Dynamic_Array(Dynamic_Array* arr, int val){
    if(arr == NULL){
        return -1;
    }

    int pos = -1;
    for(int i = 0; i < arr->size; i++){
        if(arr->pAddr[i] == val){
            pos = i;
            break;
        }
    }

    return pos;
}

// 6. 释放动态数组的内存
void FreeSpace_Dynamic_Array(Dynamic_Array* arr){
    // 6.1 判断数组是否有数据
    if(arr == NULL){
        return; 
    }
    // 6.1 先释放里面的那部分内存空间
    if(arr->pAddr != NULL){
        free(arr->pAddr);
    }

    // 6.2 释放 外层结构体的内存空间
    free(arr);
}

// 7. 打印
void Print_Dynamic_Array(Dynamic_Array* arr){
    // 7.1 判断数组是否有数据
    if(arr == NULL){
        return;
    }

    // 7.2 进行打印输出数据
    for(int i = 0; i < arr->size; i++){
        printf("%d ", arr->pAddr[i]);
    }
    printf("\n");
}

// 8. 清空数组
void Clear_Dynamic_Array(Dynamic_Array* arr){
    // 8.1 判断数组是否有数据
    if(arr == NULL){
        return;
    }

    // 8.2 清空数据 直接将数据中的 size = 0 即可，因为访问 pAddr 是根据size来的，不需要将pAddr所指向的内存空间设置为空，下次使用的时候会再次覆盖这次的数据
    arr->size = 0;
}

// 9. 获得动态数组的容量
int Capacity_Dynamic_Array(Dynamic_Array* arr){
    if (arr == NULL)
    {
        return -1;
    }
    
    return arr->capacity;
}

// 10. 获得动态数组当前元素个数
int Size_Dynamic_Array(Dynamic_Array* arr){
    if (arr == NULL)
    {
        return -1;
    }
    
    return arr->size;
}

// 11. 获得某个位置的元素
int At_Dynamic_Array(Dynamic_Array* arr, int pos  ){
    if(arr == NULL){
        return -1;
    }

    return arr->pAddr[pos];
}
