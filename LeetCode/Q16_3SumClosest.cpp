#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int l = i + 1, r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];

                if (abs(sum - target) < abs(closest - target))
                    closest = sum;

                if (sum < target)
                    l++;
                else if (sum > target)
                    r--;
                else {
                    return target;
                }
            }
        }
        return closest;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,2,1,-4};
    cout<<sol.threeSumClosest(nums,1)<<endl;
}
