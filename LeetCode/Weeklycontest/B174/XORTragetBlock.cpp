#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int alternatingXOR(vector<int> &nums, int target1, int target2)
    {
        int n = nums.size();

        int mod = 1e9 + 7;
        vector<int> dp1(150000, 0);
        vector<int> dp2(150000, 0);

        dp2[0] = 1;
        int current = 0;
        long answer1 = 0, answer2 = 0;

        for (int val : nums)
        {
            current ^= val;
            answer1 = dp2[current ^ target1];
            answer2 = dp1[current ^ target2];

            dp1[current] = (dp1[current] + answer1) % mod;
            dp2[current] = (dp2[current] + answer2) % mod;
        }

        vector<int> temp = nums;
        return (answer1 + answer2) % mod;
    }
};