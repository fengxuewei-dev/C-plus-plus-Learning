#include <iostream>
#include <cstring>

// #include <iomapip> // setiosflags
#include <iomanip> // setiosflags
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
    标准输出流
    cout.flush()    刷新缓冲区
    cout.put()      将字符写入到 输出缓冲区，支持链式编程 cout.put('a').put('b');
    cout.write(str, len)    写一个字符串

    格式化输出
    cout.unsetf(ios::hex / ios::dec / ios::oct)
    cout.setf(ios::hex / ios::dec / ios::oct / ios::showbase / ios::left)

    cout.width(10)
    cout.fill('*')

    控制符控制
    cout << hex // oct; dec
         << setiosflags(ios::showbase) // 显示方法
         << setw(10)    // 宽度
         << setfill('~')    // 填充
         << setiosflags(ios::left)  // 对齐方式
         << number << endl;
    
*/



using namespace std;

// 通过成员方法来进行调用
void test01(){
    cout.put('h').put('e').put('l');
    cout << endl;
    char const* str = "helloword";
    cout.write(str, strlen(str));
    cout << endl;
}
void test02(){
    // 格式化输出
    int number = 10;
    // 将上面的数字使用八进制进行输出
    // 1、将当前 cout 默认的输出方式卸载掉
    cout.unsetf(ios::dec); // ios::dec 十进制的输出方式

    // 2、重新设置 输出方式
    cout.setf(ios::oct); // 八进制输出方法
    // cout.setf(ios::hex); // 16进制输出方法
    // cout << number << endl; // 此时直接输出 12, 并没有显示前面的特定标志 0

    // 3、设置特定的标志显示
    cout.setf(ios::showbase);
    cout << number << endl; // 012

    cout.unsetf(ios::oct);
    cout.setf(ios::hex);
    // cout.setf(ios::showbase);
    cout << number << endl;
}
void test03(){
    // 输出显示的时候，设置宽度
    // cout.width();
    cout.width(10); // 设置宽度为10
    cout.fill('*'); // 其他的位置使用什么字符来填充呢？ 位宽的其他空位使用字符替换 默认的是 右对齐的
    cout.setf(ios::left);   // 设置左对齐
    int number = 20;

    cout << number << endl;
}

// 通过控制符
void test04(){
    int number = 10;
    cout << hex 
         << setiosflags(ios::showbase) // 显示方法
         << setw(10) 
         << setfill('~')
         << setiosflags(ios::left)
         << number << endl;
}

int main(void){
    test04();
    return 0;
}