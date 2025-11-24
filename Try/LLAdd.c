#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;
    struct node *next;
} n;

n *head1 = NULL;
n *tail1 = NULL;
n *head2 = NULL;
n *tail2 = NULL;
n *head3 = NULL;
n *tail3 = NULL;
int carry =0;

void create(n **head, n **tail, int x)
{
    n *newNode = (n *)malloc(sizeof(n));
    newNode->data = x;
    newNode->next = NULL;

    if (*head != NULL)
    {
        (*tail)->next = newNode;
        *tail = newNode;
    }
    else
    {
        *head = newNode;
        *tail = newNode;
    }
}

void printList(n *head)
{
    n *temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void add(n **h1, n **h2)
{
    n *t1 = *h1;
    n *t2 = *h2;
    
}

int main()
{
    int x = 54327;
    int temp = x;

    while (temp > 0)
    {
        create(&head1, &tail1, temp % 10);
        temp = temp / 10;
    }

    int y = 42562;
    temp = y;

    while (temp > 0)
    {
        create(&head2, &tail2, temp % 10);
        temp = temp / 10;
    }

    printList(head1);
    printList(head2);
    add(head1, head2);
    return 0;
}
