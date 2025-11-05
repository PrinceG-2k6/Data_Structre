#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return n + 1;
    }
};


int main(){
    Solution sol;
    vector<int> nums ={7,2,9,1,8,3};
    /*
        3,2,9,1,8,7
        9,2,3,1,8,7

        -
        -

        1,2,3,9,8,7
    */
    cout<<sol.firstMissingPositive(nums);
}