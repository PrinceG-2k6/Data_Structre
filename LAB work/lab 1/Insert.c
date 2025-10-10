#include <stdio.h>
int main()
{
    int n,m,i,j,k,x,y,z;
    printf("ENTER THE SIZE OF ARRAY\n");
    scanf("%d",&n);
    void printArray(int *a, int n){
        for(int i=0;i<n;i++){
            printf("%d  ",a[i]);
        }
       
    }
    int a[n];
    printf("\n\nENTER THE ELEMENTS OF ARRAY\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }

    printf("\n The array is :");
    printArray (a,n);
    int c[n+1];
    printf("\n Enter the element u want to insert at beginning  : ");
    scanf("%d",&x);
    c[0]=x;
    for(i=0;i<n;i++)
    {
        c[i+1]=a[i];
    }

    printArray (a,n+1);

    printf("\n Enter the element u want to insert at end  : ");
    scanf("%d",&x);
    c[n]=x;
    for(i=0;i<n;i++)
    {
        c[i]=a[i];
    }

    for(i=0;i<n+1;i++)
    {
        printf("%d  ",c[i]);
    }

    printf("\n Enter the element u want to insert at specific index : ");
    scanf("%d",&x);

    printf("\n Enter the index : ");
    scanf("%d",&m);

    
    for(i=0;i<n;i++)
    {   
        if(i==m)
        {
            c[i]=x;
            for(i=m+1;i<n+1;i++)
            {
                c[i]=a[i-1];
            }

            break;
        }
        else
        c[i]=a[i];
    }

    for(i=0;i<n+1;i++)
    {
        printf("%d  ",c[i]);
    }

    return 0;

}
