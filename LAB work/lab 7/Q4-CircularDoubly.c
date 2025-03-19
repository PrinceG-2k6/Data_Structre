#include<stdio.h>
#include<stdlib.h>

struct Dnode{
    int data;
    struct Dnode* next;
    struct Dnode* prev;
};
void deleteAtBeg(struct Dnode** head ,struct Dnode** tail)
{
    if (*head == NULL)
        return;
        struct Dnode* temp = *head;
        (*tail)->next = (*head)->next;
        *head = (*head)->next;
        (*head)->prev=*tail;
        free(temp);
}
void deleteAtEnd(struct Dnode** head ,struct Dnode** tail)
{
    if (*head == NULL)
        return;
    // struct Dnode* temp = *head;
    // while (temp->next->next != *head)
    // {
    //     temp = temp->next;
    // }
    // struct Dnode* temp1 = temp->next;
    // temp->next = *head;
    // (*head)->prev=temp;
    // *tail=temp;
    // free(temp1);
    struct Dnode* temp = (*head)->prev;
    (*head)->prev = (*tail)->prev;
    *tail = (*tail)->prev;
    (*tail)->next=*head;
    free(temp);

}
void deleteAtPos(struct Dnode** head,struct Dnode** tail)
{
    struct Dnode* temp = *head;
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    int i = 0;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    struct Dnode* temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev=temp;
    free(temp1);
}
void InsertAtBeg(struct Dnode** head,struct Dnode** tail)
{
    struct Dnode* NewDnode = (struct Dnode*)malloc(sizeof(struct Dnode));
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    NewDnode->data = data;
    NewDnode->next = *head;
    (*head)->prev=NewDnode;
   (*tail)->next = NewDnode;
    *head = NewDnode;
    NewDnode->prev = *tail;
    
}
void InsertAtEnd(struct Dnode** head,struct Dnode** tail)
{
    struct Dnode* NewDnode = (struct Dnode*)malloc(sizeof(struct Dnode));
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    NewDnode->data = data;
    (*tail)->next=NewDnode;
    NewDnode->prev=*tail;
    *tail=(*tail)->next;
    (*tail)->next=*head;
    (*head)->prev =*tail;
}
void InsertAtPos(struct Dnode** head,struct Dnode** tail)
{
    struct Dnode* NewDnode = (struct Dnode*)malloc(sizeof(struct Dnode));
    struct Dnode* temp = *head;
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
    temp->next->prev=NewDnode;
    temp->next = NewDnode;
    NewDnode->prev=temp;
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
    printf("Printing by head   : ");
    while(temp->next != head)
    {
        printf(" %d |",temp->data);
        temp = temp->next;
    }
    printf(" %d \n",temp->data);

}
void printtail(struct Dnode* tail)
{
    struct Dnode* temp = tail;
    printf("Printing by tail   : ");
    while(temp->prev != tail)
    {
        printf(" %d |",temp->data);
        temp = temp->prev;
    }
    printf(" %d \n",temp->data);
}
int main()
{   
    int i , n;
    printf("Enter the number of Dnodes : ");
    scanf("%d",&n);
    struct Dnode* head = NULL;
    struct Dnode* tail = NULL;
    for(i=0;i<n;i++)
    {
        head = createDnode(head);
    }
    struct Dnode* temp =head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    tail = temp;
    tail->next = head;
    head->prev= tail;


    printList(head);
    printtail(tail);

    printf("1->Delete a Dnode\n2->Insert a Dnode\n");
    scanf("%d",&n);
    if(n==1)
    {
        printf("1->Delete at the beginning\n2->Delete at the end\n3->Delete at the position\n");
        printf("Enter the where to delete : ");
        scanf("%d",&i); 

        if(i==1)
        {
            deleteAtBeg(&head , &tail);
            printList(head);
            printtail(tail);
        }
        else if(i==2)
        {
            deleteAtEnd(&head,&tail);
            printList(head);
            printtail(tail);
        }
        else if(i==3)
        {
            deleteAtPos(&head,&tail);
            printList(head);
            printtail(tail);
        }
    }
    if(n==2)
    {
        printf("1->Insert at the beginning\n2->Insert at the end\n3->Insert at the position\n");
        printf("Enter the where to Insert : ");
        scanf("%d",&i);
        if(i==1)
        {
            InsertAtBeg(&head,&tail);
            printList(head);
            printtail(tail);
        }
        else if(i==2)
        {
            InsertAtEnd(&head,&tail);
            printList(head);
            printtail(tail);
        }
        else if(i==3)
        {
            InsertAtPos(&head,&tail);
            printList(head);
            printtail(tail);
        }
    }
 
    
    return 0 ;
}
