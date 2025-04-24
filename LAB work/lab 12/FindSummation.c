#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void InOrderTraversal(struct node* root)
{
    if(root!=NULL)
    {
        InOrderTraversal(root->left);
        printf("%d" ,root->data);
        InOrderTraversal(root->right);
    }
}

int findPairWithSum(struct node* root, int target, struct node** node1, struct node** node2) {
    if (root == NULL) {
        return 0;
    }

    static struct node* nodes[100];
    static int index = 0;

    // Perform in-order traversal and store nodes in an array
    findPairWithSum(root->left, target, node1, node2);
    nodes[index++] = root;
    findPairWithSum(root->right, target, node1, node2);

    // Check for the pair
    for (int i = 0; i < index; i++) {
        for (int j = i + 1; j < index; j++) {
            if (nodes[i]->data + nodes[j]->data == target) {
                *node1 = nodes[i];
                *node2 = nodes[j];
                return 1;
            }
        }
    }

    return 0;
}

void findAndPrintPair(struct node* root, int target) {
    struct node* node1 = NULL;
    struct node* node2 = NULL;

    if (findPairWithSum(root, target, &node1, &node2)) {
        printf("Pair found: %d and %d\n", node1->data, node2->data);
    } else {
        printf("No pair found with the sum %d\n", target);
    }
}

void deleteTree(struct node* root) {
    if (root == NULL) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    free(root);
}
int main() {
    struct node* root = createNode(4);
    root->left = createNode(2);
    root->right = createNode(5);
    root->left->left = createNode(1);
    root->left->right = createNode(3);
    
    /*
                4
               / \
              2   5
             / \  
             1  3   
    */


    printf("Inorder Traversal: ");
    InOrderTraversal(root);
    printf("\n");

    struct node* node1=NULL;
    struct node* node2=NULL;

    int target = 7;
    findAndPrintPair(root, target);
    

    deleteTree(root);
    return 0;
}
