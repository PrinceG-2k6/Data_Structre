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

struct node* search(struct node* root , int key ){
    if(root == NULL){
        return NULL;
    }
    if(root->data ==key)
    {return root;}
    else if(root->data>key)
    {
        return search(root->left , key);
    }
    else{
        return search(root->right , key);
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

    struct node * n = search(root ,1);
    if(n!=NULL)
    {
        printf("Found %d",n->data);
    }
    else{
        printf("ElEMENT NOT FOUND!!!");
    }

    deleteTree(root);
    return 0;
}
