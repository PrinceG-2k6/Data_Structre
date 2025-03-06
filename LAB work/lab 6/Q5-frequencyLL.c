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
void Frequency(struct node* head)
{
    int count = 0 , check =0;
    struct node * search=head;
    struct node* temp = head;
    while(search!=NULL)
    {
        while (temp != NULL)
        {
            if (search->data == temp->data)
            {
                count++;
            }
            temp = temp->next;
        }
        struct node * prev = search;
        while (prev != NULL)
        {
            if (search->data == prev->data)
            {
                check++;
            }
            prev = prev->next;
        }
        if(count == check )
        {
            printf("The frequency of %d is %d\n",search->data,count);
        }
        count = 0 ;
        check = 0;
        search = search->next;
        temp=head;
        
    }
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
    Frequency(head);
    return 0 ;
}
