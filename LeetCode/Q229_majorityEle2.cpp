#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n =nums.size();
        vector<int> ans;
        unordered_map<int,int> freq;
        for(int num :nums){
            freq[num]++;
        }
        int x = n/3;
        for(auto &p:freq){
            if(p.second >x)ans.push_back(p.first);
        }
        return ans;
    }
};

int main(){
    Solution sol;
    vector<int> nums ={3,2,3};
    vector<int> ans = sol.majorityElement(nums);
    for(int x:ans){
        cout<<x<<" ";
    }
}