#include "CircylarLinkedlists.h"

typedef struct PERSON
{
    CircylarLinkNode node;
    char name[64];
    int age;
    int score;
}Person;

void MyPrint(CircylarLinkNode*);
int MyCompare(CircylarLinkNode*, CircylarLinkNode*);

void test01();
void test02();
void test03();


int main(int argc, char **argv){
    
    test03();
    
    return 0;
}

void test01(){
    
    CircylarLinkList* clist = Init_CircylarLinkList();

    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");

    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;

    p1.score = 50;
    p2.score = 60;
    p3.score = 70;
    p4.score = 80;
    p5.score = 90;

    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p1);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p2);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p3);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p4);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p5);


    Print_CircylarLinkList(clist, MyPrint);

    FreeSpace_CircylarLinkList(clist);
}   



void test02(){
    
    CircylarLinkList* clist = Init_CircylarLinkList();

    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");

    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;

    p1.score = 50;
    p2.score = 60;
    p3.score = 70;
    p4.score = 80;
    p5.score = 90;

    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p1);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p2);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p3);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p4);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p5);


    Print_CircylarLinkList(clist, MyPrint);

    Person pDel;
    strcpy(pDel.name, "ccc");
    pDel.age = 30;
    pDel.score = 70;

    RemoveByVal_CircylarLinkList(clist, (CircylarLinkNode*)&pDel, MyCompare);


    Print_CircylarLinkList(clist, MyPrint);

    FreeSpace_CircylarLinkList(clist);
}   
void test03(){
    
    CircylarLinkList* clist = Init_CircylarLinkList();

    Person p1, p2, p3, p4, p5;
    strcpy(p1.name, "aaa");
    strcpy(p2.name, "bbb");
    strcpy(p3.name, "ccc");
    strcpy(p4.name, "ddd");
    strcpy(p5.name, "eee");

    p1.age = 10;
    p2.age = 20;
    p3.age = 30;
    p4.age = 40;
    p5.age = 50;

    p1.score = 50;
    p2.score = 60;
    p3.score = 70;
    p4.score = 80;
    p5.score = 90;

    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p1);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p2);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p3);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p4);
    Insert_CircylarLinkList(clist, 100, (CircylarLinkNode*)&p5);


    Print_CircylarLinkList(clist, MyPrint);

    RemoveByPos_CircylarLinkList(clist, 2);


    Print_CircylarLinkList(clist, MyPrint);

    FreeSpace_CircylarLinkList(clist);
}   


void MyPrint(CircylarLinkNode* data){
    Person* p = (Person*) data;

    printf("name: %s \t age: %d \t score: %d\n", p->name, p->age, p->score);
}
int MyCompare(CircylarLinkNode* node1, CircylarLinkNode* node2){

    Person* p1 = (Person*) node1;
    Person* p2 = (Person*) node2;

    if(strcmp(p1->name, p2->name) == 0 && p1->age == p2->age && p1->score == p2->score){
        return CIRCYLARTLINKLIST_TRUE;
    }

    return CIRCYLARTLINKLIST_FALSE;
}