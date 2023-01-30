#include <stdio.h>
#include <malloc.h>
struct BST
{
    int data;
    struct BST *lefty;
    struct BST *right;
};
typedef struct BST nodeType;
nodeType *root;
nodeType *createNode(int value);
nodeType *insert(nodeType *root, int value);
nodeType *deleteNode(nodeType *root, int value);
nodeType *minimum(nodeType *root);
nodeType *search(nodeType *root, int value);
void Inorder(nodeType *root);

int main()
{
    int choice, value;
    root = NULL;
    do
    {
        printf("\n1.Insert\n2.delete\n3.Search\n4.Inorder traversal\n5.Exit\n");
        printf("Enter choice: \n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the value to be inserted\n");
            scanf("%d", &value);
            root = insert(root, value);
            printf("Success\n");
            break;
        case 2:
            printf("Enter the value to be deleted\n");
            scanf("%d", &value);
            root = deleteNode(root, value);
            printf("Success\n");
            break;
        case 3:
            printf("Enter the value to search in BST\n");
            scanf("%d", &value);
            nodeType *n = NULL;
            n = search(root, value);
            if (n != NULL)
            {
                printf("%d is found\n", n->data);
            }
            else
            {
                printf("Element is not found\n");
            }
            break;
        case 4:
            Inorder(root);
            break;
        case 5:
            printf("Bye bye\n");
            break;
        }

    } while (choice != 5);
    return 0;
}
nodeType *createNode(int value)
{
    nodeType *newNode;
    newNode = (nodeType *)malloc(sizeof(nodeType));
    newNode->data = value;
    newNode->lefty = newNode->right = NULL;
}
nodeType *insert(nodeType *root, int value)
{
    if (root == NULL)
        root = createNode(value);
    else if (root->data > value)
        root->lefty = insert(root->lefty, value);
    else if (root->data < value)
        root->right = insert(root->right, value);
    else
        printf("Element already present,can't insert\n");
    return root;
}
nodeType *minimum(nodeType *root)
{
    while (root->lefty != NULL)
        root = root->lefty;
    return root;
}

nodeType *deleteNode(nodeType *root, int value)
{
    if (root == NULL)
        return root;
    else if (root->data > value)
        root->lefty = deleteNode(root->lefty, value);
    else if (root->data < value)
        root->right = deleteNode(root->right, value);
    else
    {
        if (root->lefty == NULL && root->right == NULL)
        {
            free(root);
            root = NULL;
        }
        else if (root->lefty == NULL)
        {
            nodeType *temp;
            temp = root;
            root = root->right;
            free(temp);
        }
        else if (root->right == NULL)
        {
            nodeType *temp;
            temp = root;
            root = root->lefty;
            free(temp);
        }
        else
        {
            nodeType *temp = minimum(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}
void Inorder(nodeType *root)
{
    if (root != NULL)
    {

        Inorder(root->lefty);
        printf(" %d ", root->data);
        Inorder(root->right);
    }
}
nodeType *search(nodeType *root, int value)
{
    if (root == NULL)
        return NULL;
    else if (root->data == value)
        return root;
    else if (root->data > value)
        return search(root->lefty, value);
    else
        return search(root->right, value);
}