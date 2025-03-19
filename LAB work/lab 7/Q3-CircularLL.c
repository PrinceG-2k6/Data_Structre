#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
void deleteAtBeg(struct node** head ,struct node** tail)
{
    if (*head == NULL)
        return;
        struct node* temp = *head;
        (*tail)->next = (*head)->next;
        *head = (*head)->next;
        free(temp);
}
void deleteAtEnd(struct node** head ,struct node** tail)
{
    if (*head == NULL)
        return;
    struct node* temp = *head;
    while (temp->next->next != *head)
    {
        temp = temp->next;
    }
    struct node* temp1 = temp->next;
    temp->next = *head;
    *tail=temp;
    free(temp1);

}
void deleteAtPos(struct node** head,struct node** tail)
{
    struct node* temp = *head;
    int pos;
    printf("Enter the position : ");
    scanf("%d",&pos);
    int i = 0;
    while(i<pos-1)
    {
        temp = temp->next;
        i++;
    }
    struct node* temp1 = temp->next;
    temp->next = temp1->next;
    free(temp1);
}
void InsertAtBeg(struct node** head,struct node** tail)
{
    struct node* Newnode = (struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    Newnode->data = data;
    Newnode->next = *head;
   (*tail)->next = Newnode;
    *head = Newnode;
    
}
void InsertAtEnd(struct node** head,struct node** tail)
{
    struct node* Newnode = (struct node*)malloc(sizeof(struct node));
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    Newnode->data = data;
    Newnode->next = *head;

    struct node* temp = *head;
   (*tail)->next = Newnode;
    *tail = Newnode;
}
void InsertAtPos(struct node** head,struct node** tail)
{
    struct node* Newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp = *head;
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
    Newnode->data = data;
    Newnode->next = temp->next;
    temp->next = Newnode;
}
struct node* createNode(struct node* head){
    struct node* Newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    int data;
    printf("Enter the data : ");
    scanf("%d",&data);
    Newnode->data = data;
    Newnode->next = NULL;
    if(head == NULL)
    {
        head = Newnode;
    }
    else
    {
        temp= head;
        while (temp->next!=NULL)
        {
            temp = temp->next;
        }
        temp->next = Newnode;
        
    }
    return head;
}

void printList(struct node* head)
{
    struct node* temp = head;
    while(temp->next != head)
    {
        printf(" %d |",temp->data);
        temp = temp->next;
    }
    printf(" %d \n",temp->data);
}
int main()
{   
    int i , n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    struct node* head = NULL;
    
    struct node* tail = NULL;
    for(i=0;i<n;i++)
    {
        head = createNode(head);
    }
    struct node* temp=head;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    tail = temp;
    tail->next = head;
    
    printf("The Circular Linked List is : ");
    printList(head);

    printf("1->Delete a node\n2->Insert a node\n");
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
        }
        else if(i==2)
        {
            deleteAtEnd(&head,&tail);
            printList(head);
        }
        else if(i==3)
        {
            deleteAtPos(&head,&tail);
            printList(head);
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
        }
        else if(i==2)
        {
            InsertAtEnd(&head,&tail);
            printList(head);
        }
        else if(i==3)
        {
            InsertAtPos(&head,&tail);
            printList(head);
        }
    }
    return 0 ;
}
