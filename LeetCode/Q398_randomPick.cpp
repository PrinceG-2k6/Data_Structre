#include <bits/stdc++.h>
#include <random>
using namespace std;

class Solution {
    unordered_map<int,vector<int>> mpp;
public:
    Solution(vector<int>& nums) {
        
        int i=0;
        for(int num:nums){
            mpp[num].push_back(i);
            i++;
        }
    }
    
    int pick(int target) {
    vector<int>& indices = mpp[target];             // get vector of indices for this target
    int randomIndex = rand() % indices.size();      // random valid index
    return indices[randomIndex];                    // return one random position
}

};


int main() {
    vector<int> nums = {1, 2, 3, 3, 3};

    Solution sol(nums);

    cout<<sol.pick(3);
    cout<<sol.pick(1);
    cout<<sol.pick(3);


   
    return 0;
}