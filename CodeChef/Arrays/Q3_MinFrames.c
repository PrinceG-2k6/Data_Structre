#include <stdio.h>
#include<stdlib.h>

int Minimize(int * a,int n){
    if(n <= 0) return 0;
    int count = 1;
    for(int i = 1; i < n; i++){
        if(a[i] != a[i-1]){
            count++;
        }
    }
    return count;
}

void printArray(int a[],int n){
    for(int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    int t,n,k;
    printf("Enter No. of Test case : ");
    scanf("%d",&t);
    for(int i =0 ;i<t;i++){
        
        printf("Enter No. of Frames fro Test Case %d : ",i+1);
        scanf("%d",&n);
        
        int a[n];
        printf("Enter Frames %d \n",i+1);
        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);
        }

        printf("%d\n",Minimize(a,n));
    }
    
    

    return 0;
}