#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums;
    }
};

int main(){

    Solution sol;
    vector<int> nums = {3,6,9,1};
    nums = sol.sortArray(nums);
    return 0;
}