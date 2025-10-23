#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    vector<int> maxSubArray(vector<int>& nums) {
        long long maxSum = nums[0], currSum = nums[0];
        int start = 0, end = 0, tempStart = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (currSum + nums[i] < nums[i]) {
                currSum = nums[i];
                tempStart = i;
            } else {
                currSum += nums[i];
            }

            if (currSum > maxSum) {
                maxSum = currSum;
                start = tempStart;
                end = i;
            }
        }

        vector<int> subarray;
        for (int i = start; i <= end; i++) {
            subarray.push_back(nums[i]);
        }
        return subarray;
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
        vector<int> nums_result;
        for(int i = 0; i < n; i++){
            scanf("%d", &nums[i]);
        }

        nums_result = sol.maxSubArray(nums);
        n = nums_result.size();
        for(int i = 0; i < n; i++){
            printf("%d ",nums_result[i]);
        }

        t--;
    }

    return 0;
}