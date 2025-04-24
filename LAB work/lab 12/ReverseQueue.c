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
        val=ptr->data;
        free(ptr);
    }

    return val;
}

void display(struct node* f)
{
    struct node * temp =f;
    while(temp->next!=NULL)
    {
        printf("%d |",temp->data);
        temp=temp->next;
    }
    printf("%d <- rear\n",temp->data);
}

void reverseQueue()
{
    struct node *prev = NULL, *current = f, *next = NULL;
    r = f; 
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    f = prev;
}

int main()
{
    int popped;
    enq(10);
    enq(11);
    enq(13);
    enq(20);
    enq(21);
    enq(83);
    enq(90);
    printf("front-> ");
    display(f);
    reverseQueue();
    printf("front-> ");
    display(f);
    return 0;
}