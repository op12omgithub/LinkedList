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

struct Node *radix[10];

void  initializeList()
{
    int i;
    for(i = 0; i < 10; i++)
    {
        radix[i] = NULL;
    }
}


int get_max_sizedigit(int *arr, int n)
{
    int i, max = arr[0], count = 0;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    while (max != 0)
    {
        max /= 10;
        count++;
    }
    return count;
}

void insert_into_list(int data, int rad)
{
    struct Node *new_node = createNode(data);
    struct Node *temp = radix[rad];
    if (temp == NULL)
    {
        radix[rad] = new_node;
    } else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
    }
}

void radix_sort(int *arr, int n)
{
    int i, j = 0, k, pass, digit, div = 1;
    pass = get_max_sizedigit(arr, n);

    for(i = 1; i <= pass; i++)
    {
        for(j = 0; j < n; j++)
        {
            digit = (arr[j] / div) % 10;

            insert_into_list(arr[j], digit);
        }
        div *= 10;
        j = 0;
        for (k = 0; k < 10; k++)
        {
            struct Node *temp = radix[k];
            radix[k] = NULL;
            while (temp != NULL)
            {
                struct Node *next = temp->next;
                arr[j++] = temp->data;
                free(temp);
                temp = next;
            }
        }
    }
}
void display(int *a, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main(int argc, char *argv[])
{
    int size;
    initializeList();
    int arr[] = { 1,13234,23,321,4321111,3000,32744,10,3838,22 };
    size =sizeof(arr)/sizeof(arr[0]);
    printf("Radix sort Input data set\n");
    display(arr, size);
    printf("\nRadix sort output data \n");
    radix_sort(arr, size);
    display(arr, size);

    return 0;
}
