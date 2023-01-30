#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0
#define MAX 10
struct CQ
{
    int size, front, rear, arr[MAX];
};
struct CQ *s;
int isFull(struct CQ *a)
{
    return s->size == MAX ? true : false;
}
int isEmpty(struct CQ *a)
{
    return s->size == 0 ? true : false;
}
void enqueue(struct CQ *a, int value);
int dequeue(struct CQ *a);
int main()
{
    struct CQ q = {0, 0, -1};
    int choice, data;
    do
    {
        printf("\n");
        printf("Select an option. \n");
        printf("1. ENQUEUE\n");
        printf("2. DEQUEUE\n");
        printf("3. EXIT.\n");
        printf(">");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            if (q.size == MAX)
                printf("QUEUUE IS FULL\n");
            else
            {
                printf("Enter data : ");
                scanf("%d", &data);
                enqueue(&q, data);
                printf("%d Enqueued\n", data);
            }
            break;
        case 2:
            if (q.size == 0)
                printf("QUEUE IS EMPTY\n");
            else
                printf("Removed element is : %d \n", dequeue(&q));
            break;
        case 3:
            printf("BYE\n");
            break;
        }
    } while (choice != 3);
    return 0;
}
