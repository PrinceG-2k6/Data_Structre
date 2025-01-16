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

    printf("\n\n left shift  :\n Enter the number of left shifts :\n");
    scanf("%d",&x);

    int d[n];
    for(i=0;i<n;i++)
    {
        j=i+x;
        if(j<n)
        {
            d[i]=a[j];
        }
        else{
            d[i]=0;
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d  ",d[i]);
    }

     printf("\n\n right shift  :\n Enter the number of right shifts :\n");
    scanf("%d",&x);
    for(i=0;i<n;i++)
    {
        j=i-x;
        if(j>=0)
        {
            d[i]=a[j];
        }
        else{
            d[i]=0;
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d  ",d[i]);
    }
    

    return 0;

}