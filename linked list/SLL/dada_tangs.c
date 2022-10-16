#include <stdio.h>
#include <stdlib.h>
struct linkedlist
{
    int data;
    struct linkedist *next;
};
struct linkedlist *first;
struct linkedlist *last;
struct linkedlist *NewNode;
struct linkedlist *AllocateSpace(int data)
{
    // struct linkedlist *NewNode;
    NewNode = (struct linkedlist *)malloc(sizeof(struct linkedlist));
    NewNode->data = data;
    NewNode->next = NULL;
}
void InsertAtBeg(int element)
{
    AllocateSpace(element);
    if (first == NULL)
    {
        first = NewNode;
        last = NewNode;
    }
    else
    {
        NewNode->next = first;
        first = NewNode;
    }
}
void InsertAtEnd(int element)
{
    AllocateSpace(element);
    if (first == NULL)
    {
        first = NewNode;
        last = NewNode;
    }
    else
    {
        last->next = NewNode;
        NewNode = last;
    }
}
void display()
{
    if (first == NULL)
    {
        printf("List is Empty");
    }
    else
    {
        struct linkedlist *temp;
        temp = first;
        do
        {
            printf("%d \n", temp->data);
            temp = temp->next;
        } while (temp->next != NULL);
    }
}
int main()
{
    InsertAtBeg(200);
    InsertAtBeg(400);
    InsertAtEnd(600);
    InsertAtEnd(800);
    display();
    return 0;
}