#include <stdio.h>
#define MAX 5
#define true 1
#define false 0
int ele;
struct Queue
{
    int front;
    int rear;
    int queue_arr[MAX];
};
typedef struct Queue newName;
int isFull(newName *n)
{
    return n->rear = MAX - 1 ? true : false;
}
int isEmpty(newName *n)
{
    return n->rear < n->front ? true : false;
}
int enqueue(newName *n, int ele)
{
    n->rear++;
    return n->queue_arr[n->rear] = ele;
}
int dequeue(newName *n)
{
    return n->queue_arr[n->front++];
}
int front_peek(newName *n)
{
    return n->queue_arr[n->front];
}
int rear_peek(newName *n)
{
    return n->queue_arr[n->rear];
}
int main()
{
    int choice;
    newName k;
    k.front = 0;
    k.rear = -1;
    printf("Choose the operation you want to perform\n");
    do
    {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. peek_rear\n");
        printf("4. peek_front\n");
        printf("5. Exit\n");
        printf("Enter the choice\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to insert to the queue\n");
            scanf("%d", &ele);
            printf("%d is inserted\n", enqueue(&k, ele));
            break;
        case 2:
            printf("%d is removed from the queue\n", dequeue(&k));
            break;
        case 3:
            printf("%d is in the rear of queue\n", rear_peek(&k));
            break;
        case 4:
            printf("%d is in the front of queue\n", front_peek(&k));
            break;
        case 5:
            printf("bye\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
