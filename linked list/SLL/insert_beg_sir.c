#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
typedef struct node TypeNode;
TypeNode *first, *last, *temp;
void insert_beg(int);
void insert_end(int);
void display();
int main()
{
    int item, choice;
    do
    {
        printf("\n");
        printf("1.  Enter data at the beginning\n");
        printf("2.   Enter data at the End\n");
        printf("3.   Display\n");
        printf("4.   Exit\n");
        printf("Enter choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item to be inserted\n");
            scanf("%d", &item);
            insert_beg(item);
            break;
        case 2:
            printf("Enter the data to be inserted\n");
            scanf("%d", &item);
            insert_end(item);
            break;
        case 3:
            display();
            break;
        default:
            printf("bye bye\n");
            break;
        }

    } while (choice != 4);
}

void insert_beg(int item)
{
    TypeNode *newNode;
    newNode = (TypeNode *)malloc(sizeof(TypeNode));
    newNode->data = item;
    if (first == NULL)
    {
        newNode->next = NULL;
        first = newNode;
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
    printf("%d element is inserted at the beginnning\n", newNode->data);
}
void insert_end(int item)
{

    TypeNode *newNode;
    newNode = (TypeNode *)malloc(sizeof(TypeNode));
    newNode->data = item;
    temp = first;

    newNode->next = NULL;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display()
{
    temp = first;

    if (first == NULL)
    {
        printf("The list is empty\n");
    }
    else
    {
        printf("The list is\n ");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}
