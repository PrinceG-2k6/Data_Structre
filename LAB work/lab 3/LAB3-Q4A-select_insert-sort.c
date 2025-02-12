#include <stdio.h>
int main()
{
    int i, j, k, n, min;
    int a[9] = {9, 6, 7, 2, 3, 7, 4, 6, 5};

    printf("Array is : \n");
    for (i = 0; i < 9; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\n\nChoose one number :\n1.....selection sort\n2.....insertion sort\n");
    scanf("%d", &n);
    if (n == 1)
    {
        for (i = 0; i < 8; i++)
        {
            min = i;
            for (j = i + 1; j < 9; j++)
            {
            if (a[j] < a[min])
            {
                min = j;
            }
            }
            if (min != i)
            {
            k = a[i];
            a[i] = a[min];
            a[min] = k;
            }
        }

        printf("Sorted array using selection sort is : \n");
        for (i = 0; i < 9; i++)
        {
            printf(" %d |", a[i]);
        }
        printf("\n");
    }
    if (n == 2)
    {
        for (i = 1; i < 9; i++)
        {
            k = a[i];
            j = i - 1;
            while (j >= 0 && a[j] > k)
            {
            a[j + 1] = a[j];
            j = j - 1;
            }
            a[j + 1] = k;
        }

        printf("Sorted array using insertion sort is : \n");
        for (i = 0; i < 9; i++)
        {
            printf(" %d |", a[i]);
        }
        printf("\n");
    }

    return 0;
}