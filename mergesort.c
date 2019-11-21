#include <stdio.h>
#include <stdlib.h>
int *mergesort(int *arr, int n)
{
    int temp[n];
    int i, j;
    int size = 1;
    int l1, l2, u1, u2;
    while (size < n)
    {
        l1 = 0;
        int k = 0;
        while ((l1 + size) < n)
        {
            l2 = l1 + size;
            u1 = l2 - 1;
            u2 = (l2 + size - 1) < n ? (l2 + size - 1) : n - 1;
            for (i = l1, j = l2; (i <= u1 && j <= u2); k++)
            {
                if (arr[i] > arr[j])
                {
                    temp[k] = arr[j++];
                }
                else
                {
                    temp[k] = arr[i++];
                }
            }
            while (i <= u1)
                temp[k++] = arr[i++];
            while (j <= u2)
                temp[k++] = arr[j++];

            l1 = u2 + 1;
        }
        for (i = u2; i < n; i++)
        {

            arr[k++] = temp[i];
        }
        size = size * 2;
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = temp[i];
        printf("%d ", arr[i]);
    }
    printf("\n");
    return arr;
}

int main()
{
    int i, n;
    printf("Enter the number of elements in array\n");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int *arr1;
    arr1 = mergesort(arr, n);
    printf("The sorted array is \n");
    for (i = 0; i < n; i++)
        printf("%d ", arr1[i]);
}