#include <stdio.h>
#define true 1
#define false 0
#define MAX 5
int TOP = -1;
int Data[MAX];
int isFULL()
{
    // using ternary operator
    return TOP == MAX - 1 ? true : false;
}
int isEmpty()
{

    return TOP == -1 ? true : false;
}

void push(element)
{
    if (isFULL() == true)
    {
        printf("Stack overflow, can't push items.\n");
    }
    else
    {
        TOP++;
        Data[TOP] = element;
        printf("%d is pushed\n", element);
    }
}
void pop()
{
    if (isEmpty() == true)
    {
        printf("Stack underflow, can't pop items.\n");
    }
    else
    {
        int element = Data[TOP];
        TOP--;
        printf("%d is popped\n", element);
    }
}
void peek()
{
    if (isEmpty() == true)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int element = Data[TOP];
        printf("%d is is the top of stack\n", element);
    }
}
int main()
{
    int element;
    int choice;
    do
    {
        printf("\n1.POP\n");
        printf("2.Push\n");
        printf("3.Peek\n");
        printf("4.Exit\n");
        printf("\nChoose the operation you want to perform\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            pop();
            break;
        case 2:
            printf("Enter the element to push\n");
            scanf("%d", &element);
            push(element);
            break;
        case 3:
            peek();
            break;
        default:
            printf("Achha chalta hu!\n");
            break;
        }
    } while (choice != 4);
    return 0;
}






