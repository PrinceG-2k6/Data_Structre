#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node{
    int data;
    struct node* next;
};
struct node * f = NULL;
struct node * r = NULL;

void enq(int val)
{
    struct node* n=(struct node*)malloc(sizeof(struct node));
    if(n==NULL)
    {
        printf("Queue is FULL ! \n");
    }
    else{
        n->data = val;
        n->next = NULL;
        
        if(f==NULL && r==NULL)
        {
            f=r=n;
        }
        else{
            r->next=n;
            r = n;
            r->next =f;
        }
    }
}
int deq()
{
    int val =-1;
    struct node* ptr =f;
    if(f==NULL)
    {
        printf("Queue is Empty \n");
    }
    else{
        f=f->next;
        r->next = f;
        val=ptr->data;
        free(ptr);
    }

    return val;
}

void display(struct node* f)
{
    struct node * temp =f;
    while(temp!=r)
    {
        printf("%d |",temp->data);
        temp=temp->next;
    }
    printf("%d \n",temp->data);
}

int main()
{
    int popped;
    enq(10);
    enq(11);
    enq(13);
    enq(20);
    display(f);
    popped=deq();
    printf("Dequeeuing element is %d \n" ,popped);
    display(f);
    enq(50);
    display(f);
    popped=deq();
    printf("Dequeeuing element is %d \n" ,popped);
    return 0;
}