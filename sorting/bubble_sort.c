#include <stdio.h>
#include <stdlib.h>
#define max 5
void bubble_sort(int *arr);
void insertion_sort(int *arr);
void selection_sort(int *arr);
void quick_sort(int arr[], int l, int r);
void merge_sort(int arr[], int l, int r);
void merge(int arr[], int l, int mid, int r);
int partition(int arr[], int l, int r);
void display(int *arr);
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int arr[max] = {4, 2, 9, 8, 6};
    display(arr);
    printf("\nbubble_sort:  ");
    bubble_sort(arr);
    display(arr);
    printf("\nInsertion_sort:  ");
    insertion_sort(arr);
    display(arr);
    printf("\nselection_sort:  ");
    selection_sort(arr);
    display(arr);
    printf("\nQuick_sort:  ");
    quick_sort(arr, 0, max - 1);
    display(arr);
    printf("\nMerge_sort:  ");
    merge_sort(arr, 0, max - 1);
    display(arr);
    return 0;
}
void bubble_sort(int *arr)
{
    int i, j;
    int temp;
    for (i = 0; i < max - 1; i++)
    {
        for (j = 0; j < max - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void insertion_sort(int *arr)
{
    int temp, j;
    for (int i = 1; i < max; i++)
    {
        temp = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}
void selection_sort(int *arr)
{
    int min;
    for (int i = 0; i < max - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < max; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(&arr[i], &arr[min]);
        }
    }
}
void quick_sort(int arr[], int l, int r)
{
    int pivot;
    if (l < r)
    {
        pivot = partition(arr, l, r);
        quick_sort(arr, l, pivot - 1);
        quick_sort(arr, pivot + 1, r);
    }
}
int partition(int arr[], int l, int r)
{
    int pivot = arr[l];
    int start = l;
    int end = r;
    while (start < end)
    {
        while (arr[start] <= pivot)
            start++;
        while (arr[end] > pivot)
            end--;
        if (start < end)
            swap(arr[start], arr[end]);
    }
    swap(arr[l], arr[end]);
    return end;
}
void merge_sort(int arr[], int l, int r)
{
    int mid;
    if (l < r)
    {
        mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}
void merge(int arr[], int l, int mid, int r)
{
    int i = l;
    int j = mid + 1;
    int k = l;
    int b[max];
    while (i <= mid && j <= r)
    {
        if (arr[i] > arr[j])
        {
            b[k] = arr[j];
            j++;
        }
        else
        {
            b[k] = arr[i];
            i++;
        }
        k++;
    }
    if (i > mid)
    {
        while (j <= r)
        {

            b[k] = arr[j];
            j++;
            k++;
        }
    }
    else
    {
        while (i >= mid)
        {
            b[k] = arr[i];
            i++;
            k++;
        }
    }
}
void display(int *arr)
{
    for (int i = 0; i < max; i++)
    {
        printf("%d\t", arr[i]);
    }
}