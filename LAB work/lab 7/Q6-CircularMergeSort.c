#include <stdio.h>
#include <stdlib.h>

// Node structure for circular linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = newNode; // Circular link
    return newNode;
}

// Function to insert a node at the end of a circular linked list
Node* insertEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (!head) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

// Function to merge two sorted circular linked lists
Node* mergeCircularLists(Node* head1, Node* head2) {
    if (!head1) return head2;
    if (!head2) return head1;

    Node *result = NULL, *tail = NULL;

    Node *curr1 = head1, *curr2 = head2;
    do {
        Node* newNode;
        if (curr1->data <= curr2->data) {
            newNode = createNode(curr1->data);
            curr1 = curr1->next;
        } else {
            newNode = createNode(curr2->data);
            curr2 = curr2->next;
        }

        if (!result) {
            result = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }

        if (curr1 == head1 || curr2 == head2) break;
    } while (1);

    // Append remaining elements
    while (curr1 != head1) {
        tail->next = createNode(curr1->data);
        tail = tail->next;
        curr1 = curr1->next;
    }
    while (curr2 != head2) {
        tail->next = createNode(curr2->data);
        tail = tail->next;
        curr2 = curr2->next;
    }

    tail->next = result; // Make it circular
    return result;
}

// Function to print a circular linked list
void printCircularList(Node* head) {
    if (!head) return;
    Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function to test the merging
int main() {
    Node* list1 = NULL;
    Node* list2 = NULL;

    // Creating first sorted circular linked list
    list1 = insertEnd(list1, 1);
    list1 = insertEnd(list1, 3);
    list1 = insertEnd(list1, 5);

    // Creating second sorted circular linked list
    list2 = insertEnd(list2, 2);
    list2 = insertEnd(list2, 4);
    list2 = insertEnd(list2, 6);

    printf("List 1: ");
    printCircularList(list1);

    printf("List 2: ");
    printCircularList(list2);

    // Merging the two lists
    Node* mergedList = mergeCircularLists(list1, list2);

    printf("Merged List: ");
    printCircularList(mergedList);

    return 0;
}