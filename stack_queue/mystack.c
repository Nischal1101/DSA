#include <stdio.h>
#include <stdlib.h>
#define MAX 5
#define true 1
#define false 0
int ele;
struct stack
{
    int A[MAX];
    int top;
};
int isEmpty(struct stack *s)
{
    return s->top == -1 ? true : false;
}
int isFull(struct stack *s)
{
    return s->top == MAX - 1 ? true : false;
}
int push(struct stack *s, int ele)
{
    s->top++;
    return s->A[s->top] = ele;
}
int pop(struct stack *s)
{
    return s->A[s->top--];
}
int peek(struct stack *s)
{
    return s->A[s->top];
}
int main()
{
    struct stack k;
    k.top = -1;
    int choice;
    printf("Select the operation you want to perform\n");
    do
    {
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.peek\n");
        printf("4.Exit\n");
        printf("Enter your choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (isFull(&k) == true)
            {
                printf("Stack overflow\n");
            }
            else
            {

                printf("Enter the element you want to push\n");
                scanf("%d", &ele);
                printf("%d was pushed to the stack\n", push(&k, ele));
            }
            break;
        case 2:
            if (isEmpty(&k) == true)
            {
                printf("Stack underflow\n");
            }
            else
            {
                printf("%d is popped\n", pop(&k));
            }
            break;
        case 3:
            if (isEmpty(&k) == true)
                printf("Stack is empty\n");
            else
            {
                printf("%d is in the top of the stack\n", peek(&k));
            }
            break;
        case 4:
            printf("Bye\n");
            break;
        }
    } while (choice != 4);
}