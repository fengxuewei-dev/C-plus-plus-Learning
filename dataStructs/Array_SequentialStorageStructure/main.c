#include "DynamicArray.h"

void test01(){
    // 1. 初始化一个动态数组
    Dynamic_Array* myArray = Init_Dynamic_Array();

    // 打印容量
    printf("打印容量: %d\n", Capacity_Dynamic_Array(myArray));
    printf("数组大小: %d\n", Size_Dynamic_Array(myArray));

    // 2. 插入元素
    for(int i = 0; i < 30; i++){
        PushBack_Dynamic_Array(myArray, i);
    }

    // 打印容量
    printf("打印容量: %d\n", Capacity_Dynamic_Array(myArray));
    printf("数组大小: %d\n", Size_Dynamic_Array(myArray));

    // 3. 打印
    Print_Dynamic_Array(myArray);


    // 删除数据
    RemoveByPos_Dynamic_Array(myArray, 0); 
    RemoveByVal_Dynamic_Array(myArray, 29); 

    Print_Dynamic_Array(myArray);


    // 查找元素
    int pos = Find_Dynamic_Array(myArray, 5); // 查找元素为5的位置
    printf("元素5位于数组第 %d 个元素， 该位置的元素为 %d \n", pos + 1,  At_Dynamic_Array(myArray, pos)); 

    // 4. 销毁
    FreeSpace_Dynamic_Array(myArray);
}

int main(int argc, char **argv)
{
    
    test01();

    return 0;
}