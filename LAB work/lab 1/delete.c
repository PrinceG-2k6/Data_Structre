#include <stdio.h>
int main()
{
    int n,m,i,j,k,x,y,z;
    printf("ENTER THE SIZE OF ARRAY\n");
    scanf("%d",&n);
    
    int a[n];
    printf("\n\nENTER THE ELEMENTS OF ARRAY\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\n The array is :");
    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }

    printf("\n Delete at beginning of array : ");
    
    int b[n-1];
    for(i=1;i<n;i++)
    {   
        b[i-1] = a[i];
    }

    for(i=0;i<n-1;i++)
    {
         printf("%d  ",b[i]);
    }

    printf("\n Delete at end of array : ");
    for(i=0;i<n-1;i++)
    {   
        b[i] = a[i];
    }

    for(i=0;i<n-1;i++)
    {
         printf("%d  ",b[i]);
    }

    printf("\n Delete at specific element of array : ");
    printf("\nEnter the index u want to delete : ");
    scanf("%d",&m);


    for(i=0;i<n;i++)
    {
        if(i==m)
        {
            for(i=m+1;i<n;i++)
            {b[i-1]=a[i];}

            break;
        }
        else{
            b[i] = a[i];
        }
    }

    for(i=0;i<n-1;i++)
    {
         printf("%d  ",b[i]);
    }
    return 0;
}