#include <stdio.h>
#define MAX 5
#define true 1
#define false 0
struct queue
{
    int front;
    int rear;
    int queue_arr[MAX];
};
int isFull(struct queue *s)
{
    return s->rear == MAX - 1 ? true : false;
}
int isEmpty(struct queue *s)
{
    return s->rear < s->front ? true : false;
}
void enqueue(struct queue *s, int element)
{
    if (isFull(s) == true)
        printf("Queue overflow, can't insert items\n");
    else
    {
        s->rear++;
        s->queue_arr[s->rear] = element;
        printf("%d is enqueued\n", element);
    }
}
void dequeue(struct queue *s)
{
    int element;
    if (isEmpty(s) == true)
        printf("Queue underflow, can't delete items\n");
    else
    {
        element = s->queue_arr[s->front];
        s->front++;
        printf("%d\n", s->front);
        printf("%d is dequeued\n", element);
    }
}
int checkFront(struct queue *s)
{
    if (isEmpty(s) == true)
        printf("Queue is empty\n");
    else
        printf("The rear element is %d", s->queue_arr[s->front]);
}
int checkRear(struct queue *s)
{
    if (isEmpty(s) == true)
        printf("Queue is empty\n");
    else
        printf("The rear element is %d", s->queue_arr[s->rear]);
}
void main()
{
    struct queue ss;
    int choice;
    int element;
    ss.front = 0;
    ss.rear = -1;
    do
    {
        printf("\n");
        printf("Select an option. \n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. CHECK FRONT\n");
        printf("4. CHECK REAR\n");
        printf("5. EXIT.\n");
        printf(">");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to enqueue\n");
            scanf("%d", &element);
            enqueue(&ss, element);
            break;
        case 2:
            dequeue(&ss);
            break;
        case 3:
            checkFront(&ss);
            break;
        case 4:
            checkRear(&ss);
            break;
        case 5:
            printf("Bye bye\n");
            break;
        }
    } while (choice != 5);
}