#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
    
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

struct node* insertatFirst(struct node *head , int data)
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next=head;
    ptr->data=data;
    head = ptr;
    return ptr;
}

struct node* insertAtPosition(struct node* head, int data, int idx) 
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p =head;
    int i =0;
    ptr->data=data;
    while(i!=idx-1)
    {
        p=p->next;
        i++;
    }
    ptr->next = p->next;
    p->next=ptr;
    return head;
}
struct node* insertAtEnd(struct node * head,int data)
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    struct node * p =head;
    int i =0;
    ptr->data=data;
    while(p->next != NULL)
    {
        p=p->next;
    }
    p->next=ptr;
    ptr->next=NULL;
    return head;
}

struct node* insertAfterNode(struct node * head,struct node * prevnode,int data)
{
    struct node* ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data=data;

    ptr->next = prevnode->next;
    prevnode->next = ptr;

    return head;
}


int main()
{
    struct node* head = createnode(1);
    struct node* second = createnode(2);
    struct node* third = createnode(3);
    struct node* fourth = createnode(4);
    struct node* fifth = createnode(5);


    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;

    printList(head);

    int data;
        printf("\nEnter the data u want to insert\n");
        scanf("%d",&data);

    printf("\n Where u want to insert \n1 ->Beginning\n2 ->End\n3 ->Specific Position\n");
    int i;
    scanf("%d",&i);
    if(i==1)
    {   
        
        head = insertatFirst(head , data);
        printList(head);

    }
    if(i==2)
    {
        struct node* insert = createnode(data);
        insertAtEnd(head , data);
        printList(head);

    }
    if(i==3)
    {
        
        int idx;
         printf("\nEnter the index where u want to insert\n");
        scanf("%d",&idx);
        
        insertAtPosition(head, data, idx);
        printList(head);
    }
    // printf("\n");
    // head = insertAfterNode(head ,second ,555);
    // printList(head);

    return 0 ;
}
