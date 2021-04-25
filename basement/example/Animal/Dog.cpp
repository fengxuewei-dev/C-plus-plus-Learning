#include "Dog.hpp"

Dog::Dog(const char * const name) : Animal(){
            int len = strlen(name)+1;
            if(this->name == NULL){
                this->name = (char *)malloc(sizeof(char) * len);
                strcpy(this->name, name);
            }
        }

Dog::~Dog(){
            if(this->name != NULL){
                free(this->name);
                this->name = NULL;
            }
}


void Dog::voice(){ // 这里不需要再加 virtual 关键字了，它只是起到了一个声明的作用
    cout << this->name << " -- voice()" << endl;
}