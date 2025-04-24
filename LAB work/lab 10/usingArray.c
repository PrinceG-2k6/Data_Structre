#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Queue{
    int size;
    int f;
    int r;
    int *arr;

}qu;

int* count;

int isFull(qu* q)
{
    if(q->r==q->size-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(qu* q)
{
    if(q->r==-1)
    {
        return 1;
    }
    else{
        return 0;
    }
}


void enq(qu* q,int val)
{
    if(isFull(q))
    {
        printf("OVERFLOW !");
    }
    else
    {
        q->r=q->r+1;
        q->arr[q->r]=val;
    }
}

int deq(qu* q)
{
    int a =-1;
    if(isEmpty(q))
    {
        printf("No element is dequeue \n");
    }
    else{
        q->f++;
        a=q->arr[q->f];
        
    }

    return a;

}

void displayQueue(qu* q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue elements are: ");
        for (int i = q->f + 1; i <= q->r; i++)
        {
            printf("%d ", q->arr[i]);
        }
        printf("\n");
    }
}


int main(){
    qu* q = (qu*)malloc(sizeof(qu));
    q->size=5;
    q->f=-1;q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

    // if(isEmpty(q))
    // {
    //     printf("Queue Is Empty \n");
    // }
    enq(q,10);
    enq(q,20);
    enq(q,30);
    displayQueue(q);
    printf("enqueuing element is 40\n");
    enq(q,40);
    displayQueue(q);
    printf("Dequeuing element is %d \n" ,deq(q));
    displayQueue(q);
    
    if(isEmpty(q))
    {
        printf("Queue Is Empty \n");
    }
    if(isFull(q))
    {
        printf("Queue Is Full \n");
    }
    return 0;
}