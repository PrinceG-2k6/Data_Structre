#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* merge(struct node* l1, struct node* l2) {
    if (!l1) return l2;
    if (!l2) return l1;

    if (l1->data < l2->data) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}


struct node* getMiddle(struct node* head) {
    if (!head) return head;

    struct node *slow = head, *fast = head->next;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

struct node* mergeSort(struct node* head) {
    if (!head || !head->next) return head;

    struct node* middle = getMiddle(head);
    struct node* nextToMiddle = middle->next;
    middle->next = NULL;

    struct node* left = mergeSort(head);
    struct node* right = mergeSort(nextToMiddle);

    return merge(left, right);
}

struct node* Creatnode(int data)
{  
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void printList(struct node* head) {
    while (head) {
        printf("| %d |", head->data);
        head = head->next;
    }
}
int main() {
    struct node* head = Creatnode(4);
    head->next = Creatnode(2);
    head->next->next = Creatnode(1);
    head->next->next->next = Creatnode(3);

    printf("Original List: ");
    printList(head);

    head = mergeSort(head);

    printf("Sorted List: ");
    printList(head);

    return 0;
}
