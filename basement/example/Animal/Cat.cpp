#include "Cat.hpp"

Cat::Cat(const char *const name) : Animal(){
    if(this->name == NULL){
        int len = strlen(name) + 1;
        this->name = (char *)malloc(sizeof(char) * len);
        strcpy(this->name, name);
    }
}
Cat::~Cat(){
    if (this->name != NULL)
    {
        free(this->name);
        this->name = NULL;
    }
}
void Cat::voice(){
    cout << this->name << " --- voice" << endl;
}