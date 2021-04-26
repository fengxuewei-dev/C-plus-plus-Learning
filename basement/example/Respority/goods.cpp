#include <iostream>

using namespace std;

class Goods{
    public:
        Goods(){

        }
        Goods(double weight){
            this->weight = weight;
            this->allWeigh += weight;
            next = NULL;
        }
        ~Goods(){
            this->allWeigh -= this->weight;
        }
        static double getAllWeight(){
            return allWeigh;
        }
        Goods *next;
    private:
        double weight;
        static double allWeigh;
};

double Goods::allWeigh = 0;

typedef struct GoodsManager{
    Goods *gp;
    int size;    
}gm;

void init(gm *g){
    g->gp = new Goods;
    g->gp = NULL;
    g->size = 0;
}

void buy(Goods * &head, double& w){
    Goods* gs = new Goods(w);

    if(head == NULL){
        head = gs;
    }else{
        gs->next = head;
        head = gs;
    }
}

void sale(Goods *&head){
    if (head == NULL)
    {
        cout << "仓库没有货物。。。" << endl;
        return; 
    }
    // Goods *temp = head->next;
    // delete head->next;
    // head = temp;
    Goods *temp = head;
    head = head->next;

    delete temp;
}

int main(void){
    int choice;
    double weight;

    Goods *head = NULL;
    do{
        cout << "1 进货" << endl;
        cout << "2 出货" << endl;
        cout << "0 退出" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "请输入要进的货物重量！" << endl;
            cin >> weight;
            buy(head, weight);
            break;
        
        case 2:
            cout << "出货。。。" << endl;
            sale(head);
            break;
        
        case 0:
            return 0;
            break;
        
        default:
            break;
        }

        cout << "仓库总重量 = " <<Goods::getAllWeight()<<endl;
    }while(1);


    return 0;
}

