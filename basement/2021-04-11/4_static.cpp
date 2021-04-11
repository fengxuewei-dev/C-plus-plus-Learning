#include <iostream>
#include <cstring>
/*
类的声明，和类的实例化
    静态成员变量和静态成员函数 static
        类中的静态成员变量，一定要在类外进行初始化，在静态区，定义必须在类外进行赋值，因为并属于某个对象，是属于整个静态，应该在这个类定义好了之后，就告诉编译器该值是多少
        当编译器编译的时候，就会先扫描一遍代码，将static 成员变量分配好了内存，那么之后不管你创建多少个该类型的对象，都和该成员变量无关（在定义类对象之前，就已经为其分配好了内存空间）
            类内(不管public 还是 private)： static int mm; 类外： int AA::mm = 0;
            它是属于整个类的，所以成员函数是可以访问的
            在类外函数中也可以使用 AA::mm = 20; 来进行访问，但是仅限于该成员变量是 public 

            若一个静态成员变量是私有的话，要返回该变量，需要提供静态方法 也是属于类的，可以独立于对象 来存在
            static int getMm(){
                return mm;
            }



    在c语言中，
    static int n = 1;   在静态区进行初始化和定义，且只被初始化定义一次
    static void func(){

    } // 代表了该函数只能在该文件中可见，使用域为当前文件内部

    求类对象的大小，是不包含 static 的变量的，因为存放的位置是不一样的
    同时一个类对象中的成员函数是不在对象中的，在计算类所占字节数的时候，没有类的成员函数以及类的静态成员变量。那么为什么会通过对象名字来调用函数，该函数可以准确的调用属于该对象的数据 ==>> this 指针来获得.
*/

using namespace std;

// 定义一个盒子 box，所有的对象都拥有一个相同的高度
class Box{
    public:
        Box(double l, double w){
            m_len = l;
            m_wid = w;
        }
        ~Box(){

        }
        void print(){
            cout << "len： " << m_len << " wid: "  << m_wid << " high: " << m_hig << endl;
        }
        static double& getHig(){
            return m_hig;
        }
        void getVolumn(){
            cout << "high = " << m_hig << endl;
            cout << "V = " << m_len * m_wid *m_hig << endl;
        }
    private:
        double m_len;
        double m_wid;
        static double m_hig;
};

double Box::m_hig = 20;

// 定义一个学生类，来求出所有学生的平均分数和总分数
class Students{
    public:
        Students(int id, const char* name, const double score){
            m_id = id;
            m_score = score;

            // m_name = (char*)malloc(sizeof(char)*(strlen(name)+1))w ;
            m_name = new char(strlen(name)+1);
            if (m_name != NULL)
            {
                strcpy(m_name, name);
            }
            n++;
            sum+=score;
            average = sum / n;
        }
        ~Students(){
            if(m_name != NULL){
                delete m_name;
                m_name = NULL;
            }
            n--;
            sum = sum - m_score;
            average = sum / n;
        }
        static double getSum(){
            return sum;
        }
        static double getAverage(){
            return average;
        }
        void printStu(){
            cout << "id:" <<m_id << "\t name = " << m_name << "\t score = " << m_score << "\t studs num: " << n << ", sum: " << sum << ", average: " << average << endl;
        }
    private:
        double m_id;
        char *m_name;
        double m_score;
        static int n;           //学生个数
        static double sum;      //总成绩
        static double average;  //平均成绩
};
int Students::n = 0;
double Students::sum = 0;
double Students::average = 0;

void test01();
void test02();

int main(void){
    test02();
    return 0;
}

void test01(){
    Box b1(10, 20);
    Box b2(100,200);

    b1.getVolumn();
    b2.getVolumn();

    Box::getHig() = 30;

    b1.getVolumn();
    b2.getVolumn();
}

void test02(){
    Students st1(2019520901, (char*)"zhangsan", 67);
    Students st2(2019520902, (char*)"lisi", 70);
    Students st3(2019520903, (char*)"wangwu", 80);
    st1.printStu();
    st2.printStu();
    st3.printStu();
    cout << "---------------------" << endl;
    st3.~Students();
    st1.printStu();
    st2.printStu();

    cout << "总分为： " << Students::getSum() << endl;
    cout << "平均分为: " << Students::getAverage() << endl;
    cout << "---------------------" << endl;
    st2.~Students();
    st1.printStu();

    cout << "总分为： " << Students::getSum() << endl;
    cout << "平均分为: " << Students::getAverage() << endl;
    
    cout << "---------------------" << endl;
    cout<<"点击任意键退出："; getchar();
}