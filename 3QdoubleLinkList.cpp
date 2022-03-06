//#include "mainwindow.h"
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* prev,*next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void addToHead(struct Node*&head,int value)
{
    struct Node *newNode;
    newNode = createNode(value);
    if(head==NULL)
    {
        head = newNode;
        printf("%d value added to head\n",value);
    }
    else
    {
        newNode->next=head;
        head->prev = newNode;
        head = newNode;
        printf("%d value added to head\n",value);

    }
}
void adddToTail(struct Node* head,int value)
{
    struct Node* tmp = createNode(value);
    if(head==NULL)
    {
        head=tmp;
        printf("%d value added to tail\n",value);
     }
    else
    {
        while(head->next!=NULL)
            head=head->next;
        head->next = tmp;
        tmp->prev = head;
        printf("%d value added to tail\n",value);
    }

}
void deleteFromHead(struct Node* &head)
{
    struct Node *tmp,*tmp2;
    if(head==NULL)
        return;
    tmp = head;
    head =head->next;
    if(head!=NULL)
    {
    	 printf("%d value deleted from head\n",tmp->data);
        tmp2 = head->prev->prev;
        free(tmp);
        tmp=NULL;
        head->prev = tmp2;

    }

}
void deleteFromTail(struct Node* &head)
{
    struct Node *tmp,*tmp2;
    if(head==NULL)
        return;
    tmp  = head;
    while(tmp->next !=NULL)
    {
        tmp = tmp->next;
    }
    if(tmp!=NULL)   //in case of single node exist
    {
    	printf("%d value deleted from tail\n",tmp->data);
        tmp2 = tmp->prev;
        free(tmp);
        if(tmp2!=NULL)
            tmp2->next = head->prev;
        else
            head=NULL;         //setting in case of no node exist
    }

}

void printForward(struct Node *head)
{
    printf("Printing forward\n");
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head = head->next;
    }
    printf("\n");

}
void printBackward(struct Node *head)
{
    printf("Printing backword\n");
    if(head==NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(head->next!=NULL)
    {
        head = head->next;
    }

    while(head!=NULL)
    {
        printf("%d\t",head->data);
        head = head->prev;
    }
    printf("\n");
}
void deleteNode(struct Node* &head,int position)
{
    struct Node *tmp,*tmp2;
    if(head==NULL)
        return;

    if(position==1)
    {
    tmp = head;
    head =head->next;
    if(head!=NULL)
    	{
    	 printf("%d value deleted from %dth position\n",tmp->data,position);
        tmp2 = head->prev->prev;
        free(tmp);
        tmp=NULL;
        head->prev = tmp2;
	return;
    	}
    }

    struct Node *temp = (struct Node*) malloc(sizeof(struct Node));
    struct Node *temp1 = (struct Node*) malloc(sizeof(struct Node));
    int i = 1;

    temp = head;

    while((i < position) && temp->next!=NULL)
    {
        temp = temp->next;
        i++;
    }

    if(i == position)
    {

        temp1 = temp->prev;
        temp1->next = temp->next;

        if(temp->next==NULL)
            head->prev =NULL;
        else
            temp->next->prev = temp1;

	printf("%d value deleted from %dth position\n",temp->data,position);
        free(temp);
    }
    else
        printf("position is out of range: %d\n", i);

}


void addNode(struct Node* &head,int value, int position)
{
    struct Node *newNode = createNode(value);

    if(head==NULL)
    {
        head=newNode;
        head->prev=newNode;
        printf("%d value added to %dth position\n",value,position);
        return;
    }

    struct Node *temp = (struct Node *) malloc(sizeof(struct Node));
    temp = head;
    int i = 1;
    while((i < position-1) && temp->next!=NULL){
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if(temp->next)
        temp->next->prev = newNode;

    temp->next = newNode;
            printf("%d value added to %dth position\n",value,position);
}


void isInList(struct Node *head,int value)
{
    int flag=0;

    while(head!=NULL)
    {
        if(head->data==value)
        {
            printf(" %d value exist in the list\n",value);
            flag=1;
            break;
        }
        head = head->next;
    }
    if(flag==0)
        printf(" %d value does not exist in the list\n",value);
}

int main(int argc, char *argv[])
{
    struct Node *head=NULL;
    for(int i=1;i<5;i++)
        addToHead(head,i*10);


    printForward(head);
    for(int j=1;j<5;j++)
        adddToTail(head,j*3);
    printBackward(head);
    printForward(head);
    isInList(head,10); // 7 denote value, is exist in the list?
    isInList(head,7);

    deleteFromHead(head);
    deleteFromTail(head);
    addNode(head,100,2);//here 100 is value and 2 is position
    addNode(head,200,2);
    addNode(head,300,3);
    deleteNode(head,2);//here 2 denote position in the list.
    deleteNode(head,2);
    addNode(head,400,3);
    printForward(head);
    deleteNode(head,2);
    deleteNode(head,7);
    deleteNode(head,1);
    deleteNode(head,3);

    printForward(head);
    printBackward(head);

    return 0;
}
