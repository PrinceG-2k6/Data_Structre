#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char name[50];
    int age;
    struct Node *nextName;
    struct Node *nextAge;
} Node;

Node *headName = NULL;
Node *headAge = NULL;

// Create a new node
Node* createNode(char *name, int age) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->nextName = NULL;
    newNode->nextAge = NULL;
    return newNode;
}

// Insert into name-sorted list (alphabetical)
void insertByName(Node *newNode) {
    if (headName == NULL || strcmp(newNode->name, headName->name) < 0) {
        newNode->nextName = headName;
        headName = newNode;
        return;
    }
    Node *temp = headName;
    while (temp->nextName != NULL &&
           strcmp(newNode->name, temp->nextName->name) > 0) {
        temp = temp->nextName;
    }
    newNode->nextName = temp->nextName;
    temp->nextName = newNode;
}

// Insert into age-sorted list (increasing age)
void insertByAge(Node *newNode) {
    if (headAge == NULL || newNode->age < headAge->age) {
        newNode->nextAge = headAge;
        headAge = newNode;
        return;
    }
    Node *temp = headAge;
    while (temp->nextAge != NULL && newNode->age > temp->nextAge->age) {
        temp = temp->nextAge;
    }
    newNode->nextAge = temp->nextAge;
    temp->nextAge = newNode;
}

// Insert node into both lists
void insert(char *name, int age) {
    Node *newNode = createNode(name, age);
    insertByName(newNode);
    insertByAge(newNode);
}

// Display list sorted by name
void displayByName() {
    Node *temp = headName;
    printf("\nList sorted by NAME:\n");
    while (temp != NULL) {
        printf("%s (%d)\n", temp->name, temp->age);
        temp = temp->nextName;
    }
}

// Display list sorted by age
void displayByAge() {
    Node *temp = headAge;
    printf("\nList sorted by AGE:\n");
    while (temp != NULL) {
        printf("%s (%d)\n", temp->name, temp->age);
        temp = temp->nextAge;
    }
}

int main() {
    insert("Riya", 22);
    insert("Aman", 19);
    insert("Karan", 25);
    insert("Meena", 20);
    insert("Arjun", 25);

    displayByName();
    displayByAge();

    return 0;
}
