#include <iostream>
#include <string>

/*
    string 容器：
        char* 是一个指针， string 是一个类 封装了 char*
        内部封装了很多的成员方法，包括查找、拷贝、删除、替换、修改、插入
        不需要考虑内存越界的和释放

        string 和 char* 之间相互转换， 使用 string 的 c_str 方法
*/
/*
    string 常用 API
        初始化： string s1()/s1; s1 = s2 + s3; assign()
        访问：逐个字符访问 s1[i], s1.at(i).
        查找： find、rfind
        拼接： append、+=

        替换： 
*/
using namespace std;

void test01();
void test02();
void test03();
void test04();
void test05();
void test06();
void test07();

int main(void){
    test07();
    return 0;
}

void test01(){
    // string的初始化
    string s1;
    string s2(10, 'a'); // 10个‘a’
    string s3("asbdsfs"); // 
    string s4(s3);      // 拷贝构造函数

    cout << s1 << endl;
    cout << s2 << endl;
    cout << s3 << endl;
    cout << s4 << endl;
}

void test02(){
    // 赋值操作
    string s1;
    string s2("asdasda");
    s1 = s2; // 重载了等号操作符号

    cout << s1 << endl;

    s1 = "helloworld";
    cout << s1 << endl;

    s1 = 'a';
    cout << s1 << endl;

    s1.assign("HelloKitty");   // 成员方法 
    cout << s1 << endl;
}

void test03(){
    string s1 = "abcdefg";

    // 逐个字符进行访问
    for(int i = 0; i < s1.size();i++){
        cout << s1[i] << " "; // 如果访问越界，直接挂掉
    }
    cout << endl;

    for(int i = 0; i < s1.size(); i++){
        cout << s1.at(i) << " ";    // 如果访问越界，at 函数抛出越界 out of range
    }
    cout << endl;

    try
    {
        s1.at(100);
    }
    catch(...) // 捕获所有异常
    {
        std::cout << "error" << '\n';
    }
}

void test04(){
    // 字符串拼接操作
    // 重载了 += 运算符
    string s = "abcd";
    s += "efg";
    s += 'a';

    cout << s << endl;

    string s2 = "hellow";
    s2.append(s, 5); // 跳过前五个字符，将剩下的字符放在尾部
    cout << s2 << endl;
}

void test05(){
    // 字符串 查找 find(), rfind()

    string s = "abcdefg";

    // 查找第一次出现的位置
    int pos = s.find("fg"); // 从0开始数

    cout << pos << endl;

    s += "fgdecba";

    pos = s.rfind("fg");
    cout << pos << endl;
}

void test06(){
    string s = "abcdefg";

    cout << s << endl;
    s.replace(0, 3, "111");
    cout << s << endl;
}

void test07(){
    // string 比较  大的时候返回1， 小的时候返回 -1， 等于 返回0
    string s1 = "abcd";
    string s2 = "abce";

    cout << s1.compare(s2) << endl;
}
