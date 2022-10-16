#include <stdio.h>
#include <stdlib.h>
void main()
{
    struct node
    {
        int data;
        struct node *next;
    };
    struct node *newNode, *head, *temp;
    head = 0;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data\n");
    scanf("%d", &newNode->data);
    newNode->next = 0;
    if (head == 0)
    {
        head = temp = newNode;
    }
    else
    {
        temp->next = newNode;
        // head->next = 0;
    }
}