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
        q->count++;
    }
}

void dequeue(Queue *q) {
    if (q->count == 0) {
        cout << "Kamar kosong" << endl;
    } else {
        q->front = (q->front + 1) % MAXQUEUE;
        q->count--;
    }
}

void cetak(Queue *q) {
    int i;
    if (q->count == 0) {
        cout << "Kamar kosong" << endl;
    } else {
        for (i = 0; i < q->count; i++) {
            cout << q->kamar[(q->front + i) % MAXQUEUE] << endl;
        }
    }
}

int main() {
    Queue antrian;
    initQueue(&antrian);
    int identitas = 1;
    for (int i = 0; i < 6; i++)
    {
        enqueue(identitas, &antrian);
        // if (identitas%5==0)
        // {
        //     dequeue(&antrian);
        //     enqueue(identitas, &antrian);
        // }
        identitas++;
    }
    cetak(&antrian);
    
}




