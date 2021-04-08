#include <iostream>
#include <cstring>

using namespace std;

struct teacher{
    int id;
    char name[64];
};

// 使用常规的方法来申请内存空间
int get_mem(struct teacher **tp);
void free_teacher(struct teacher **tpp);
void test01();


// 使用引用的方法来申请内存空间
int get_mem2(struct teacher * &tp);
void free_teacher2(struct teacher * &tpp);
void test02();

int main(void){
    test02();
    return 0;
}

int get_mem(struct teacher **tp){
    struct teacher *t1 = NULL;
    t1 = (struct teacher*)malloc(sizeof(struct teacher));
    t1->id = 20;
    strcpy(t1->name, "li4");
    
    *tp = t1;

    return 0; // 0: success -1：failed; other:others status
}

void free_teacher(struct teacher **tpp){
    if(tpp == NULL){
        return;
    }
    struct teacher *tp = *tpp;
    if(tp != NULL){
        free(tp);
        *tpp = NULL;
    }
} // 这个函数若有一个没有搞清楚，就会出现内存释放不成功

void test01(){
    struct teacher *tpp = NULL;
    
    get_mem(&tpp);

    cout << "id = " << tpp->id << "\t" << "name = " << tpp->name << endl;
    
    free_teacher(&tpp);
}


// 指针引用
int get_mem2(struct teacher * &tp){
    
    tp = (struct teacher*)malloc(sizeof(struct teacher));
    
    if(tp == NULL){
        return -1;
    }
    
    tp->id = 30;
    
    strcpy(tp->name, "wang5");

    return 0;
}

void free_teacher2(struct teacher * &tpp){
    if(tpp == NULL){
        return;
    }

    free(tpp);
}
void test02(){
    struct teacher *tpp = NULL;
    
    get_mem2(tpp);

    cout << "id = " << tpp->id << "\t" << "name = " << tpp->name << endl;
    
    free_teacher2(tpp);
}