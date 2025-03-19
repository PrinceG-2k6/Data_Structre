#include<stdio.h>
#include<stdlib.h>

struct Dnode{
    int data;
    struct Dnode* next;
    struct Dnode* prev;
};

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
    return 0 ;
}
