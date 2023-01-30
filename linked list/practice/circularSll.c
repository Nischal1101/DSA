#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int info;
    struct SLL *next;
};
typedef struct SLL nodeType;
nodeType *first, *last;
nodeType *createNode(int item)
{
    nodeType *newNode = (nodeType *)malloc(sizeof(nodeType));
    newNode->info = item;
    newNode->next = newNode;
    return newNode;
}
void insertAtBeg(int item)
{
    nodeType *newNode = createNode(item);
    if (first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
    printf("%d has been inserted at beginning\n", item);
}
void insertAtEnd(int item)
{
    nodeType *newNode = createNode(item);
    if (first == NULL)
    {
        first = last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
}
void insertAtSpecific(int item)
{
    int i, position;
    printf("Enter the position\n");
    scanf("%d", &position);
    nodeType *newNode = createNode(item);
    if (first == NULL)
    {
        first = last = newNode;
        printf("%d is inserted at beginning\n", item);
    }
    else
    {
        nodeType *temp = first;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        printf("%d is inserted at position \n", item, position);
    }
}
void delAtBegin()
{
    if (first == NULL)
    {
        printf("The list is Empty\n");
    }
    else
    {
        nodeType *temp;
        temp = first;
        printf("%d is deleted from the beginning\n", temp->info);
        first = first->next;
        free(temp);
    }
}
void delAtEnd()
{
    nodeType *temp, *hold;
    if (first == NULL)
    {
        printf("The list is empty\n");
    }
    else if (first == last)
    {
        temp = first;
        first = NULL;
        last = NULL;
        printf("%d is deleted from the end\n", temp->info);
        free(temp);
    }
    else
    {
        temp = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        hold = temp->next;
        temp->next = NULL;
        printf("%d has been deleted from the end of list\n", hold->info);
        last = temp;
        free(hold);
    }
}
void delAtSpecific()
{
    int position;
    nodeType *temp, *hold;
    printf("Enter the position\n");
    scanf("%d", &position);
    if (first == NULL)
    {
        printf("The list is empty\n");
    }
    else if (first == last)
    {
        temp = first;
        first = NULL;
        last = NULL;
        printf("%d has been deleted from the end of list\n", temp->info);
        free(temp);
    }
    else
    {
        temp = first;
        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;
        }
        hold = temp->next;
        hold->next = temp->next;
        printf("%d has been deleted from position %d \n", hold->info, position);
        free(hold);
    }
}
void display()
{
    nodeType *temp;
    temp = first;
    if (first == NULL)
    {
        printf("Empty list\n");
    }
    else
    {

        while (temp->next != first)
        {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
        // printf("%d", temp->info);
        printf("NULL\n");
    }
}

int main()
{
    first = last = NULL;
    int choice, item;
    do
    {
        printf("\n");
        printf("Select a option. \n");
        printf("1. INSERT ELEMENT AT BEGINNING\n");
        printf("2. INSERT ELEMENT AT END\n");
        printf("3. INSERT ELEMENT AT SPECIFIED POSITION\n");
        printf("4. DELETE ELEMENT AT BEGINNING\n");
        printf("5. DELETE ELEMENT AT END\n");
        printf("6. DELETE ELEMENT AT SPECIFIED POSITION\n");
        printf("7. DISPLAY ELEMENTS\n");
        printf("8. EXIT\n");
        printf(">");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter item to be inserted : ");
            scanf("%d", &item);
            insertAtBeg(item);
            break;

        case 2:
            printf("Enter item to be inserted : ");
            scanf("%d", &item);
            insertAtEnd(item);
            break;

        case 3:
            printf("Enter item to be inserted : ");
            scanf("%d", &item);
            insertAtSpecific(item);
            break;

        case 4:
            delAtBegin();
            break;

        case 5:
            delAtEnd();
            break;

        case 6:
            delAtSpecific();
            break;

        case 7:
            display();
            break;
        }
    } while (choice != 8);
    return 0;
}
