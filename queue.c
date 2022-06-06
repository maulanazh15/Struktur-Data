#include <stdio.h>
// #include <stdlib.h>
#define MAXQUEUE 5
typedef struct
{
    int count;
    int front;
    int rear;
    int item[MAXQUEUE];
} QUEUE;
QUEUE antrian;
void inisialisasi(QUEUE *Q)
{
    Q->count = 0;
    Q->front = 0;
    Q->rear = 0;
}
int isEmpty(QUEUE *Q)
{
    int hasil = 0;
    if (Q->count == 0)
    {
        hasil = 1;
    }
    return hasil;
}
int isFull(QUEUE *Q)
{
    int hasil = 0;
    if (Q->count == MAXQUEUE)
    {
        hasil = 1;
    }
    return hasil;
}
void insert(QUEUE *Q, int data)
{
    if (isFull(&antrian) == 1)
    {
        printf("maaf sudah full");
    }
    else
    {
        Q->item[Q->rear] = data; 
        Q->rear = (Q->rear + 1) % MAXQUEUE;
        ++(Q->count);
    }
}

void print(QUEUE *Q)
{
    int i;
    if (isEmpty(Q) == 1)
    {
        printf("maaf antrian kosong");
    }
    else
    {
        for (i = 0; i < Q->count; i++)
        {
            if (i == 0)
            {
                printf("%d", Q->item[Q->front]);
            }
            else
            {
                printf(" <- %d", Q->item[(Q->front + i) % MAXQUEUE]);
            }
        }
    }
}

int main()
{
    inisialisasi(&antrian);
    printf("masukan 3\n");
    insert(&antrian, 3);
    printf("masukan 6\n");
    insert(&antrian, 6);
    print(&antrian);
}
