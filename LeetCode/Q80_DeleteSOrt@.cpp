#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0 || nums.size() == 1) return nums.size();
        int start = 0;
        int fast = 0;
        int count = 0;
        while(start < nums.size() && count < 2 && nums[start] == nums[0]){
            count++;
            start++;
        }
        start--;
        while(fast < nums.size()){
            if (nums[start] != nums[fast]){
                int val = nums[fast];
                count = 0;
                while(fast < nums.size() && nums[fast] == val){
                    start++;
                    nums[start] = val;
                    count++;
                    if(count == 2) break;
                    fast++;
                }
            }
            else fast++;
        }

        return start+1;
    }
};
int main()
{
    Solution sol;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    cout << endl
         << sol.removeDuplicates(nums) << endl;
}