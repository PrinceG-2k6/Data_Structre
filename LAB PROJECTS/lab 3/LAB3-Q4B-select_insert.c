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

    printf("\n\nWhich position sort u want :\n1.....Odd\n2.....Even\n");
    scanf("%d", &n);
    if (n == 1)
    {
        for (i = 0; i < 8; i+=2)
        {
            min = i;
            for (j = i + 2; j < 9; j+=2)
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

        printf("Sorted array at odd position is : \n");
        for (i = 0; i < 9; i++)
        {
            printf(" %d |", a[i]);
        }
        printf("\n");
    }
    if (n == 2)
    {
        for (i = 1; i < 8; i+=2)
        {
            min = i;
            for (j = i + 2; j < 9; j+=2)
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

        printf("Sorted array using Even position is : \n");
        for (i = 0; i < 9; i++)
        {
            printf(" %d |", a[i]);
        }
        printf("\n");
    }

    return 0;
}