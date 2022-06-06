#include <stdio.h>
#include <stdlib.h>
#define MAXSTACK 2
typedef struct
{
    int item[MAXSTACK];
    int count;
} Stack;
Stack tumpukan;
int isFull(Stack *x)
{
    int hasil = 0;
    if ((x->count) >= MAXSTACK)
        hasil = 1;
    return hasil;
}
int isEmpty(Stack *x)
{
    int hasil = 0; // mengecek apakah stack kosong jika kosong maka hasil = 0;
    if ((x->count) == 0)
    {
        hasil = 1;
    }
    return hasil;
}
void membuatStack(Stack *x)
{
    x->count = 0;
}
void push(int data, Stack *x)
{
    if (isFull(x) == 1)
    {
        printf("Stack Penuh\n");
    }
    else
    {
        x->item[x->count] = data;
        ++(x->count);
        printf("berhasil memasukan\n");
    }
}

void pop(Stack *x)
{
    if (isEmpty(x) == 1)
    {
        printf("Stack Kosong\n");
    }
    else
    {
        x->item[x->count - 1] = 0;
        --(x->count);
        printf("berhasil menghapus\n");
    }
}

void cetak()
{
    for (int i = 0; i < MAXSTACK; i++)
    {
        printf("isi index %d %d \n", i, tumpukan.item[i]);
    }
}


int main()
{
    int i;
    membuatStack(&tumpukan);
    printf("masukan 3\n");
    push(3, &tumpukan);
    printf("masukan 5\n");
    push(5, &tumpukan);
    printf("masukan 6\n");
    push(6, &tumpukan);
    printf("masukan 7\n");
    push(7, &tumpukan);
    cetak();
    pop(&tumpukan);
    pop(&tumpukan);
    pop(&tumpukan);
    pop(&tumpukan);
    cetak();
}