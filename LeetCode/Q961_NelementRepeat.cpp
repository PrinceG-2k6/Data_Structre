#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        for(int i=0;i<nums.size()-2;i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2]){
                return nums[i];
            }
        }
        

        return nums[nums.size()-1];
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {2,1,2,5,3,2};
    cout<<sol.repeatedNTimes(nums);
    
}