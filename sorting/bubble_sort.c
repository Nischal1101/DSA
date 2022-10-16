#include <stdio.h>
#include <stdlib.h>
#define MAX 5
int arr[MAX];

void display()
{
    for (int i = 0; i < MAX; i++)
    {
        printf("%d\t", arr[i]);
    }
}
void get_arr()
{
    for (int i = 0; i < MAX; i++)
    {
        arr[i] = rand();
        display();
    }
}
void bubble_sort()
{
    int i, j, temp;
    for (int i = 0; i < MAX - 1; i++)
    {
        for (int j = 0; j < MAX - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
int main()
{
    get_arr();
}