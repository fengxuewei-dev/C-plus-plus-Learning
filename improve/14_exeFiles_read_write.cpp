#include <iostream>
#include <fstream>

using namespace std;

// 文本文件 、二进制文件，在系统中存放的是都是二进制形式存放的额 
// 文本文件中，window 在每一行后面多两个字符，回车换行，将其作为行结束的标志 在linux下面就是将换行作为行结束的标志

// window
// 如果使用文本默认进行读取的时候，程序会将每一行后面的结束符号自动替换为 \n
// 如果使用文本模式进行写文件的时候，程序会将 \n 替换到 \r \n 写入到文本文件

// linux 下是以 \n 为文本文件结束符号 所以在 linux 下面使用二者模式没有什么区别

// 二进制文件读写 
/*
    对象序列化：
        比如：在程序中写了一个类 person，并且定义了一个类对象，将其写入到文件内部，避免将该对象从文件内部再次读取出来
*/ 

class Person{
    public:
        Person(){

        }
        Person(int age, int id){
            this->mAge = age;
            this->mId = id;
        }

        void show(){
            cout << "age = " << this->mAge << " id = " << this->mId << endl;
        }
    private:
        int mAge;
        int mId;
};

void test01(){
    Person p1(10, 20);
    Person p2(100, 200);

    // 将 p1 和 p2 写入到文件内
    // 这两个对象在内存中存放的是二进制  

    const char* TargetName = "./target.txt";

    // 1、将内存中数据原封不动的存放在文件中
    ofstream osm(TargetName, ios::out | ios::binary);  // 以二进制的方式进行读写 ios::binary

    osm.write((char *)&p1, sizeof(Person));    // 该函数专门针对 二进制方式的写 参数需要一个char* 类型

    osm.write((char *)&p2, sizeof(Person));


    osm.close();

}

void test02();

int main(void){
    test02();
    return 0;
}



void test02(){
   
    // 读写的时候有个指针
    cout << "test02" << endl;
    const char* TargetName = "./target.txt";

    // 2. 将内容从文件中读取出来
    ifstream ism(TargetName, ios::in | ios::binary);
    Person p;
    ism.read((char *)&p, sizeof(Person));


    Person pp;
    ism.read((char *)&pp, sizeof(Person));
    p.show();
    pp.show();

}