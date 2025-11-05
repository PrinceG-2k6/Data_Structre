#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findXSum(vector<int> &nums, int k, int x)
    {
        int i;
        int n = nums.size();
        vector<int>ans;
        for (i = 0; i <=n - k; i++)
        {
            int j = i;
            vector<int> sub(nums.begin() + i, nums.begin() + i + k);
            unordered_map<int, int> freq;
            for (int num : sub)
            {
                freq[num]++;
            }
            vector<pair<int, int>> items(freq.begin(), freq.end());
            sort(items.begin(), items.end(), [](auto &a, auto &b)
                 {
                if (a.second == b.second) return a.first > b.first;
                return a.second > b.second; });

            // for (auto &p : items)
            // {
            //     cout << p.first << " " << p.second << "\n";
            // }
            vector<int> result;
            for(j=0;j<items.size()&&j<x;j++){
                result.push_back(items[j].first);
            }

            int xSum =0;
            for(int x: result){
                xSum+=count(sub.begin(),sub.end(),x)*x;
            }
            
            ans.push_back(xSum);
        }

        return ans;
    }
};

int main()
{
    Solution sol;
    vector<int> nums = {3,8,7,8,7,5};
    int k = 2;
    int x = 2;
    vector<int> ans = sol.findXSum(nums, k, x);
    for (int x : ans)
    {   
        cout << x << " ";
    }
    
}