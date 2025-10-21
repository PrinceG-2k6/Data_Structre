#include <stdio.h>
#include<stdlib.h>

void reverse(int nums[], int start, int end) {
    while (start < end) {
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
    }
}

void rotate(int* nums , int n, int k){
    if (n == 0) return; 
    k = k % n;         
    

    reverse(nums, 0, n - 1);
    reverse(nums, 0, k - 1);
    reverse(nums, k, n - 1);
    /*
    1 2 3 4 5

    5 4 3 2 1
    3 4 5 2 1
    3 4 5 1 2

    3 4 5 1 2
    */
}

void printArray(int a[],int n){
    for(int i =0;i<n;i++){
        printf("%d ",a[i]);
    }
}

int main(){
    int a[]={1,2,3,4,5};
    int n = 5;
    printf("Enter The number to shift right");
    int k;
    scanf("%d",&k);
    rotate(a,n,k);

    printArray(a,n);

    return 0;
}