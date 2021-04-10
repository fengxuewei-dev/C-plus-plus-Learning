#include "Point.hpp"
#include "Circles.hpp"



int main(void){
    Circles c1, c2;
    Point p1, p2;
    
    p1.setX(0);
    p1.setY(0);
    p2.setX(10);
    p2.setY(10);

    c1.setCo(p1);
    c2.setCo(p2);
    
    c1.setR(10);
    c2.setR(30);

    


    return 0;
}