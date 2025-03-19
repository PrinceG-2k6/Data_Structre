#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(struct node* head , int data){
    struct node* Newnode = (struct node*)malloc(sizeof(struct node));
    struct node* temp;
    
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
    int data;
    printf("Enter the number of nodes for 1st Sorted circular linked list : ");
    scanf("%d",&n);
    struct node* head1 = NULL;
    struct node* tail1 = NULL;
    for(i=0;i<n;i++)
    {
        
        printf("Enter the data : ");
        scanf("%d",&data);
        head1 = createNode(head1 , data);
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

    printf("Enter the number of nodes for 2nd Sorted circular linked list : ");
    scanf("%d",&n);
    struct node* head2 = NULL;
    struct node* tail2 = NULL;
    for(i=0;i<n;i++)
    {
        printf("Enter the data : ");
        scanf("%d",&data);
        head2 = createNode(head2 , data);
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
    
    struct node* temp1 = head1;
    struct node* temp2 = head2;
    struct node* head=0;
    while(temp1!=0 && temp2!=0)
    {
        if(temp1->data < temp2->data)
        {
            head = createNode(head , temp1->data);
            temp1 = temp1->next;
        }
        else 
        {
            head = createNode(head ,temp2->data);
            temp2 = temp2->next;
        }
    }

    if(temp2=0)
    {
        while(temp1!=0)
        {
            head = createNode(head , temp1->data);
            temp1 = temp1->next;
        }
    }else
    {
        while(temp2!=0)
        {
            head = createNode(head ,temp2->data);
            temp2 = temp2->next;
        }
    }

    printf("The Merged Sorted Circular Linked List is :  ");
    printList(head);
    return 0 ;
}
