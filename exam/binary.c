#include <stdio.h>
int A[] = {1, 2, 5, 8, 43};
int binary_search(int l, int r, int key)
{
    int mid = (l + r) / 2;
    if (key < A[mid])
        return binary_search(l, mid - 1, key);
    else if (key > A[mid])
        return binary_search(mid + 1, r, key);
    else if (key == A[mid])
        return key;
    else
        return 0;
}
int main()
{
    int key, result;
    printf("Enter the key to be found\n");
    scanf("%d", &key);
    result = binary_search(0, 4, key);
    if (result == 0)
        printf("Element not found\n");
    else
        printf("%d is found\t", result);
}