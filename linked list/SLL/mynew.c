#include <stdio.h>
#include <stdlib.h>
struct node
{
    int info;
    struct node *next;
};
typedef struct node nodeType;
nodeType *first, *last, *newNode;
nodeType *temp;
void insert_beg(int);
void insert_end(int);
void insert_specific(int);
void del_beg();
void deletatend();
void deleteatspecific();
void display();
int main()
{
    first = last = NULL;
    int item, choice;
    do
    {
        printf("\nChoose the options below\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at End\n");
        printf("3. Enter at specific position\n");
        printf("4. Delete at beginning\n");
        printf("5.Delete at end\n");
        printf("6.Delete at specific position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the number you want to insert at the beginning\n");
            scanf("%d", &item);
            insert_beg(item);
            break;
        case 2:
            printf("Enter the number you want to insert at the end\n");
            scanf("%d", &item);
            insert_end(item);
            break;
        case 3:
            printf("Enter the number you want to insert at the specific position\n");
            scanf("%d", &item);
            insert_specific(item);
            break;
        case 4:
            del_beg();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Bye bye\n");
            break;
        }
    } while (choice != 8);
}
void insert_beg(int item)
{
    newNode = (nodeType *)malloc(sizeof(nodeType));
    newNode->info = item;
    newNode->next = NULL;
    if (first == NULL)
    {
        first = newNode;
        last = newNode;
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
    printf("%d is inserted at the beginning\n", newNode->info);
}
void insert_end(int item)
{
    newNode = (nodeType *)malloc(sizeof(nodeType));
    newNode->info = item;
    newNode->next = NULL;
    if (first == NULL)

    {
        newNode->next = NULL;
        first = newNode;
        last = newNode;
    }
    else
    {
        last->next = newNode;
        last = newNode;
    }
    printf("%d inserted at end \n", newNode->info);
}
void insert_specific(int item)
{
    nodeType *temp;
    temp = first;
    int pos, i = 1;
    printf("Enter the position to enter a node\n");
    scanf("%d", &pos);
    newNode = (nodeType *)malloc(sizeof(nodeType));
    if (first == NULL)

    {
        newNode->next = NULL;
        first = newNode;
        last = newNode;
    }
    else
    {
        while (i < pos - 1)
        {
            temp = temp->next;
            i++;
        }
        temp->next = newNode->next;

        temp->next = newNode;
    }
}
void del_beg()
{
    if (first == NULL)
        printf("The list is empty");
    else
        temp = first;
    printf("%d is deleted from the list\n", temp->info);
    first = first->next;
    free(temp);
}

void deleteatend()
{
    nodeType *hold;
    if (first == NULL)
    {
        printf("List is Empty \n");
    }
    else if (first == last)
    {
        printf("Only one node\n");
        hold = first;
        first = NULL;
        last = NULL;
        printf("%d deleted \n", hold->info);
        free(hold);
    }
    else
    {
        temp = first;
        hold = first;
        while (temp->next != last)
        {
            temp = temp->next;
        }
        hold = temp->next;
        temp->next = NULL;
        last = temp;
        printf("%d deleted from end\n", hold->info);
        free(hold);
    }
}
void deleteatspecific()
{
    int pos, i;
    nodeType *hold;
    if (first == NULL)
    {
        printf("List is Empty \n");
    }
    else if (first == last)
    {
        printf("Only one node\n");
        hold = first;
        first = NULL;
        last = NULL;
        printf("%d deleted\n", hold->info);
        free(hold);
    }
    else
    {
        temp = first;
        printf("Enter Position : ");
        scanf("%d", &pos);
        for (i = 1; i < (pos - 1); i++)
        {
            temp = temp->next;
        }
        hold = temp->next;
        temp->next = hold->next;
        printf("%d deleted from position %d ", hold->info, pos);
        free(hold);
    }
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
        while (temp != NULL)
        {
            printf("%d\t", temp->info);
            temp = temp->next;
        }
    }
}