#include <stdio.h>
#define MAX 5
#define true 1
#define false 0
int choice = 0, top = -1;
int element;
int stack[MAX];
int isFull()
{
    return top = MAX - 1 ? true : false;
}
int isEmpty()
{
    return top = -1 ? true : false;
}
int push(int element)
{
    top++;
    stack[top] = element;
}
int pop()
{
    return stack[top--];
}
int peek()
{
    return stack[top];
}
int main()
{
    while (choice != 4)
    {
        printf("choose one from the following options");
        printf("\n1.push\n2.pop\n3.peek\n4.Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull() == false)
            {
                printf("stack overflow\n");
            }
            else
            {
                printf("Enter the value of element to be pushed\n");
                scanf("%d", &element);
                push(element);
                printf("%d element was pushed\n", element);
            }
            break;
        case 2:
            if (isEmpty() == true)
                printf("Stack underflow\n");
            else
            {
                printf("Element %d was poped\n ", pop());
                printf("element was popped\n");
            }
            break;
        case 3:
            if (isEmpty() == true)
                printf("Stack is empty\n");
            else
            {
                printf("%d is at the top of stack\n", peek());
            }
            break;
        case 4:
            printf("bye\n");
        default:
            printf("vag\n");
        }
    }
}