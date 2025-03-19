<<<<<<< HEAD
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
    while(temp->next != NULL)
    {
        printf(" %d |",temp->data);
        temp = temp->next;
    }
    printf(" %d \n",temp->data);
}
struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
int main()
{   
    int i , n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    struct node* head = NULL;
    for(i=0;i<n;i++)
    {
        head = createNode(head);
    }
    printList(head);
    head = reverseList(head);
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
    while(temp->next != NULL)
    {
        printf(" %d |",temp->data);
        temp = temp->next;
    }
    printf(" %d \n",temp->data);
}
struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
int main()
{   
    int i , n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    struct node* head = NULL;
    for(i=0;i<n;i++)
    {
        head = createNode(head);
    }
    printList(head);
    head = reverseList(head);
    printList(head);
    return 0 ;
}
>>>>>>> f9bc61ea0ddc790e5ebc925f061663eb968bce2f
