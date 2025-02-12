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
    return 0;
}