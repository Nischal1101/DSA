#include <stdio.h>
#define max 7
void binary_search(int *A, int l, int r, int key)
{

    int mid = (l + r) / 2;
    if (key == A[mid])
        printf("Element is found at index %d", mid);
    // return mid;
    else if (key < A[mid])
        return binary_search(A, l, mid - 1, key);
    else
        return binary_search(A, mid + 1, r, key);
}
int main()
{
    int A[] = {1, 2, 3, 4, 5, 6, 8};
    binary_search(A, 0, max - 1, 8);
}