#include<stdio.h>
int main()
{
    int a[]={1,2,1,2,2,3,3,4,5,6,6};
    int i,j,k,c1=0,c2=0;

    for(i=0;i<11;i++)
    {
        for(j=0;j<11;j++)
        {
            if(a[i]==a[j])
            c1++;
        }

        for(j=i;j<11;j++)
        {
            if(a[i]==a[j])
            c2++;
        }

        if(c1==c2)
        {
            printf(" Frequncy of -->  %d == %d\n",a[i], c2);
        }
        c1=0;
        c2=0;
    }

    return 0;
}