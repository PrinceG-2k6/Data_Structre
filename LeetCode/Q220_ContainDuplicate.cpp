#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        for(int i=0;i<nums.size()-indexDiff;i++){
            if(abs(nums[i]-nums[i+indexDiff])==valueDiff){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution sol;
    vector<int> nums={1,5,9,1,5,9};
    cout<<sol.containsNearbyAlmostDuplicate(nums,2,3);
}