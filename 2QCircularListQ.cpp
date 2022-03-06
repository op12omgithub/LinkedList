//#include "mainwindow.h"
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Queue
{
    struct Node *front, *rear;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertQ(Queue* q, int data)
{
    struct Node* tmp;
    tmp = createNode(data);
    if (q->front == NULL)
        q->front = tmp;
    else
        q->rear->next = tmp;

    q->rear = tmp;
    q->rear->next = q->front;
    printf("%d data is added in Q\n",data);
}

void deleteQ(Queue* q)
{
    int item;
    if (q->front == NULL) {
        printf("Queue has no data\n");
        return;
    }

    if (q->front == q->rear)
    {
        item = q->front->data;
        free(q->front);
        q->front = NULL;
        q->rear = NULL;
    }
    else
    {
        struct Node* tmp = q->front;
        item = tmp->data;
        q->front = q->front->next;
        q->rear->next = q->front;
        free(tmp);
    }
    printf(" %d data is deleted from Q\n",item);
}

void printQueue(struct Queue* q)
{
    struct Node* tmp = q->front;
    if(tmp !=NULL)
    {
        printf("Print the elements in circular Queue\n");

        while (tmp->next != q->front)
        {
            printf("%d \t", tmp->data);
            tmp = tmp->next;
        }

        printf("%d\n", tmp->data);
    }
    else
    printf("No elements in circular Queue\n");

}

int main(int argc, char *argv[])
{
    Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = q->rear = NULL;
    for(int i=1;i<4;i++)
    insertQ(q, i*10);

    printQueue(q);

    deleteQ(q);
    deleteQ(q);
    deleteQ(q);

    printQueue(q);

    insertQ(q, 100);
    insertQ(q, 200);
    insertQ(q, 300);

    printQueue(q);

    return 0;
}
