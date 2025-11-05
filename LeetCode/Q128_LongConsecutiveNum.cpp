#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;

        unordered_set<int> s(nums.begin(), nums.end()); // store all numbers in a hash set
        int longest = 0;

        for (int num : s) {
            // Start counting only if 'num' is the beginning of a sequence
            if (!s.count(num - 1)) {
                int current = num;
                int count = 1;

                // Count consecutive numbers
                while (s.count(current + 1)) {
                    current++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};


int main()
{
    Solution sol;
    vector<int> nums = {1, 0, 1, 2};
    /*
        3,2,9,1,8,7
        9,2,3,1,8,7

        -
        -

        1,2,3,9,8,7
    */
    cout << sol.longestConsecutive(nums);
}