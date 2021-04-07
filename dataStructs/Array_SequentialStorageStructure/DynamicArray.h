/*  
    存放 API 的数据接口
*/

#ifndef DYNAMIC_ARRAY_H
#define DYNAMIC_ARRAY_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 动态数组的结构体定义
typedef struct MYDYNAMICARRAY{
    int* pAddr;     // 存放数据的地址
    int size;       // 当前有多少个元素
    int capacity;   // 容量，容器当前最大能容纳多少元素
}Dynamic_Array;


// 写一系列相关对 动态数组 操作的 API
// 对结构体 MYDYNAMICARRAY 结构体操作的函数
// 区分一个 api 是通过后缀来区分的

/**
 * @brief 线性表的顺序存储：用一块连续的内存空间来存放数据
 * 
 * 容量的引入可以提高效率，因为在每次的插入数据，不能都去申请空间，使效率降低
 * 使用容量的概念，可以降低申请拷贝内存的次数，提高效率
 * 
 * @return Dynamic_Array* 
 */
// 1. 初始化
Dynamic_Array* Init_Dynamic_Array();

// 2. 插入 默认的是在尾部插入，不需要指定插入位置；需要整个数组，需要插入的元素值
void PushBack_Dynamic_Array(Dynamic_Array* arr, int val);

// 3. 删除1: 根据位置删除 整个数组，需要删除的位置
void RemoveByPos_Dynamic_Array(Dynamic_Array* arr, int pos);

// 4  删除2：根据值删除 删除这个值第一次出现的位置
void RemoveByVal_Dynamic_Array(Dynamic_Array* arr, int val);

// 5. 查找
int Find_Dynamic_Array(Dynamic_Array* arr, int val);

// 6. 释放动态数组的内存
void FreeSpace_Dynamic_Array(Dynamic_Array* arr);

// 7. 打印
void Print_Dynamic_Array(Dynamic_Array* arr);

// 8. 清空数组
void Clear_Dynamic_Array(Dynamic_Array* arr);

// 9. 获得动态数组的容量
int Capacity_Dynamic_Array(Dynamic_Array* arr);

// 10. 获得动态数组当前元素个数
int Size_Dynamic_Array(Dynamic_Array* arr);

// 11. 获得某个位置的元素
int At_Dynamic_Array(Dynamic_Array* arr, int val);





#endif