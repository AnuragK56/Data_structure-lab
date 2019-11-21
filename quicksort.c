#include <stdio.h>
void getdata(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
}
void quicksort(int a[], int lb, int ub)
{
    if (lb > ub)
        return;
    int down, up, temp, pivot;
    pivot = a[lb];
    down = lb;
    up = ub;
    while (down < up)
    {
        while (down <= ub && a[down] <= pivot)
            down++;
        while (a[up] > pivot && up >= lb)
            up--;
        if (down < up)
        {
            temp = a[down];
            a[down] = a[up];
            a[up] = temp;
        }
    }

    temp = a[up];
    a[up] = a[lb];
    a[lb] = temp;
    quicksort(a, lb, up - 1);
    quicksort(a, up + 1, ub);
}
void putdata(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    getdata(arr, n);
    quicksort(arr, 0, n - 1);
    putdata(arr, n);
    return 0;
}