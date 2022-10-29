#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}
void preOrder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(struct node *root)
{
    if (root != NULL)
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}
void postOrder(struct node *root)
{
    if (root != NULL)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}
int main()
{
    struct node *n = createNode(2);
    struct node *n1 = createNode(1);
    struct node *n2 = createNode(4);
    struct node *n3 = createNode(11);
    struct node *n4 = createNode(12);
    struct node *n5 = createNode(3);
    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = NULL;
    n2->right = n5;
    preOrder(n);
    printf("\n");
    postOrder(n);
    printf("\n");
    inOrder(n);
    printf("\n");
    return 0;
}