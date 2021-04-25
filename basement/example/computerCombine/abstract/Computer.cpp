#include "Computer.hpp"

Computer::Computer(CPU *cpu, Memory* stro, Card* card){
    this->cpu = cpu;
    this->card = card;
    this->memory = stro;
}
Computer::~Computer(){

}

// 工作
void Computer::work(){
    this->cpu->calculate();
    this->card->display();
    this->memory->stroage();
}

// void Computer::calculate(){
//     std::cout << "Inter Calculate..." << std::endl;
// }

// void Computer::display(){
//     std::cout << "Inter display..." << std::endl;
// }

// void Computer::stroage(){
//     std::cout << "Inter stroage..." << std::endl;
// }