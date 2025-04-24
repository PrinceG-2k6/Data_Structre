#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node * left;
    struct node * right;
};
struct node * createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}
void preOrderTraversal(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d" ,root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
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

void PostOrderTraversal(struct node* root)
{
    if(root!=NULL)
    {
        
        PostOrderTraversal(root->left);
        PostOrderTraversal(root->right);
        printf("%d" ,root->data);
    }
}

int main()
{
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

    printf("Preorder Traversal: ");
    preOrderTraversal(root);
    printf("\n");

    printf("Inorder Traversal: ");
    InOrderTraversal(root);
    printf("\n");

    printf("Postorder Traversal: ");
    PostOrderTraversal(root);
    printf("\n");
    

    return 0;

}