#include <stdio.h>
int main()
{
    int a[] = {1, 2, 1, 2, 2, 3, 3, 4, 5, 6, 6};
    int b[11];
    int i, j, k, c1 = 0, c2 = 0, c3;

    printf("The original array is :\n");
    for (i = 0; i < 11; i++)
    {
        printf("%d |", a[i]);
    }

    printf("\n\n");

    for (i = 0; i < 11; i++)
    {
        for (j = 0; j < 11; j++)
        {
            if (a[i] == a[j])
                c1++;
        }

        for (j = i; j < 11; j++)
        {
            if (a[i] == a[j])
                c2++;
        }

        if (c1 == c2)
        {
            printf(" Frequncy of -->  %d == %d\n", a[i], c2);
        }
        c1 = 0;
        c2 = 0;
    }

    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
        {
            if(a[i]==a[j])
            {
                c1++;
            }
        }
        b[i]=c1;
        c1=0;
    }

    for(i=0;i<11;i++)
    {
        for(j=i+1;j<11;j++)
        {
            if(b[i]<b[j])
            {
                c3=b[i];
                b[i]=b[j];
                b[j]=c3;

                c3=a[i];
                a[i]=a[j];
                a[j]=c3;
            }
        }
    }

    printf("\n\nThe sorted array is :\n");
    for (i = 0; i < 11; i++)
    {
        printf("%d |", a[i]);
    }

    return 0;
}