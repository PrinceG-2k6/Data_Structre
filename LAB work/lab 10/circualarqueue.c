#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct queue{
    int size;
    int f;
    int r;
    int *arr;

}que;

int isFull(que* q)
{
    if((q->r+1)%q->size==q->f)
    {
        return 1;
    }
    else{
        return 0;
    }
}

int isEmpty(que* q)
{
    if(q->r==q->f)
    {
        return 1;
    }
    else{
        return 0;
    }
}


void enq(que* q,int val)
{
    if(q->r!=-1 && isFull(q))
    {
        printf("OVERFLOW !");
    }
    else
    {
        q->r=(q->r+1)%q->size;
        q->arr[q->r]=val;
        printf("enqueeuing element is %d \n" ,val);
    }
}

int deq(que* q)
{
    int a =-1;
    if(isEmpty(q))
    {
        printf("Empty Queue \n");
    }
    else{
        a=q->arr[q->f];
        q->f=(q->f+1)%q->size;        
    }

    return a;

}

void displayQueue(que* q) {
    if (isEmpty(q)) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are: ");
    int i = q->f;
    while (i != q->r) {
        printf("%d ", q->arr[i]);
        i = (i + 1) % q->size;
    }
    printf("%d\n", q->arr[i]); // Print the last element
}

int main(){
    que* q = (que*)malloc(sizeof(que));
    q->size=3;
    q->f=0;q->r=-1;
    q->arr=(int*)malloc(q->size*sizeof(int));

    if(isEmpty(q))
    {
        printf("queeue Is Empty \n");
    }
    enq(q,10);
    enq(q,20);
    enq(q,30);
    
    displayQueue(q);
    printf("Dequeeuing element is %d \n" ,deq(q));
    // printf("Dequeeuing element is %d \n" ,deq(q));
    printf("Dequeeuing element is %d \n" ,deq(q));
    displayQueue(q);
    enq(q,10);
    enq(q,20);
    enq(q,30);
    // enq(q,30);

    
    if(isEmpty(q))
    {
        printf("queeue Is Empty \n");
    }
    if(isFull(q))
    {
        printf("queeue Is Full \n");
    }
    return 0;
}