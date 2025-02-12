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

    int t;
    printf("\nChoose no. \nSORT OF : \n1.. odd position \n2.. even position\n3.. all\n4.. odd number\n5.. even number\n");
    scanf("%d",&m);

    if(m==1)
    {
        printf("\n\n\n Sorting at odd position array is :\n");
        for(i=0;i<n;i=i+2)
        {
            for(j=i+2;j<n;j=j+2)
            {
                if(a[i]>a[j])
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }

        for(i=0;i<n;i++)
        {
            printf("%d  ",a[i]);
        }
    }
    
    if(m==2)
    {
        printf("\n\n\n Sorting at even position array is :\n");
        for(i=1;i<n;i=i+2)
        {
            for(j=i+2;j<n;j=j+2)
            {
                if(a[i]>a[j])
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }

        for(i=0;i<n;i++)
        {
            printf("%d  ",a[i]);
        }
    }

    if (m==3)
    {
        printf("\n\n\n Sorting at all position array is :\n");
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }

        for(i=0;i<n;i++)
        {
            printf("%d  ",a[i]);
        }        
    }

    if(m==4)
    {
        printf("\n\n\n Sorting of odd number is :\n");
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j] && a[i]%2!=0 && a[j]%2!=0)
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }

        for(i=0;i<n;i++)
        {
            printf("%d  ",a[i]);
        }
    }

    if(m==5)
    {
        printf("\n\n\n Sorting of even number is :\n");
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j] && a[i]%2==0 && a[j]%2==0)
                {
                    t=a[i];
                    a[i]=a[j];
                    a[j]=t;
                }
            }
        }

        for(i=0;i<n;i++)
        {
            printf("%d  ",a[i]);
        }
    }
    


    return 0;

}