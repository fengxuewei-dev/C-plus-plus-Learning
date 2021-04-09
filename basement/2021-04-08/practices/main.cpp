#include "Circles.h"

void test01();

int main(void){
    test01();
    return 0;
}
void test01(){
    Circles c1;
    c1.setR(10);
    cout << "r = " << c1.getR() << endl;
    cout << "girth = " << c1.getGirth() << endl;
    cout << "area = " << c1.getArea() << endl;
}