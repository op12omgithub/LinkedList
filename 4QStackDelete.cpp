//#include "mainwindow.h"
#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void push(struct Node* &stack,int value)
{
    struct Node* newData = createNode(value);
  if(stack==NULL)
  {
    stack = newData;
    printf("%d is added\n",stack->data);

    return;
  }
  newData->next=stack;
  stack=newData;
  printf("%d is added\n",stack->data);

}
void pop(struct Node* &stack)
{
  struct Node *tmp;
  if(stack!=NULL)
  {
      printf("%d is deleted from top\n",stack->data);

      tmp = stack;
      stack=stack->next;
      free(tmp);
      tmp=NULL;
  }
}
void pop_bottom(struct Node* &stack)
{
   struct Node* tmp;
   if(stack==NULL)
       return;
   if(stack->next==NULL)
   {
       printf("%d is deleted from bottom\n",stack->data);
       tmp=stack;
       free(tmp);
       tmp=NULL;
       return;
   }
   tmp=stack;
   while(tmp->next->next!=NULL)
   {
       tmp=tmp->next;
   }
   printf("%d is deleted from bottom\n",tmp->next->data);

   free(tmp->next);
   tmp->next=NULL;
}
void display(struct Node* stack)
{
    if(stack==NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("Print the stack\n");
    while(stack!=NULL)
    {
        printf("%d\t",stack->data);
         stack=stack->next;
    }
    printf("\n");

}
int main(int argc, char *argv[])
{
struct Node *stack=NULL;
for(int i=1;i<6;i++)
    push(stack,i*10);

display(stack);
pop_bottom(stack);
pop(stack);
display(stack);

push(stack,100);
pop_bottom(stack);
display(stack);

    return 0;
}
