#include <stdio.h>
#define Max 6
int A[Max] = {1, 4, 2, 9, 0, 6};
void insertionSort();
void bubbleSort();
void selectionSort();
void mergeSort();
void quickSort();
void swap(int *B, int *C)
{
    int temp;
    temp = *B;
    *B = *C;
    *C = temp;
}
void display()
{
    for (int i = 0; i < Max; i++)
    {
        printf("%d\t", A[i]);
    }
}

int main()
{
    printf("The unsorted array is \n");
    display();
    selectionSort();
    printf("The sorted array is n");
    display();
}
void bubbleSort()
{
    for (int i = 0; i < Max; i++)
    {

        for (int j = 0; j < Max - i - 1; j++)
        {
            if (A[j] > A[j + 1])
                swap(&A[j], &A[j + 1]);
        }
    }
}
void selectionSort()
{
    int min, i;
    for (i = 0; i < Max - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < Max; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        if (min != i)
            swap(&A[i], &A[min]);
    }
}
void insertionSort()
{
    
}
