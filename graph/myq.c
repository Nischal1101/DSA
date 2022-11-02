#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX 10
struct queue
{
    int front;
    int rear;
    int arr[MAX];
};
struct queue *q;
void enqueue(struct queue *q, int value);
void dequeue(struct queue *q);
int isEmpty(struct queue *q);
int isFull(struct queue *q);
int checkFront(struct queue *q);
int checkRear(struct queue *q);
int main()
{
    struct queue p = {0, -1};
    int i = 1;
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    int a[7][7] =
        {
            {0, 1, 1, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 0},
            {1, 1, 0, 1, 1, 0, 0},
            {1, 0, 1, 0, 1, 0, 0},
            {0, 0, 1, 1, 0, 1, 1},
            {0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 1, 0, 0}
        };
    


// int choice, value;
// do
// {
//     printf("1.Enqueue\n2.Dequeue\n3.checkFront\n4.checkRear\n5.Exit\n");
//     printf("\nEnter the choice: ");
//     scanf("%d", &choice);
//     switch (choice)
//     {
//     case 1:
//         printf("Enter the value you want to insert\n");
//         scanf("%d", &value);
//         enqueue(&p, value);
//         break;
//     case 2:
//         dequeue(&p);
//         break;
//     case 3:
//         if (isEmpty(&p))
//             printf("Queue is empty\n");
//         else
//             printf("%d is in front of queue\n", checkFront(&p));
//         break;
//     case 4:
//         if (isEmpty(&p))
//             printf("Queue is empty\n");
//         else
//             printf("%d is in rear of queue\n", checkRear(&p));
//         break;
//     case 5:
//         printf("Bye bye\n");
//     }

// } while (choice != 5);
return 0;
}
int isEmpty(struct queue *q)
{
    return q->rear < q->front ? true : false;
}
int isFull(struct queue *q)
{
    return q->rear == MAX - 1 ? true : false;
}

void enqueue(struct queue *q, int value)
{
    q->rear++;
    q->arr[q->rear] = value;
    printf("%d is inserted in the queue\n", value);
}
void dequeue(struct queue *q)
{
    int ret = q->arr[q->front];
    q->front++;
    printf("%d has been removed from the queue\n", ret);
}
int checkFront(struct queue *q)
{
    return q->arr[q->front];
}
int checkRear(struct queue *q)
{
    return q->arr[q->rear];
}