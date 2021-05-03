#include <iostream>
#include <fstream> // 文件读写
/*
    文件的读写
     istream ostream --- ifstream ofstream

     iostream -- fstream
*/

/*
    文本文件读写
*/

using namespace std;

void test01();

int main(void){
    test01();
    return 0;
}

void test01(){
    // 1、打开文件，且将文件内容放在缓存区中
    const char* filename = "./source.txt"; // 这个是正斜杠， 反斜杠（window）需要写两个 
    const char* targetName = "./target.txt"; // 这个是正斜杠， 反斜杠（window）需要写两个 
    ifstream ism(filename, ios::in);        // 只读方式打开文件（默认文本文件） 文件和输入缓冲区的管道
    // ofstream osm(targetName, ios::out);     // 不进行追加
    ofstream osm(targetName, ios::out | ios::app); // 追加的方式进行写入
    /*
        // 这种方法也是可以打开文件
        ifstream ism;
        ism.open(filename, ios::in);
    */
    if(!ism){ // 对对象进行取反，说明该类将该 符号 ！ 进行重载了
        cout << "打开文件失败" << endl;
        return;
    }

    // 文件 ==“管道”==> 程序

    // 2、读文件
    char ch;
    while(ism.get(ch)){ // 逐个字符进行读取
        // cout << ch;

        // 写到文件中

        osm.put(ch); // put一个字符到 输出流中 流到文件中
    }
    cout << endl;

    // 3、关闭文件
    ism.close();
    osm.close();


}