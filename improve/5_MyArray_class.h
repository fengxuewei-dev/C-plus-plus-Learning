#pragma once

// 容量的概念
// 当前内部存放多少元素
// 数组保存数据的首地址
#define SIZE_MAX 100

template<class T>
class MyArray{
    public:
        MyArray(int capacity);

        ~MyArray();
        MyArray(const MyArray<T>& another); 

        T& operator[](T& value);

        MyArray operator=(const MyArray<T>& arr); 

        void PushBack(T& value); // 在最后追加元素，当内存空间不足的时候，会失败，返回0

        

    private:
        int mCapacity;  // 容量
        int mSize;      // 存放多少元素
        T* pAddr;       // 数据元素的首地址

};
