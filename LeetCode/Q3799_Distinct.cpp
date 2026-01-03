#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        bitset<100001>vis;
        vis.reset();
        for(int i = n - 1; i >= 0; i--){
            if(!vis[nums[i]]) vis[nums[i]] = 1;
            else return (i + 3)/3;
        }
        return 0;
    }
};