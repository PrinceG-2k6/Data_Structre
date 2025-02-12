#include <stdio.h>
int main()
{
    int i, j, k,c, n, m, sum = 0, avg = 0,multi;
    int a[7][7] = { 1,3,5,2,5,3,5,
                    7,5,4,8,6,6,4,
                    9,5,7,5,6,3,5,
                    7,8,5,6,4,9,5,
                    1,2,5,4,8,3,5,
                    8,3,4,6,3,7,9,
                    5,6,8,4,9,5,7
                };
int d[7][7];
    printf("Matrix:\n");
    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("%d\t", a[i][j]);
            d[i][j]=a[i][j];
        }
        printf("\n");
    }

    printf("'ON APPLYING CROSS CO-RELATION FILTER ' \n\n");
    int b[3][3] ={1,2,1,
                  2,4,2,
                  1,2,1};
    
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 5; j++)
        {
            sum = 0;
            for (k = 0; k < 3; k++)
            {
                for (c = 0; c < 3; c++)
                {
                    multi = a[i + k][j + c] * b[k][c];
                    sum = sum + multi;
                }
            }
            avg= sum/9;
            d[i+1][j+1] = avg;
        }
    }

    for (i = 0; i < 7; i++)
    {
        for (j = 0; j < 7; j++)
        {
            printf("%d\t", d[i][j]);
        }
        printf("\n");
    }

    return 0;
}