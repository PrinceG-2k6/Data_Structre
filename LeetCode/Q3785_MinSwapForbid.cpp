#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums, vector<int>& forbidden) {
        int size = nums.size();
        int cand_n = 0, n_cnt = 0;
        int not_n = 0;
        int all_forb = 0;

        // First pass: count forbidden positions and find majority candidate
        for(int ii=0; ii<size; ++ii) {
            int n = nums[ii];
            if(n == forbidden[ii]) {
                all_forb++;
                if(n == cand_n) n_cnt++;
                else if(n_cnt) n_cnt--;
                else {
                    cand_n = n;
                    n_cnt = 1;
                }
            }
        }

        n_cnt = 0;

        // Second pass: verify candidate and count valid positions
        for(int ii=0; ii<size; ++ii) {
            int n = nums[ii];
            // How many forbidden positions actually contain cand_n
            if(n == cand_n && n == forbidden[ii]) n_cnt++;  
            // How many valid positions can accept cand_n
            else if(n != cand_n && cand_n != forbidden[ii]) not_n++;  
        }

        // Impossible if not enough valid places
        if(n_cnt > not_n) return -1;

        // Minimum swaps needed
        return max(n_cnt, (all_forb+1)/2);
    }
};
int main()
{
    Solution sol;
    vector<int> num={1,2,3};
    vector<int> forbidden={3,2,1};
    cout<<sol.minSwaps(num,forbidden)<<endl;
    
}    