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

int countTotalNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + countTotalNodes(root->left) + countTotalNodes(root->right);
}

int countLeafNodes(struct node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
    return countLeafNodes(root->left) + countLeafNodes(root->right);
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

    int totalNodes = countTotalNodes(root);
    int leafNodes = countLeafNodes(root);

    printf("Total Nodes: %d\n", totalNodes);
    printf("Leaf Nodes: %d\n", leafNodes);

    deleteTree(root);
    return 0;
}
