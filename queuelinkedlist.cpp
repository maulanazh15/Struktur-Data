#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

typedef struct node* address;
struct queuelinkedlist {
    address front;
    address rear;
};
struct node
{
    int data;
    address link;
};



