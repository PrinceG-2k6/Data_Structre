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

    printf("\n\n\n Reverse of array is :\n");
    i=0;
    j=n-1;
    int t;
    while(i<=j)
    {
        t=a[i];
        a[i]=a[j];
        a[j]=t;

    

        i++;
        j--;

        
    }

    for(i=0;i<n;i++)
    {
        printf("%d  ",a[i]);
    }

    return 0;

}