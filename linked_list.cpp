#include <iostream>

using namespace std;

typedef struct node *address;

struct node {
    address prev;
    int data;
    address next;
};

address first, last, temp;

address alokasi(int data) {
    address temp = new node;
    temp->data = data;
    temp->prev = NULL;
    temp->next = NULL;
    return temp;
}

void insertfirst(address baru){
    if(first == NULL){
        first = last = baru;
    } else {
        baru->next = first;
        first->prev = baru;
        first = baru;
    }
}

void insertlast(address baru){
    if(first == NULL){
        first = last = baru;
    } else {
        baru->prev = last;
        last->next = baru;
        last = baru;
    }
}

void insertafter(address prec, address baru){
    baru->next = prec->next;
    baru->prev = prec;
    prec->next->prev = baru;
    prec->next = baru;
}

void deletefirst(){
    if(first == NULL){
        cout << "List kosong" << endl;
    } else if(first == last){
        delete first;
        first = last = NULL;
    } else {
        temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
    }
}
void deletelast(){
    if(first == NULL){
        cout << "List kosong" << endl;
    } else if(first == last){
        delete first;
        first = last = NULL;
    } else {
        temp = last;
        last = last->prev;
        last->next = NULL;
        delete temp;
    }
}

void deleteafter(address prec){
    if(first == NULL){
        cout << "List kosong" << endl;
    } else if(first == last){
        delete first;
        first = last = NULL;
    } else {
        temp = prec->next;
        prec->next = temp->next;
        prec->next->prev = prec;
        delete temp;
    }
} 

void cetak(){
    address temp = first;
    while(temp != NULL){
        if (temp->next == NULL){
            cout << temp->data;
        } else {
            cout << temp->data << " <-> ";
        }
        temp = temp->next;
    }
    cout << endl;
}


int main(){
    insertfirst(alokasi(1));
    insertfirst(alokasi(2));
    insertfirst(alokasi(3));
    cetak();
    insertlast(alokasi(4));
    insertlast(alokasi(5));
    insertlast(alokasi(6));
    cetak();
    insertafter(first, alokasi(7));
    insertafter(first -> next, alokasi(8));
    insertafter(first->next->next->next, alokasi(9));
    cetak();
    deletefirst();
    cetak();
    deletelast();
    cetak();
    deleteafter(first);
    cetak();
    return 0;
}
