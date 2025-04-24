#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* createnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

struct node* addTwoLists(struct node* list1, struct node* list2) {
    struct node* result = NULL;
    struct node* head = NULL;
    int sum = 0;
    while (list1 || list2 ) {
        int sum = 0;
        if (list1) {
            sum += list1->data;
            list1 = list1->next;
        }
        if (list2) {
            sum += list2->data;
            list2 = list2->next;
        }
        if(head == NULL)
        {
            head = createnode(sum);
        }
        else{
            struct node* temp = head;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next = createnode(sum);
        }
        
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
    struct node* list1 = createnode(2);
    list1->next = createnode(4);
    list1->next->next = createnode(3);

    struct node* list2 = createnode(5);
    list2->next = createnode(5);
    list2->next->next = createnode(4);

    printf("List 1: ");
    printList(list1);

    printf("List 2: ");
    printList(list2);

    struct node* result =addTwoLists(list1, list2);

    printf("Result: ");
    printList(result);

    return 0;
}
