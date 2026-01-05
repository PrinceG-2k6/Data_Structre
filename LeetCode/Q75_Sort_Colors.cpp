#include <bits/stdc++.h>
using namespace std;    

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int red = 0;
        int white = 0;
        int blue = nums.size() - 1;
        
        while (white <= blue) {
            if (nums[white] == 0) {
                swap(nums[white], nums[red]);
                red++;
                white++;
            } else if (nums[white] == 1) {
                white++;
            } else {
                swap(nums[white], nums[blue]);
                blue--;
            }
        }
    }
};

int main(){
    Solution sol;
    
    vector<int> nums={1,2,3};
    sol.sortColors(nums);
    for(int n :nums){
        cout<<n<<" ";
    }
}