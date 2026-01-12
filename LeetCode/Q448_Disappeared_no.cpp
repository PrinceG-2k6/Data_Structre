#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 7 3 2 4 8 2 3 1
        // 3 3 2 4 8 2 7 1
        // 2 3 3 4 8 2 7 1
        // 3 2 3 4 8 2 7 1
        // 1 2 3 4 3 2 7 8

        for(int i =0;i<nums.size();i++){
            while(nums[i]!=i+1 && nums[nums[i]-1]!=nums[i]){
                int t = nums[nums[i]-1];
                nums[nums[i]-1] = nums[i];
                nums[i] = t;
            }
        }
        vector<int> ans;
        int count =1;
        for(int i =0;i<nums.size();i++){
            if(nums[i]!=count){
                ans.push_back(count);
            }
            count++;
        }
        return ans;
    }
};

int main (){
    Solution sol;
    vector<vector<int>> points = {{1,1},{3,4},{-1,0}};
    cout<<sol.minTimeToVisitAllPoints(points);
}