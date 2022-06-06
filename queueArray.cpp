#include <iostream>
#define MAXQUEUE 5
using namespace std;

typedef struct {
    int count;
    int front;
    int rear;
    int kamar[MAXQUEUE];
} Queue;

void initQueue(Queue *q) {
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}


void enqueue(int identitas, Queue *q) {
    if (q->count == MAXQUEUE) {
        cout << "Kamar penuh" << endl;
    } else {
        q->kamar[q->rear] = identitas;
        q->rear = (q->rear + 1) % MAXQUEUE;
        (q->count)++;
    }
}

void dequeue(Queue *q) {
    if (q->count == 0) {
        cout << "Mohon maaf Kamar kosong" << endl;
    } else {
        int datanya; 
        datanya = q->kamar[q->front];
        q->front = (q->front + 1) % MAXQUEUE;
        (q->count)--;
        cout << "Orang dengan nomor identitas : " << datanya << " telah keluar dari kamar." << endl;
    }
}



int main() {
    Queue antrian;
    initQueue(&antrian);
    int pilihan;
    while (pilihan != 4) {
        cout << "1. Masukkan antrian" << endl;
        cout << "2. Keluar antrian" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        switch (pilihan) {
            case 1:
                int identitas;
                cout << "Masukkan nomor identitas : ";
                cin >> identitas;
                enqueue(identitas, &antrian);
                break;
            case 2:
                dequeue(&antrian);
                break;
            case 3:
                cout<<"Terima kasih telah menggunakan antrian kami"<<endl;
                break;
            default:
                cout << "Pilihan tidak ada" << endl;
                break;
        }
    }
    return 0;
    
    
    
}




