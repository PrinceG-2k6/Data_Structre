#include <stdio.h>
#include<stdlib.h>
int longestSubarraySum(int* arr, int n, int k) {
    int sum, max = 0;
    for (int i = 0; i < n; i++) {
        sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == k) {
                if (j - i + 1 > max)
                    max = j - i + 1;
            }
        }
    }
    return max;
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
        
        printf("Enter Size of array of case no. %d \n",i+1);
        scanf("%d",&n);
        
        printf("Enter Sum to Find : ");
        scanf("%d",&k);
        int a[n];
        for(int j=0;j<n;j++){
            scanf("%d",&a[j]);
        }

        printf("%d\n",longestSubarraySum(a,n,k));
    }
    
    

    return 0;
}