#include <bits/stdc++.h>
using namespace std;

class Solution {
    int count = 0;
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==forbidden[i]){
                int j=i+1;
                while(j%n!=i){
                    if(nums[i]!=forbidden[j] && nums[j]!=forbidden[i]){
                        
                        int t = nums[i];
                        nums[i]=nums[j];
                        nums[j]=t;
                        count++;
                        break;
                    }
                    j++;
                }
            }
        }

        return count;
    }
};
int main()
{
    Solution sol;
    vector<int> num={1,2,3};
    vector<int> forbidden={3,2,1};
    cout<<sol.minSwaps(num,forbidden)<<endl;
    
}    