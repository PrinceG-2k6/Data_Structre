#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

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

struct node* reverseKGroup(struct node* head, int k) {
    if (!head || k <= 1) return head;

    struct node* prev = NULL;
    struct node* curr = head;
    struct node* next = NULL;
    int count = 0;

    struct node* temp = head;
    for (count = 0; temp != NULL && count < k; count++) {
        temp = temp->next;
    }

    if (count < k) return head;

    count = 0;
    while (curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL) {
        head->next = reverseKGroup(next, k);
    }

    return prev;
}

void printList(struct node* head) {
    while (head != NULL) {
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
    printList(head);

    int k;
    printf("Enter the number of nodes in group to reverse: ");
    scanf("%d",&k);

    printf("Original List:\n");
    printList(head);

    head = reverseKGroup(head, k);

    printf("Reversed List in Groups of %d:\n", k);
    printList(head);

    return 0;
}
