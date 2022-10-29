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
int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}
struct node *search(struct node *root, int key)
{
    if (root == NULL || key == root->data)
    {
        return root;
    }
    else if (key < root->data)
    {
        return search(root->left, key);
    }
    else
    {
        return search(root->right, key);
    }
}
int main()
{
    struct node *n = createNode(2);
    struct node *n1 = createNode(1);
    struct node *n2 = createNode(3);
    struct node *n3 = createNode(0);
    struct node *n4 = createNode(12);
    struct node *n5 = createNode(4);
    n->left = n1;
    n->right = n2;
    n1->left = n3;

    n1->right = n4;
    n2->right = n5;
    printf("%d", isBST(n));
    printf("\n");
    struct node *s = search(n, 4);
    if (s != NULL)
    {
        printf("Element found %d", s->data);
    }
    else
    {
        printf("Element not found");
    }

    return 0;
}