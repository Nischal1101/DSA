#include <stdio.h>
#include <stdlib.h>

struct CLL
{
    int info;
    struct CLL *next;
};
typedef struct CLL NodeType;
NodeType *first, *last, *temp;

NodeType *CreateNode(int element)
{
    NodeType *NewNode;
    NewNode = (NodeType *)malloc(sizeof(NodeType));
    if (NewNode != NULL)
    {
        NewNode->info = element;
        NewNode->next = NULL;
    }
    return NewNode;
}

void InsertAtBeg(int element)
{
    NodeType *NewNode;
    NewNode = CreateNode(element);
    if (first == NULL)
    {
        first = last = NewNode;
        last->next = first;
    }
    else
    {
        NewNode->next = first;
        first = NewNode;
        last->next = first;
    }
}

void InsertAtEnd(int element)
{
    NodeType *NewNode;
    NewNode = CreateNode(element);
    if (first == NULL)
    {
        first = last = NewNode;
        last->next = first;
    }
    else
    {
        last->next = NewNode;
        last = NewNode;
        last->next = first;
    }
}

void DeleteAtBeg()
{
    if (first == NULL)
        printf("Void Deletion. List is Empty.\n");
    else if (first == last)
        first = last = NULL;
    else
    {
        temp = first;
        first = first->next;
        last->next = first;
        free(temp);
    }
}

void DeleteAtEnd()
{
    if (first == NULL)
        printf("Void Deletion. List is Empty.\n");
    else if (first == last)
        first = last = NULL;
    else
    {
        temp = first;
        while (temp->next != last)
            temp = temp->next;
        free(last);
        last = temp;
        last->next = first;
    }
}

void traversal()
{
    temp = first;
    if (first == NULL)
        printf("List is Empty.\n");
    else
    {
        do
        {
            printf("%d\t", temp->info);
            temp = temp->next;
        } while (temp != first);
        printf("\n");
    }
}

int main()
{
    first = last = NULL;
    int element, choice;
    do
    {
        printf("1.INSERTION AT BEGINNING\n");
        printf("2.INSERTION AT THE END\n");
        printf("3.DELETION FROM BEGINNING\n");
        printf("4.DELETION FROM THE END\n");
        printf("5.TRAVERSAL\n");
        printf("6.EXIT\n");
        printf("Choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element you want to insert: ");
            scanf("%d", &element);
            InsertAtBeg(element);
            break;

        case 2:
            printf("Enter the element you want to insert: ");
            scanf("%d", &element);
            InsertAtEnd(element);
            break;

        case 3:
            DeleteAtBeg();
            break;

        case 4:
            DeleteAtEnd();
            break;

        case 5:
            traversal();
            break;

        case 6:
            printf("BYE\n");
        }
    } while (choice != 6);
    return 0;
}