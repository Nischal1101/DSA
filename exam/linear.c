#include <stdio.h>
int A[] = {5, 2, 3, 8, 1};
int linearSearch(int key)
{
    int flag = 0;
    for (int i = 0; i < 5; i++)
    {
        if (A[i] == key)
        {
            flag++;
        }
    }
    return flag;
}
int main()
{
    int key;
    int flag;
    printf("Enter the key\n");
    scanf("%d", &key);
    flag = linearSearch(key);
    if (flag == 0)
        printf("Element not found\n");
    else
        printf("%d element is found\t", key);
    return 0;
}