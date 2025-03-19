<<<<<<< HEAD
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* Newnode = (struct node*)malloc(sizeof(struct node));
    Newnode->data=data;
    Newnode->next=NULL;
    return Newnode;
    
}

void printList(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

struct node * merge (struct node * head , struct node *head1)
{
    struct node * p = head;
    struct node * q = head1;
    struct node * a[8];
    int k = 0;
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            a[k]=p;
            k++;
            p=p->next;
        }
        else
        {
            a[k]=q;
            k++;
            q=q->next;
        }

        if(p==NULL)
        {
            while(q!=NULL)
            {
                a[k]=q;
                k++;
                q=q->next;
            }
        }
        if(q==NULL)
        {
            while(p!=NULL)
            {
                a[k]=p;
                k++;
                p=p->next;
            }
        }
    }

    for(k=1;k<8;k++)
    {
        a[k-1]->next=a[k];
    }
    head = a[0];

    return head;
}

int main()
{   
    int i=1,n,j=0;
    struct node * a[4];
    a[0]=createNode(10);
    a[1]=createNode(20);
    a[2]=createNode(30);
    a[3]=createNode(40);
    for(i=1;i<4;i++)
    {
        a[i-1]->next =a[i];
    }
    struct node * b[4];
    b[0]=createNode(5);
    b[1]=createNode(12);
    b[2]=createNode(25);
    b[3]=createNode(38);
    for(i=1;i<4;i++)
    {
        b[i-1]->next =b[i];
    }
    struct node * head = a[0];
    struct node * head1 = b[0];
    printList(head);
    printList(head1);
    

    head = merge(head , head1);
    printList(head);
    return 0 ;
}
=======
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* Newnode = (struct node*)malloc(sizeof(struct node));
    Newnode->data=data;
    Newnode->next=NULL;
    return Newnode;
    
}

void printList(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL \n");
}

struct node * merge (struct node * head , struct node *head1)
{
    struct node * p = head;
    struct node * q = head1;
    struct node * a[8];
    int k = 0;
    while(p!=NULL && q!=NULL)
    {
        if(p->data<q->data)
        {
            a[k]=p;
            k++;
            p=p->next;
        }
        else
        {
            a[k]=q;
            k++;
            q=q->next;
        }

        if(p==NULL)
        {
            while(q!=NULL)
            {
                a[k]=q;
                k++;
                q=q->next;
            }
        }
        if(q==NULL)
        {
            while(p!=NULL)
            {
                a[k]=p;
                k++;
                p=p->next;
            }
        }
    }

    for(k=1;k<8;k++)
    {
        a[k-1]->next=a[k];
    }
    head = a[0];

    return head;
}

int main()
{   
    int i=1,n,j=0;
    struct node * a[4];
    a[0]=createNode(10);
    a[1]=createNode(20);
    a[2]=createNode(30);
    a[3]=createNode(40);
    for(i=1;i<4;i++)
    {
        a[i-1]->next =a[i];
    }
    struct node * b[4];
    b[0]=createNode(5);
    b[1]=createNode(12);
    b[2]=createNode(25);
    b[3]=createNode(38);
    for(i=1;i<4;i++)
    {
        b[i-1]->next =b[i];
    }
    struct node * head = a[0];
    struct node * head1 = b[0];
    printList(head);
    printList(head1);
    

    head = merge(head , head1);
    printList(head);
    return 0 ;
}
>>>>>>> f9bc61ea0ddc790e5ebc925f061663eb968bce2f
