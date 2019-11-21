#include <stdio.h>
#include <stdlib.h>
#define n 4
void transitiveclosure(int arr[][n])
{
    int k, i, j;
    for (k = 0; k < n; k++)
    {
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                arr[i][j] = arr[i][j] || (arr[i][k] && arr[k][j]);
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
            printf("%d ", arr[i][j]);
        printf("\n");
    }
}
int main()
{
    int i, j;
    int arr[n][n];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Is there link from %c to %c \n Enter  1-Yes 0-No \n", 65 + i, 65 + j);
            scanf("%d", &arr[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    // for (i = 0; i < n; i++)
    // {
    //     int count = 0;
    //     for (j = 0; j < n; j++)
    //     {
    //         if (arr[i][j] == 1)
    //             count++;
    //     }
    //     printf("InCount from %c is  %d\n", 65 + i, count);
    // }
    // for (j = 0; j < n; j++)
    // {
    //     int count = 0;
    //     for (i = 0; i < n; i++)
    //     {
    //         if (arr[i][j] == 1)
    //             count++;
    //     }
    //     printf("DepthCount from %c is  %d\n", 65 + j, count);
    // }
    transitiveclosure(arr);
}