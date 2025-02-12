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
        printf("| %d |",temp->data);
        temp = temp->next;
    }
}

struct node * deleteFirst(struct node *head)
{
    struct node * ptr = head;
    head = head->next;
    free(ptr);
    return head;
}
struct node * deleteLast(struct node *head)
{
    struct node * p = head;
    struct node * q = head->next;
    while(q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    return head;
}

struct node * deleteindex(struct node *head,int index)
{
    struct node * p = head;
    struct node * q = head->next;
    for(int i=0;i<index-1;i++)
    {
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    free(q);
    return head;
}

struct node * deleteData(struct node *head,int data)
{
    struct node * p = head;
    struct node * q = head->next;
    while(q->data!=data && q->next!=NULL)
    {
        p=p->next;
        q=q->next;
    }
    if(q->data==data)
    {
    p->next=q->next;
    free(q);
    }
    else{
        printf("\nElement is not there\n");
    }
    return head;
}

int main()
{
    struct node* head = createNode(1);
    struct node* second = createNode(2);
    struct node* third = createNode(3);
    struct node* fourth = createNode(4);
    struct node* fifth = createNode(5);


    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;

    printList(head);
    int i;
    printf("\nDELETION\n1->Beginning\n2->End\n3->Specific \n4->delete at value\n\n");
    scanf("%d",&i);
    if(i==1)
    {
        head = deleteFirst(head);
        printList(head);
    }
    if(i==2)
    {
        head = deleteLast(head);
        // head = deleteLast(head);
        printList(head);
    }
    if(i==3)
    {   
        int index ;
        printf("\nEnter the index\n");
        scanf("%d",&index);
        head = deleteindex(head ,2);
        printList(head);
    }
    if(i==4)
    {
        int data;
        printf("\nEnter the data u want to delete  :");
        scanf("%d",&data);

        head = deleteData(head ,data);
        printList(head);
    }


    return 0 ;
}
