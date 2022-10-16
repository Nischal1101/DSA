#include <stdio.h>
int A[6] = {2, 5, 1, 9, 6, 4};
int bs(int key, int l, int r)
{
    int m;
    int flag = 0;
    m = (l + r) / 2;
    while (l < r)
    {
        if (A[m] == key)
        {
            flag = 1;
            printf("Element is found at index %d", m);
        }
        else if (A[m] > key)
        {
            r = m - 1;
        }
        else
            l = m + 1;
    }
    if (flag == 0)
    {
        printf("Search is unsuccessful");
    }
}
int main()
{
    bs(5,0,6);

    return 0;
}
