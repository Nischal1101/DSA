#include <stdio.h>
void linear_search(int *A, int key);
int main()
{
    int A[] = {4, 56, 6, 2, 33, 5, 33, 9};
    int key;
    printf("Enter the key to be searched\n");
    scanf("%d", &key);
    linear_search(A, key);
}
void linear_search(int *A, int key)
{
    int flag = 0;
    for (int i = 0; i < 8; i++)
    {
        if (A[i] == key)
        {
            printf("Element is found at index %d\n", i);
            flag++;
        }
    }
    if (flag == 0)
    {
        printf("Element is not found\n");
    }
}