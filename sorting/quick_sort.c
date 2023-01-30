void quick_sort(int a[], int l, int r)
{
    int pivot;
    if (l < r)
    {
        pivot = partition(a, l, r);
        quick_sort(a, l, pivot - 1);
        quick_sort(a, pivot + 1, r);
    }
}
int partition(int a[], int l, int r)
{
    int start = l;
    int end = r;
    int pivot = a[l];
    int temp;
    while (start < end)
    {
        while (a[start] <= pivot)
            start++;
        while (a[end] > pivot)
            end--;
        if (start < end)
        {
            swap(a[start], a[end]);
        }
    }
    swap(a[l], a[end]);
    return end;
}