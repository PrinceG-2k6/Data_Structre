#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct Stacknode {
    int data;
    struct Stacknode* next;
};

void push(struct Stacknode** top, int data) {
    struct Stacknode* newnode = (struct Stacknode*)malloc(sizeof(struct Stacknode));
    if (!newnode) {
        printf("Stack overflow\n");
        return;
    }
    newnode->data = data;
    newnode->next = *top;
    *top = newnode;
}

void printStack(struct Stacknode* top) {
    while (top) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}

void createTwoStacks(struct node* head, struct Stacknode** stack1, struct Stacknode** stack2) {
    int count = 0;
    while (head) {
        if (count % 2 == 0) {
            push(stack1, head->data);
        } else {
            push(stack2, head->data);
        }
        head = head->next;
        count++;
    }
}

struct node* createnode(struct node* head){
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

void printList(struct node* head) {
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int i , n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    struct node* head = NULL;
    for(i=0;i<n;i++)
    {
        head = createnode(head);
    }

    printf("Original Linked List:\n");
    printList(head);

    struct Stacknode* stack1 = NULL;
    struct Stacknode* stack2 = NULL;

    createTwoStacks(head, &stack1, &stack2);

    printf("Stack 1:\n");
    printStack(stack1);

    printf("Stack 2:\n");
    printStack(stack2);

    return 0;
}
