#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k % nums.size();

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};

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
    vector<int> nums(a, a + n);
    Solution sol;
    sol.rotate(nums, k);
    
    for(int i = 0; i < n; i++) {
        a[i] = nums[i];
    }
    printArray(a,n);

    return 0;
}