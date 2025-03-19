#include<stdio.h>
#include<stdlib.h>

struct Dnode{
    int data;
    struct Dnode* next;
    struct Dnode* prev;
};
void InsertAtBeg(struct Dnode** head)
{
    struct Dnode* NewDnode = (struct Dnode*)malloc(sizeof(struct Dnode));
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    NewDnode->data = data;
    NewDnode->next = *head;
    if (*head != NULL)
        (*head)->prev = NewDnode;
    *head = NewDnode;
}
void InsertAtEnd(struct Dnode* tail)
{
    struct Dnode* NewDnode = (struct Dnode*)malloc(sizeof(struct Dnode));
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    NewDnode->data = data;
    NewDnode->next = NULL;
    tail->next = NewDnode;
    NewDnode->prev = tail;
    tail = NewDnode;
}
void InsertAtPos(struct Dnode* head)
{
    struct Dnode* NewDnode = (struct Dnode*)malloc(sizeof(struct Dnode));
    struct Dnode* temp = head;
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    int i = 0;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    NewDnode->data = data;
    NewDnode->next = temp->next;
    temp->next->prev = NewDnode;
    temp->next = NewDnode;
    NewDnode->prev = temp;
}
struct Dnode* createDnode(struct Dnode* head){
    struct Dnode* NewDnode = (struct Dnode*)malloc(sizeof(struct Dnode));
    struct Dnode* tail;
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    NewDnode->data = data;
    NewDnode->next = NULL;
    if(head == NULL)
    {
        head = NewDnode;
        tail = NewDnode;
    }
    else
    {
        tail= head;
        while (tail->next!=NULL)
        {
            tail = tail->next;
        }
        tail->next = NewDnode;
        NewDnode->prev = tail;
        tail = NewDnode;
        
    }
    return head;
}

void printList(struct Dnode* head)
{
    struct Dnode* temp = head;
    while(temp->next != NULL)
    {
        printf(" %d |",temp->data);
        temp = temp->next;
    }
    printf(" %d \n",temp->data);

}
int main()
{   
    int i , n;
    printf("Enter the number of Dnodes : ");
    scanf("%d",&n);
    struct Dnode* head = NULL;
    for(i=0;i<n;i++)
    {
        head = createDnode(head);
    }
    printList(head);

    struct Dnode* tail = NULL;
    struct Dnode* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    tail = temp;

    printf("1->Insert at the beginning\n2->Insert at the end\n3->Insert at the position\n");
    printf("Enter the where to Insert : ");
    scanf("%d",&i);
    if(i==1)
    {
        InsertAtBeg(&head);
        printList(head);
    }
    else if(i==2)
    {
        InsertAtEnd(tail);
        printList(head);
    }
    else if(i==3)
    {
        InsertAtPos(head);
        printList(head);
    }


    return 0 ;
}
