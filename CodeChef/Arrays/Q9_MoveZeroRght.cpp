#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nonZeroIndex = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                swap(nums[nonZeroIndex], nums[i]);
                nonZeroIndex++;
            }
        }
    }
};

int main() {
    
    Solution sol;
    int t,n;
    cout<<"Enter The Number Of test Case : "<<endl;
    cin>>t;
    while(t>0){

        cout<<"\nEnter The Size : "<<endl;
        cin>>n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }

        sol.moveZeroes(nums);

        for(int i = 0; i < n; i++){
            printf("%d ",nums[i]);
        }

        t--;
    }

    return 0;
}
