#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int missinng=0;
        for(int num:nums){
            if(num!=missinng){
                return missinng;
            }
            missinng++;
        }
        
    }
};

int main()
{
    int t;
    cin >> t;

    Solution sol;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cout << sol.missingNumber(a) << endl;
    }
}
