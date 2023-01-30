#include <stdio.h>
#include <stdlib.h>
struct BST
{
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST nodeType;
nodeType *root;
nodeType *createNode(int key)
{
    nodeType *newNode = NULL;
    newNode = (nodeType *)malloc(sizeof(nodeType));
    newNode->data = key;
    newNode->left = newNode->right = NULL;
    return newNode;
}
nodeType *insert(nodeType *root, int key)
{
    if (root == NULL)
        root = createNode(key);
    else if (key < root->data)
        root->left = insert(root->left, key);
    else
        root->right = insert(root->right, key);
    return root;
}
void inorder(nodeType *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}
int main()
{
    int choice, key;
    root = NULL;
    do
    {
        printf("1.Insert\n 2.Treverse\n 3.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the key to be inserted\n");
            scanf("%d", &key);
            root = insert(root, key);
            printf("SUCCESS\n");
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