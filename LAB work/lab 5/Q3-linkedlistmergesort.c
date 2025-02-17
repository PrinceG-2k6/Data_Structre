#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * next;
};

struct node* Creatnode(int data)
{   
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}
int SizeOfList(struct node* head)
{
    int i=0;
    struct node* temp =head;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
}

void Printlist(struct node* head)
{
    struct node* temp = head;
    while(temp!=NULL)
    {
        printf("| %d |",temp->data);
        temp=temp->next;
    }
}

void merge(int *a, int l, int m, int h) 
{
    int i, j, k;
    int b[50];
    i = l;
    j = m+1;
    k = l;

    while(i<=m && j<=h)
    {
        if(a[i] < a[j])
        {
            b[k] = a[i];
            i++;
        }
        else
        {
            b[k] = a[j];
            j++;
        }
        k++;

    }

    while(i<=m)
    {
        b[k] = a[i];
        i++;
        k++;
    }
    while (j<=h)
    {
        b[k] = a[j];
        j++;
        k++;
    }
    
    for(i=l;i<=h;i++)
    {
        a[i]=b[i];
    }
}

void mergeSort(int *a, int l, int h) {
    if (l < h) {
        int m = (l+h) / 2;

        mergeSort(a, l, m);
        mergeSort(a, m + 1, h);

        merge(a, l, m, h);
    }
}

void printarray(int *a, int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}


int main()
{
    struct node* b[5];
    int i,data;
    struct node* head;
    
    for(i=0;i<5;i++)
    {
        printf("Enter data : ");
        scanf("%d",&data);
        b[i]=Creatnode(data);
        if(i>0)
        {
            b[i-1]->next=b[i];
        }
    }
    head = b[0];
    Printlist(head);

    int n = SizeOfList(head);
    int a[n];

    for(i=0;i<5;i++)
    {
        a[i]=b[i]->data;
    }
    mergeSort(a,0,n-1);
    for(i=0;i<5;i++)
    {
        b[i]->data=a[i];
    }
    head=b[0];
    printf("\nSorted Linked list\n");
    Printlist(head);

    return 0 ;

}