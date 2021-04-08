#include <iostream>

using namespace std;

namespace A{
    int value = 10;
}

namespace B{
    int value = 20;
}
int main(void){
    std::cout << "A::value = " << A::value << std::endl;
    std::cout << "B::value = " << B::value << std::endl;
	return 0;
}