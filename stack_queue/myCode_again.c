#include <stdio.h>
#define true 1
#define false 0
#define MAX 5
struct stack
{
    int Data[MAX];
    int TOP;
};
int isFULL(struct stack *s)
{
    // using ternary operator
    return s->TOP == MAX - 1 ? true : false;
}
int isEmpty(struct stack *s)
{

    return s->TOP == -1 ? true : false;
}

void push(struct stack *s, int element)
{
    if (isFULL(s) == true)
    {
        printf("Stack overflow, can't push items.\n");
    }
    else
    {
        s->TOP++;
        s->Data[s->TOP] = element;
        printf("%d is pushed\n", element);
    }
}
void pop(struct stack *s)
{
    if (isEmpty(s) == true)
    {
        printf("Stack underflow, can't pop items.\n");
    }
    else
    {
        int element = s->Data[s->TOP];
        s->TOP--;
        printf("%d is popped\n", element);
    }
}
void peek(struct stack *s)
{
    if (isEmpty(s) == true)
    {
        printf("Stack is empty\n");
    }
    else
    {
        int element = s->Data[s->TOP];
        printf("%d is is the top of stack\n", element);
    }
}
int main()
{
    int element;
    int choice;
    struct stack ss;
    ss.TOP = -1;

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
            pop(&ss);
            break;
        case 2:
            printf("Enter the element to push\n");
            scanf("%d", &element);
            push(&ss, element);
            break;
        case 3:
            peek(&ss);
            break;
        default:
            printf("Achha chalta hu!\n");
            break;
        }
    } while (choice != 4);
    return 0;
}
