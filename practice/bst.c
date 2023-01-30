// Write a c program to implement binary search tree and perform searching and insertion operations.
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node nodeType;
nodeType *createNode(int data)
{
    nodeType *newNode = (nodeType *)malloc(sizeof(nodeType));
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->data = data;
}

nodeType *insert(nodeType *root, int value)
{
    if (root == NULL)
    {
        root = createNode(value);
    }
    else if (root->data > value)
    {
        root->left = insert(root->left, value);
    }
    else
    {
        root->right = insert(root->right, value);
    }
    return root;
}
void inorder(nodeType *root)
{
    if (root != NULL)
    {

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{
    int element, choice;
    nodeType *root = NULL;
    do
    {
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted\n");
            scanf("%d", &element);
            root = insert(root, element);
            printf("Success\n");
            break;
        case 2:
            inorder(root);
            break;
        case 3:
            printf("Bye bye\n");
            break;
        }
    } while (choice != 3);

    return 0;
}
