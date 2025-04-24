#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

int search(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value) {
            return i;
        }
    }
    return -1;
}

Node* buildTree(int inorder[], int preorder[], int inorderStart, int inorderEnd, int* preorderIndex) {
    if (inorderStart > inorderEnd) {
        return NULL;
    }

    int current = preorder[*preorderIndex];
    (*preorderIndex)++;
    Node* node = createNode(current);

    if (inorderStart == inorderEnd) {
        return node;
    }

    int inorderIndex = search(inorder, inorderStart, inorderEnd, current);

    node->left = buildTree(inorder, preorder, inorderStart, inorderIndex - 1, preorderIndex);
    node->right = buildTree(inorder, preorder, inorderIndex + 1, inorderEnd, preorderIndex);

    return node;
}

void printInorder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d ", root->data);
    printInorder(root->right);
}

int main() {
    int inorder[] = {4, 2, 5, 1, 6, 3, 7};
    int preorder[] = {1, 2, 4, 5, 3, 6, 7};
    int n = sizeof(inorder) / sizeof(inorder[0]);

    int preorderIndex = 0;
    Node* root = buildTree(inorder, preorder, 0, n - 1, &preorderIndex);

    printf("Inorder traversal of the reconstructed tree: ");
    printInorder(root);

    return 0;
}
