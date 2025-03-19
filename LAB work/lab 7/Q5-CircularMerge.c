#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

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
    printf("Enter the number of nodes for 1st circular linked list : ");
    scanf("%d",&n);
    struct node* head1 = NULL;
    struct node* tail1 = NULL;
    for(i=0;i<n;i++)
    {
        head1 = createNode(head1);
    }
    struct node* temp=head1;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    tail1 = temp;
    tail1->next = head1;
    
    printf("The 1st Circular Linked List is : ");
    printList(head1);

    printf("Enter the number of nodes for 2nd circular linked list : ");
    scanf("%d",&n);
    struct node* head2 = NULL;
    struct node* tail2 = NULL;
    for(i=0;i<n;i++)
    {
        head2 = createNode(head2);
    }
    temp=head2;
    while(temp->next!=NULL)
    {
        temp = temp->next;
    }
    tail2 = temp;
    tail2->next = head2;
    
    printf("The 2nd Circular Linked List is : ");
    printList(head2);

    tail1->next=head2;
    tail2->next=head1;

    printf("The Merged Circular Linked List is : ");
    printList(head1);
    return 0 ;
}
