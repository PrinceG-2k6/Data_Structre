#include<stdio.h>
#include<stdlib.h>

struct Dnode{
    int data;
    struct Dnode* next;
    struct Dnode* prev;
};

struct Dnode* deleteAtBeg(struct Dnode* head)
{
    struct Dnode* temp = head;
    head = head->next;
    head->prev = NULL;
    free(temp);
    return head;
}
void deleteAtEnd(struct Dnode* tail)
{
    struct Dnode* temp = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(temp);
}
void deleteAtPos(struct Dnode* head)
{
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
    struct Dnode* temp1 = temp->next;
    temp->next = temp1->next;
    temp1->next->prev = temp;
    free(temp1);
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

    printf("1->Delete at the beginning\n2->Delete at the end\n3->Delete at the position\n");
    printf("Enter the where to delete : ");
    scanf("%d",&i);
    if(i==1)
    {
        head = deleteAtBeg(head);
        printList(head);
    }
    else if(i==2)
    {
        deleteAtEnd(tail);
        printList(head);
    }
    else if(i==3)
    {
        deleteAtPos(head);
        printList(head);
    }

    
    return 0 ;
}
