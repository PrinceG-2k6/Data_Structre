#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createNode(int data){
    struct node* Newnode = (struct node*)malloc(sizeof(struct node));
    Newnode->data=data;
    Newnode->next=NULL;
    return Newnode;
    
}

struct node* Concate(struct node* head , struct node * head2 )
{
    int i,j,k,p=0,q=0;
    struct node * ptr = head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next = head2;
    return head;
}

void printList(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("| %d |",temp->data);
        temp = temp->next;
    }
    
}

int main()
{
    //1st linked list
    struct node* head = createNode(1);
    struct node* second = createNode(2);
    struct node* third = createNode(3);
    struct node* fourth = createNode(4);
    struct node* fifth = createNode(5);
    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;
    fifth->next=NULL;

    //2nd linked list
    struct node* head2 = createNode(6);
    struct node* second2 = createNode(7);
    struct node* third2 = createNode(8);
    struct node* fourth2 = createNode(9);
    struct node* fifth2 = createNode(10);
    head2->next=second2;
    second2->next=third2;
    third2->next=fourth2;
    fourth2->next=fifth2;
    fifth2->next=NULL;

    printf("\n1st linked list\n");
    printList(head);
    printf("\n2nd linked list\n");
    printList(head2);

    printf("\nConcated linked list\n");
    head = Concate(head ,head2);
    printList(head);


    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0 ;
}
