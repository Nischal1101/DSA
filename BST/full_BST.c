#include <stdio.h>
#include <malloc.h>
struct newNode
{
    int data;
    struct newNode *left;
    struct newNode *right;
};
struct newNode *createNode(int ddata)
{
    struct newNode *n;
    n = (struct newNode *)malloc(sizeof(struct newNode));
    n->data = ddata;
    n->left = NULL;
    n->right = NULL;
    return n;
}
int isBST(struct newNode *root)
{
    static struct newNode *prev = NULL;
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
struct newNode *search(struct newNode *root, int key)
{
    if (root == NULL || key == root->data)
        return root;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}
void insert(struct newNode *root, int key)
{
    struct newNode *prev = NULL;
    while(root!=NULL)
    {

    prev == root;

    if (key == root->data)
    {

        printf("Cannot insert %d, already in BST", key);
        return;
    }
    else if (key < root->data)
    {
    root=root-left;
    }
    else
    {
    root=root->rig
    }
    struct newNode *new = createNode(key);
    if (key < prev->data)
    {

        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
void insert(struct newNode *root, int key)
{
    struct newNode *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            printf("Cannot insert %d, already in BST", key);
            return;
        }
        else if (key < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    struct newNode *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}
int main()
{
    struct newNode *n = createNode(100);
    struct newNode *n1 = createNode(90);
    struct newNode *n2 = createNode(105);
    struct newNode *n3 = createNode(85);
    struct newNode *n4 = createNode(98);
    struct newNode *n5 = createNode(101);
    struct newNode *n6 = createNode(120);
    struct newNode *n7 = createNode(84);
    struct newNode *n8 = createNode(97);
    struct newNode *n9 = createNode(117);
    struct newNode *n10 = createNode(119);
    n->left = n1;
    n->right = n2;
    n1->left = n3;
    n1->right = n4;
    n2->left = n5;
    n2->right = n6;
    n3->left = n7;
    n4->left = n8;
    n6->left = n9;
    n9->right = n10;
    if (isBST(n) == 1)
    {
        printf("The binary tree is a binary search tree\n");
    }
    else
    {
        printf("The binary tree isn't a binary search tree\n");
    }
    struct newNode *i = search(n, 105);
    if (i != NULL)
        printf("%d is found\n", i->data);
    else
        printf("element is not found\n");
    insert(n, 89);
    printf("%d is inserted\n", n->left->left->right->data);
    return 0;
}