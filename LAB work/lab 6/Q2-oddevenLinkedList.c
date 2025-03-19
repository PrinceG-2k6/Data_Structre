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
    printf(" %d ",temp->data);
}
void divideOddEven(struct node* head, struct node** oddhead, struct node** evenhead) {
    struct node* oddTail = NULL;
    struct node* evenTail = NULL;
    struct node* current = head;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (*evenhead == NULL) {
                *evenhead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        } else {
            if (*oddhead == NULL) {
                *oddhead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    if (oddTail != NULL) {
        oddTail->next = NULL;
    }
    if (evenTail != NULL) {
        evenTail->next = NULL;
    }
}
int main()
{   
    int i , n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    struct node* head = NULL;
    struct node* oddhead = NULL;
    struct node* evenhead = NULL;
    for(i=0;i<n;i++)
    {
        head = createNode(head);
    }
    printList(head);
    divideOddEven(head, &oddhead, &evenhead);
    printf("\nOdd List: ");
    printList(oddhead);
    printf("\nEven List: ");
    printList(evenhead);
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
    printf(" %d ",temp->data);
}
void divideOddEven(struct node* head, struct node** oddhead, struct node** evenhead) {
    struct node* oddTail = NULL;
    struct node* evenTail = NULL;
    struct node* current = head;

    while (current != NULL) {
        if (current->data % 2 == 0) {
            if (*evenhead == NULL) {
                *evenhead = current;
                evenTail = current;
            } else {
                evenTail->next = current;
                evenTail = evenTail->next;
            }
        } else {
            if (*oddhead == NULL) {
                *oddhead = current;
                oddTail = current;
            } else {
                oddTail->next = current;
                oddTail = oddTail->next;
            }
        }
        current = current->next;
    }

    if (oddTail != NULL) {
        oddTail->next = NULL;
    }
    if (evenTail != NULL) {
        evenTail->next = NULL;
    }
}
int main()
{   
    int i , n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    struct node* head = NULL;
    struct node* oddhead = NULL;
    struct node* evenhead = NULL;
    for(i=0;i<n;i++)
    {
        head = createNode(head);
    }
    printList(head);
    divideOddEven(head, &oddhead, &evenhead);
    printf("\nOdd List: ");
    printList(oddhead);
    printf("\nEven List: ");
    printList(evenhead);
    return 0 ;
}
>>>>>>> f9bc61ea0ddc790e5ebc925f061663eb968bce2f
