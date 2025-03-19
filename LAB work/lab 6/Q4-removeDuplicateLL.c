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
void removeDuplicates(struct node* head) {
    struct node* current = head;
    struct node* prev = NULL;
    struct node* temp;
    
    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;
        
        while (temp != NULL) {
            if (current->data == temp->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}
void printList(struct node* head)
{
    struct node* temp = head;
    while(temp->next != NULL)
    {
        printf(" %d |",temp->data);
        temp = temp->next;
    }
    printf(" %d ",temp->data);
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
    removeDuplicates(head);
    printf("\nAfter removing duplicates: ");
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
void removeDuplicates(struct node* head) {
    struct node* current = head;
    struct node* prev = NULL;
    struct node* temp;
    
    while (current != NULL && current->next != NULL) {
        prev = current;
        temp = current->next;
        
        while (temp != NULL) {
            if (current->data == temp->data) {
                prev->next = temp->next;
                free(temp);
                temp = prev->next;
            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        current = current->next;
    }
}
void printList(struct node* head)
{
    struct node* temp = head;
    while(temp->next != NULL)
    {
        printf(" %d |",temp->data);
        temp = temp->next;
    }
    printf(" %d ",temp->data);
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
    removeDuplicates(head);
    printf("\nAfter removing duplicates: ");
    printList(head);
    return 0 ;
}
>>>>>>> f9bc61ea0ddc790e5ebc925f061663eb968bce2f
