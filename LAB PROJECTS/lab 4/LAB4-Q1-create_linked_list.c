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

void printList(struct node* head)
{
    struct node* temp = head;
    while(temp != NULL)
    {
        printf("%d -> ",temp->data);
        temp = temp->next;
    }
    printf("NULL");
}

int main()
{
    struct node* head = createNode(1);
    struct node* second = createNode(2);
    struct node* third = createNode(3);
    struct node* fourth = createNode(4);
    struct node* fifth = createNode(5);


    head->next=second;
    second->next=third;
    third->next=fourth;
    fourth->next=fifth;

    printList(head);

    free(head);
    free(second);
    free(third);
    free(fourth);
    free(fifth);

    return 0 ;
}
