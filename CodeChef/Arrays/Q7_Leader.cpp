#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findLeaders(vector<int>& nums) {
        int n = nums.size();
        vector<int> leaders;
        int MaxFromRight = nums[n-1];

        leaders.push_back(MaxFromRight);

        for(int i = n-2;i>=0;i--){
            if(nums[i]>MaxFromRight){
                MaxFromRight = nums[i];
                leaders.push_back(MaxFromRight);
            }
        }
        reverse(leaders.begin(),leaders.end());
        return leaders;
    }
};

int main() {
    Solution sol;
    
    // Test cases
    vector<int> nums1 = {16, 17, 4, 3, 5, 2};
    vector<int> nums2 = {1, 2, 3, 4, 5};
    
    // Test case 1
    cout << "Input array 1: ";
    for(int num : nums1) cout << num << " ";
    cout << "\nLeaders: ";
    vector<int> result1 = sol.findLeaders(nums1);
    for(int leader : result1) cout << leader << " ";
    
    // Test case 2
    cout << "\n\nInput array 2: ";
    for(int num : nums2) cout << num << " ";
    cout << "\nLeaders: ";
    vector<int> result2 = sol.findLeaders(nums2);
    for(int leader : result2) cout << leader << " ";
    
    return 0;
}