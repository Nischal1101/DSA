#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define true 1
#define false 0
struct info
{
    int roll;
    char name[20];
};
struct SLL
{
    struct info *std;
    struct SLL *next;
};
// typedef struct info student;
typedef struct SLL typeNode;
typeNode *first, *last, *pointer, *newNode, *temp;
int isEmpty()
{
    first = newNode;
    last = newNode;
}

int create_node(int roll, char *name)
{
    newNode = (typeNode *)malloc(sizeof(typeNode));
    newNode->std->roll = roll;
    // newNode->std->name[20] = *name;
    strcpy(newNode->std->name[20], name);
    newNode->next = NULL;
}
int insert_beg(int roll, char *name)
{
    if (first == NULL)
    {
        isEmpty();
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
    printf("%d and %s are inserted at the beginning\n", roll, name);
}
int insert_end()
{
    if (first == NULL)
    {
        isEmpty();
    }
    else
    {

        last->next = newNode;
        last = newNode;
    }
}
int insert_spec(int roll, int pos)
{
    int i = 1;
    temp = first;
    if (isEmpty() == true)
    {
        first = newNode;
        last = newNode;
    }
    while (i < pos - 1)
    {
        temp = temp->next;
        i++;
    }
}
int del_end();
int del_beg();
int del_spec();
void display()
{
    temp = first;
    if (isEmpty() == true)
        printf("The linked list is empty\n");
    else

        while (temp != NULL)
        {
            printf("%d\t", temp->std->roll);
            temp = temp->next;
        }
}

int main()
{
    int roll, choice, pos;
    char name[20];
    do
    {
        printf("\nEnter the choices below\n");
        printf("1. Insertion at beginning\n");
        printf("2. Insertion at end\n");
        printf("3. Insertion at specific position\n");
        printf("4. Deletion at beginning\n");
        printf("5. Deletion at end\n");
        printf("6. Deletion at specific position\n");
        printf("7. Display\n");
        printf("8. Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the roll number\n");
            scanf("%d", &roll);
            printf("Enter the name\n");
            scanf("%d", &name);
            create_node(roll, name);
            insert_beg(roll, name);
            break;
        case 2:
            printf("Enter the roll number to be inserted at the end\n");
            scanf("%d", &roll);
            printf("Enter the name\n");
            scanf("%d", &name);
            create_node(roll, name);
            insert_end(roll);
            break;
        case 3:
            printf("Enter the rollment to be inserted at the specific location\n");
            scanf("%d", &roll);
            printf("Enter the name\n");
            scanf("%d", &name);

            printf("Enter the position of the rollment\n");
            scanf("%d", &pos);
            create_node(roll, name);
            insert_spec(roll, pos);
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            display();
            break;
        case 8:
            printf("Bye bye\n");
            break;
        }
    } while (choice != 8);
}