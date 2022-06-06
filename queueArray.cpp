#include <iostream>
#define MAXQUEUE 5
using namespace std;

typedef struct
{
    int count;
    int front;
    int rear;
    int kamar[MAXQUEUE];
} Queue;

void initQueue(Queue *q)
{
    q->count = 0;
    q->front = 0;
    q->rear = 0;
}

void enqueue(int identitas, Queue *q)
{
    if (q->count == MAXQUEUE)
    {
        cout << "Kamar penuh" << endl;
    }
    else
    {
        q->kamar[q->rear] = identitas;
        q->rear = (q->rear + 1) % MAXQUEUE;
        (q->count)++;
    }
}

void dequeue(Queue *q)
{
    if (q->count == 0)
    {
        cout << "Mohon maaf kamar telah dikosongkan." << endl;
    }
    else
    {
        int datanya;
        datanya = q->kamar[q->front];
        q->front = (q->front + 1) % MAXQUEUE;
        (q->count)--;
        cout << "Orang dengan nomor identitas : " << datanya << " telah keluar dari kamar." << endl;
    }
}

int main()
{
    Queue antrian;
    initQueue(&antrian);
    int pilihan;
    int identitas = 1;

    while (pilihan != 3)
    {
        cout << "Selamat Datang di Wahana Wisata Dasar Laut Plankton Inc" << endl;
        cout << "Pilih menu yang ingin anda lakukan : " << endl;
        cout << "1. Masuk ke kamar pandang." << endl;
        cout << "2. Keluar dari kamar pandang." << endl;
        cout << "3. Keluar dari wahana." << endl;
        cout << "Pilihan : ";
        cin >> pilihan;
        switch (pilihan)
        {
        case 1:
            cout << "Nomor identitas anda : " << identitas << endl;
            enqueue(identitas, &antrian);
            if (antrian.count != 5)
            {
                identitas++;
            }
            system("pause");
            break;
        case 2:
            dequeue(&antrian);
            system("pause");
            break;
        case 3:
            cout << "Terima kasih telah berkunjung ke wahana kami." << endl;
            system("pause");
            break;
        default:
            cout << "Pilihan tidak ada" << endl;
            break;
        }
        system("cls");
    }
    return 0;
}
