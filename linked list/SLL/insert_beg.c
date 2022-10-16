#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
// typedef struct node nodeType;
struct node *newNode, *head, *temp;
void insert_beg()
{
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter the data you want to insert at beginning");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
        head = newNode;
        head->next = NULL;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}
void display()
{
    do
    {
        temp = head;
        printf(temp->data,"%d is inserted",temp->data);
        temp = temp->next;
    } while (temp->next != NULL);
}
int main()
{
    int choice;
    do
    {
        printf("Enter 0 if you want to insert more");
        scanf("%d", &choice);
        print("Enter the data you want to insert");
        scanf("%d", &newNode->data);
        insert_beg();
    } while (choice != 0);
}