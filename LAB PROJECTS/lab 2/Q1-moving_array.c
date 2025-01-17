#include <stdio.h>
#include <conio.h>
float avg(float a[],int m ,int n)
{
    int i,j,k;
    float sum=0,count=0;
    printf("\n\nEnter the number of which u want moving array : ");
    scanf("%d", &m);
    for (i = 0; i < n + m - 1; i++)
    {
        for (j = i - m + 1; j < i + 1; j++)
        {
            if (j >= 0 && j < n)
            {
                sum = sum + a[j];
                count++;
            }
        }

        float avg = sum / count;
        printf(" %.2f |", avg);
        sum = 0;
        count = 0;
    }
}
int main()
{
    int i, j, k, n, m;
    printf("Enter the number of elements in array  : ");
    scanf("%d", &n);
    float a[n];
    for (i = 0; i < n; i++)
    {
        scanf("%f", &a[i]);
    }

    puts("Your array is :");

    for (i = 0; i < n; i++)
    {
        printf("%.1f | ", a[i]);
    }
    avg(a,m,n);    

    return 0;
}