#include <stdio.h>
int main()
{
    int i, j, k, c, n, m, sum = 0, avg = 0;
    int a[7][7] = { 1,3,5,2,5,3,5,
                    7,5,4,8,6,6,4,
                    9,5,7,5,6,3,5,
                    7,8,5,6,4,9,5,
                    1,2,5,4,8,3,5,
                    8,3,4,6,3,7,9,
                    5,6,8,4,9,5,7,
                };
    int b[7][7];

    printf("Matrix:\n");
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("%d ", a[i][j]);
            b[i][j]=a[i][j];
        }
        printf("\n");
    }

    printf("'ON APPLYING BOX FILTER ' \n\n");
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            sum = 0;
            for (k = 0; k < 3; k++)
            {
                for (c = 0; c < 3; c++)
                {
                    sum = sum + a[i + k][j + c];
                }
            }
            avg= sum/9;
            b[i+1][j+1] = avg;
        }
    }

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("%d ", b[i][j]);
        }
        printf("\n");
    }

    return 0;
}