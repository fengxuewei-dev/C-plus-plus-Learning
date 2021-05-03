#include <iostream>

/*
    键盘/文件输入 ----> 缓冲区 ---> 程序 ---> 输出缓冲区 ---> 显示器 或者 文件

    文件的输入和输出是 文件I/O
    输入和输出是相对于程序来说的

    cin     输入缓冲区
    cout    存在缓冲区          默认和显示器进行关联
    cerr    不存在缓冲区        输出数据到显示器
    clog    存在缓冲区          输出数据到显示器

    缓冲区： 比如下面代码：
        int a;
        cin >> a; // 此时 cin 开始读取数据，等待输入缓冲区内部存在数据（就是一块内存，比如：char buf[256]）；当缓冲区没有数据的时候，开始阻塞，等待键盘输入，这个时候当键盘输入 abc，点击回车，将字符发送到输入缓冲区中，此时 cin 可以按照特定的方式从缓存区进行读取数据


        cout << "hello world" // 这个时候将字符串发送到缓冲区，但是不会进行输出； 当在后面加上一个 << endl，才会进行输出，endl 产生了 刷新 输出缓冲区的作用同时输出一个换行，刷新之后输出缓冲区的 hello world 字符 ，输出到 显示器，此时内部缓冲区就没有 hello world 的字符串字样
*/

/*
    标准输入流
    cin.get()
    cin.getline()
    cin.ignore()
    cin.peek()
    cin.putback()
*/



using namespace std;

void test01();
void test02();
void test03();
void test04();

int main(void){
    test04();
    return 0;
}

void test04(){
    // cin.putback(); // 和 cin.get() 一起使用，cin.get 是从缓冲区将数据拿出来，而 cin.putback() 是将刚拿出去的数据再存放到 它的位置， 二者的结合 相当于  cin.peek 的功能

    char ch;
    cout << "Please input the character or number: ";
    ch = cin.get();

    if(ch >= '0' && ch <= '9'){
        cin.putback(ch);
        int number;
        cin >> number;
        cout  << "the number is "<< number << endl;
    }else{
        cin.putback(ch);
        char buf[256] = {0};
        cin >> buf;
        cout << "the string is " << buf<< endl;
    }
}

void test03(){
    // cin.peek(); // 查看输入缓存区的第一个数据是什么，但是不取出来，cin.get()会将数据拿出来
    cout << "Please input the character or number: ";
    char ch;
    ch = cin.peek();     // 窥探输入缓冲区第一个字符是什么，返回的是第一个字符
    if(ch >= '0' && ch <= '9'){
        int number;
        // number = atoi(cin.getline());
        cin >> number;
        cout  << "the number is "<< number << endl;
    }else{
        char buf[256] = {0};
        cin >> buf;
        cout << "the string is " << buf<< endl;
    }
}

void test02(){
    // cin.ignore() 忽略当前字符
    char ch, ch1;
    cin.get(ch);

    // cin.ignore(10, '\n'); // 忽略10个字符，该语句表示，如果在忽略10个字符内部，出现了 \n， 那么就将 \n 之前的额数据忽略掉 === 优先进行寻找 \n， 当找到 \n 的时候，后面剩余 忽略的字符个数就不进行忽略了
    // 忽略的数据 也不再存在域缓冲区
    cin.ignore(2);    // 将输入缓冲区的第二个字符进行跳过，忽略  cin.ignor(2) 忽略两个字符
    cin.get(ch1);

    cout << ch << ch1 << endl;


}
void test01(){
    // std::cout << "hello world"; // 是一个 ostream 对象 将头文件包含进行之后，只是一个全局流对象
    // int a;
    // cin >> a;

    // 标准输入流 ch = cin.get(); cin.get(ch); cin.get(ch, size)可以读取字符串; cin.getline(buf, size);
    char ch;
    // while((ch = cin.get()) != EOF){ // EOF 是一个结束符 对应键盘上面就是一个 ctrl+z
    //     // cin.get() 读取一个输出一个 
    //     cout << ch << endl; 
    // }

    char ch2;
    cin.get(ch2);   // 读取一个字符

    char buf[256] = {0};
    // cin.get(buf, 256); // 从缓冲区读取一个字符串，长度为 256


    // 256 Maximum number of characters to extract.
    cin.getline(buf, 256); // 读取一行数据，直到遇到 \n 为止，不会将 \n 读取出来的
    cout << buf << endl;
}