#include <stdio.h>
#include <stdlib.h>
struct SLL
{
    int data;
    struct SLL *next;
};
typedef struct SLL nodeType;
nodeType *first, *last;
void insert_beg(int element)
{
    nodeType *newNode;
    newNode = (nodeType *)malloc(sizeof(nodeType));
    if (first == NULL)
    {
        first = newNode;
        last = newNode;
        newNode->next = NULL;
    }
    else
    {
        newNode->next = first;
        first = newNode;
    }
    printf("%d is inserted at the beginning\n", element);
}
void display()
{
    while(last!=NULL);
    {
        
    }
}
int main()
{
    int element;
    printf("Enter the element to be inserted at the beginning\n");
    scanf("%d", &element);
    first = 0, last = 0;
    insert_beg(element);
}