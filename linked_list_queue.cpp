#include <iostream>
using namespace std;
typedef struct node* address;

struct node{
 int data;
 address link;
};

struct queue{
  address front;
  address rear;
};
queue Q1, Q2;
address alokasi(int x){
    address temp=(address)malloc(sizeof(node));
    temp->data=x;
    temp->link=NULL;
    return temp;
}

void enqueue(queue *q, address baru){
    if(q->rear!=NULL){ //kalo ada
        q->rear->link=baru;
        q->rear=baru;
    }else{ //kalo ga ada
        q->front=baru;
        q->rear=baru;
    }
}
void dequeue(queue *q){
    int isidata;
    address temp;
    if(q->front !=NULL){
        isidata=q->front->data;
        temp=q->front;
        q->front=q->front->link;
        free(temp);
        cout<<"data yang diambil adalah "<<temp->data<<endl;
    while (temp!=NULL){
        cout<<temp->data<<"\n";
       temp=temp->link;
    }
}else{
    cout<<"queue kosong"<<endl;
}
}
void cetak(queue *q){
    address temp;
    temp=q->front;
    while(temp!=NULL){
        cout<<temp->data<<"\n";
        temp=temp->link;
    }
}

int main()
{
    enqueue(&Q1, alokasi(10));
    enqueue(&Q1, alokasi(20));
    enqueue(&Q1, alokasi(30));
    dequeue(&Q1);
    cetak(&Q1);
   

    return 0;
}